#include <stdlib.h>
#include "matrix_reverse.h"

matrix_error_t new_matrix(matrix_t *matrix, size_t size_x, size_t size_y){
    if (matrix == NULL)
        return ERROR_NULL_PTR_REFERENCE;
    if (size_x == 0 || size_y == 0)
        return ERROR_OUT_RANGE_SET;
    int *array = (int *)malloc(sizeof(int) * (size_y * size_x));;
    if (array == NULL)
        return ERROR_MEMORY_ALLOCATION_ERROR;
    for (int i = 0; i < size_y * size_x; i++){
        array[i] = 0;
    }
    matrix->array = array;
    matrix->size_x = size_x;
    matrix->size_y = size_y;
    return ERROR_OK;
}

matrix_error_t free_matrix(matrix_t *matrix){
    if (matrix == NULL)
        return ERROR_NULL_PTR_REFERENCE;
    free(matrix->array);
    matrix->array = NULL;
    return ERROR_OK;
}

matrix_error_t reverse_matrix(matrix_t *matrix, long int process_count) {
    process_count = 0;
    if (matrix == NULL)
        return ERROR_NULL_PTR_REFERENCE;
    matrix_t matrix_temp;
    init_matrix(&matrix_temp);
    matrix_error_t error = new_matrix(&matrix_temp, matrix->size_y, matrix->size_x);
    if (error != ERROR_OK)
        return ERROR_MEMORY_ALLOCATION_ERROR;
    size_t j = matrix_temp.size_x - 1, k = 0;
    for (size_t i = 0; i < matrix->size_y * matrix->size_x; i++){
        matrix_temp.array[(matrix_temp.size_y - 1 - k) * matrix_temp.size_x + j] = matrix->array[i];
        k++;
        if (k == matrix_temp.size_y)
            k = 0;
        if (((i + 1) % matrix->size_x) == 0)
            j--;
    }
    for (size_t i = 0; i < matrix->size_x * matrix->size_y; i++){
        matrix->array[i] = matrix_temp.array[i];
    }
    matrix->size_x = matrix_temp.size_x;
    matrix->size_y = matrix_temp.size_y;
    error = free_matrix(&matrix_temp);
    if(error != ERROR_OK)
        return ERROR_MEMORY_ALLOCATION_ERROR;
    return ERROR_OK;
}


