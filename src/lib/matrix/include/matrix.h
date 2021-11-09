#ifndef _IZ_2_MATRIX_H_
#define _IZ_2_MATRIX_H_
#include "errors.h"
#include <stddef.h>

typedef struct matrix {
    int *array;
    size_t size_x;
    size_t size_y;
} matrix_t;

void init_matrix(matrix_t *matrix);
matrix_error_t set_elem(matrix_t *matrix, size_t x, size_t y, int value);
matrix_error_t set_matrix_rand_elem_1_9(matrix_t *matrix);

#endif //_IZ_2_MATRIX_H_

