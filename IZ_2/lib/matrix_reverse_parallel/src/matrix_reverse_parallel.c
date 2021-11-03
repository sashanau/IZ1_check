#include "matrix_reverse_parallel.h"
#include "utils.h"
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#define unlikely(expr) __builtin_expect(!!(expr), 0)

matrix_error_t set_matrix_mmap(matrix_t *matrix, size_t size_x, size_t size_y){
    if (unlikely(matrix == NULL))
        return ERROR_NULL_PTR_REFERENCE;
    if (unlikely(size_x == 0 || size_y == 0))
        return ERROR_OUT_RANGE_SET;
    matrix->array = (int *)open_mmap(sizeof(int) * size_y * size_x);
    if (unlikely(matrix->array == MAP_FAILED))
        return ERROR_MEMORY_ALLOCATION_ERROR;
    for(int i = 0; i < size_x * size_y; i++){
        matrix->array[i] = 0;
    }
    matrix->size_y = size_y;
    matrix->size_x = size_x;
    return ERROR_OK;
}

void *open_mmap(size_t len){
    return mmap(NULL,
                len,
                PROT_READ | PROT_WRITE,
                MAP_ANONYMOUS | MAP_SHARED,
                -1,
                0);
}

matrix_error_t free_matrix_mmap(matrix_t *matrix){
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
    return ERROR_OK;
}

void matrix_reverse_parallel(matrix_t *matrix, long int process_count){
    if (unlikely(matrix == NULL || process_count == 0))
        return;
    int *ptr_start = NULL;
    size_t temp_size_x = 0;
    size_t size_swap = 0;                    //Количесво swap-ов всего
    if (matrix->size_x == 1 || matrix->size_y == 1)
        return;
    if (matrix->size_y > matrix->size_x){
        size_swap = ((matrix->size_x * matrix->size_x) - matrix->size_x) / 2;
        ptr_start = &matrix->array[(matrix->size_y - matrix->size_x) * matrix->size_x];
        temp_size_x = matrix->size_x;
    } else if (matrix->size_y == matrix->size_x){
        size_swap = ((matrix->size_x * matrix->size_x) - matrix->size_x) / 2;
        ptr_start = matrix->array;
        temp_size_x = matrix->size_x;
    } else{
        size_swap = ((matrix->size_y * matrix->size_y) - matrix->size_y) / 2;
        ptr_start = matrix->array;
        temp_size_x = matrix->size_y;
    }

    if(unlikely(size_swap < process_count))
        process_count = (long)size_swap;

    size_t count_next_fork = size_swap / process_count;
    size_t j = 1, start_fork, end_fork;
    int pid;

    // Создаем задданное кол-во процессов разбвая на участки начиная с конца массива поскольку этот цикл самый долгий.
    for (long int i = process_count - 1; i >= 0; --i) {
        pid = fork();
        if (pid == 0){
            start_fork = count_next_fork * i;
            if (i == process_count - 1)
                end_fork = size_swap;
            else
                end_fork = count_next_fork * (i + 1);
            break;
        }
        if (pid > 0)
            continue;
        else {
            printf("ERROR: status fork\n");
            return;
        }
    }

    if (pid == 0) {
        size_t real_count = 0, temp_count_x = 0;
        for (size_t i = 0; i < end_fork; ++i) {
            temp_count_x = real_count % matrix->size_x;
            if (i >= start_fork) {
                swap(&ptr_start[real_count],
                     &ptr_start[((temp_size_x - temp_count_x - 1)
                     * matrix->size_x) + temp_size_x - j]);
            }
            real_count++;
            if (unlikely(temp_size_x * j + ((matrix->size_x - temp_size_x) * (j - 1)) == real_count + j)) {
                real_count = real_count + j + (matrix->size_x - temp_size_x);
                j++;
            }
        }
        exit(0);
    } else {
        int status;
        for(int i = 0; i < process_count; i++){
            wait(&status);
            if (unlikely(WIFEXITED(status) == 0)){
                printf("ERROR: status fork\n");
                return;
            }
        }
        return;
    }
}


