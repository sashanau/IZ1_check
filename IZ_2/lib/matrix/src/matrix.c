#include "matrix.h"
#include <stdlib.h>

void init_matrix(matrix_t *matrix){
    if (matrix == NULL)
        return;

    matrix->array = NULL;
    matrix->size_x = 0;
    matrix->size_y = 0;
}

matrix_error_t set_elem(matrix_t *matrix, size_t x, size_t y, int value){
    if (matrix == NULL)
        return ERROR_NULL_PTR_REFERENCE;
    if (x > matrix->size_x || y > matrix->size_y)
        return ERROR_OUT_RANGE_SET;
    matrix->array[(y * matrix->size_x) + x] = value;
    return OK;
}

matrix_error_t set_matrix_rand_elem_1_9(matrix_t *matrix){
    if (matrix == NULL)
        return ERROR_NULL_PTR_REFERENCE;
    for (size_t i = 0; i < matrix->size_x * matrix->size_y; i++){
        matrix->array[i] = (rand() % 9) + 1;
    }
    return OK;
}
