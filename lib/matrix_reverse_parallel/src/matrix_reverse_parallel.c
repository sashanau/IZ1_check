#include "matrix_reverse_parallel.h"
#include "matrix.h"
#include "errors.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/mman.h>
#define unlikely(expr) __builtin_expect(!!(expr), 0)

matrix_error_t new_matrix_mmap(matrix_t *matrix, size_t size_x, size_t size_y) {
    if (unlikely(matrix == NULL))
        return ERROR_NULL_PTR_REFERENCE;
    if (unlikely(size_x == 0 || size_y == 0))
        return ERROR_OUT_RANGE_SET;
    matrix->array = (int *)mmap(NULL, (sizeof(int) * size_y * size_x),
                                PROT_READ | PROT_WRITE,
                                MAP_ANONYMOUS | MAP_SHARED,
                                -1, 0);
    if (unlikely(matrix->array == MAP_FAILED))
        return ERROR_MEMORY_ALLOCATION_ERROR;
    for(int i = 0; i < size_x * size_y; i++) {
        matrix->array[i] = 0;
    }
    matrix->size_y = size_y;
    matrix->size_x = size_x;
    return OK;
}

matrix_error_t free_matrix_mmap(matrix_t *matrix) {
    if (unlikely(matrix == NULL))
        return ERROR_NULL_PTR_REFERENCE;
    int error;
    error = munmap(matrix->array, ((matrix->size_x * matrix->size_y) * sizeof(int)));
    if (error != 0)
        return ERROR_NULL_PTR_REFERENCE;
    matrix->array = NULL;
    matrix->size_y = 0;
    matrix->size_x = 0;
    matrix = NULL;
    return OK;
}

void set_elems_matrix_temp(matrix_t *matrix, matrix_t *matrix_temp, size_t start_fork, size_t end_fork) {
    size_t j = matrix_temp->size_x - 1, k = 0;
    for (size_t i = 0; i < end_fork; i++) {
        if (i >= start_fork)
            set_elem(matrix_temp, j, (matrix_temp->size_y - 1 - k), matrix->array[i]);
        k++;
        if (k == matrix_temp->size_y)
            k = 0;
        if (((i + 1) % matrix->size_x) == 0)
            j--;
    }
}

matrix_error_t matrix_reverse_parallel(matrix_t *matrix, long int process_count) {
    if (matrix == NULL)
        return ERROR_NULL_PTR_REFERENCE;
    matrix_t matrix_temp;
    init_matrix(&matrix_temp);
    matrix_error_t error = new_matrix_mmap(&matrix_temp, matrix->size_y, matrix->size_x);
    if (error != OK)
        return error;
    if(unlikely(matrix->size_x * matrix->size_y < process_count))
        process_count = (long)(matrix->size_x * matrix->size_y);
    size_t step_fork_size = (matrix->size_x * matrix->size_y) / (size_t)process_count;
    size_t start_fork = 0, end_fork = 0;

    // Создаем задданное кол-во процессов разбвая на участки начиная с конца массива поскольку этот цикл самый долгий из-за особенностей реализации.
    int pid;
    int status;
    for (long int i = process_count - 1; i >= 0; --i) {
        pid = fork();
        if (pid == 0){
            start_fork = step_fork_size * i;
            if (i == process_count - 1)
                end_fork = matrix_temp.size_x * matrix_temp.size_y;
            else
                end_fork = step_fork_size * (i + 1);
            break;
        }
        else if (pid > 0)
            continue;
        else {
            // Ждём окончания всех запущенных процессов
            for(long int b = process_count - i; b < process_count; b++) {
                wait(&status);
                if (unlikely(WIFEXITED(status) == 0)) {
                    return ERROR_FORK_CLOSE;
                }
            }
            error = free_matrix_mmap(&matrix_temp);
            if (error != OK)
                return error;
            return ERROR_FORK_OPEN;
        }
    }
    if (pid == 0) {
        set_elems_matrix_temp(matrix, &matrix_temp, start_fork, end_fork);
        exit(0);
    } else {
        // Ждём окончания всех процессов
        for(int i = 0; i < process_count; i++) {
            wait(&status);
            if (unlikely(WIFEXITED(status) == 0)) {
                return ERROR_FORK_CLOSE;
            }
        }
        memcpy(matrix->array, matrix_temp.array, (matrix_temp.size_x * matrix_temp.size_y) * sizeof(int));
        matrix->size_x = matrix_temp.size_x;
        matrix->size_y = matrix_temp.size_y;
        error = free_matrix_mmap(&matrix_temp);
        if (error != OK)
            return error;
        return OK;
    }
}
