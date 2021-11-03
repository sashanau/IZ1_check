#include "matrix.h"
#include "utils.h"
#include <stdlib.h>

void reverse_matrix(matrix_t *matrix) {
    if (matrix == NULL)
        return;

    int *ptr_start = NULL;
    size_t temp_size_x = 0;
    if (matrix->size_x == 1 || matrix->size_y == 1)
        return;
    if (matrix->size_y > matrix->size_x){
        ptr_start = &matrix->array[(matrix->size_y - matrix->size_x) * matrix->size_x];
        temp_size_x = matrix->size_x;
    } else if (matrix->size_y == matrix->size_x){
        ptr_start = matrix->array;
        temp_size_x = matrix->size_x;
    } else{
        ptr_start = matrix->array;
        temp_size_x = matrix->size_y;
    }

    for (size_t i = 0; i < temp_size_x - 1; i++){
        for(size_t j = 0; j < temp_size_x - i - 1; j++){
            swap(&ptr_start[(i * matrix->size_x) + j],
                 &ptr_start[((temp_size_x - j - 1) *
                 matrix->size_x) + temp_size_x - i - 1]);
        }
    }
}

matrix_error_t set_matrix(matrix_t *matrix, size_t size_x, size_t size_y){
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
