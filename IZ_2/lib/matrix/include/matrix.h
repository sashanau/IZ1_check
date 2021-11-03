#ifndef IZ_2_MATRIX_H
#define IZ_2_MATRIX_H

#include "errors.h"
#include <stddef.h>

typedef struct matrix{
    int *array;
    size_t size_x;
    size_t size_y;
} matrix_t;

void init_matrix(matrix_t *matrix);
matrix_error_t set_elem(matrix_t *matrix, size_t x, size_t y, int value);

#endif //IZ_2_MATRIX_H
