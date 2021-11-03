#ifndef IZ_2_MATRIX_REVERSE_PARALLEL_H
#define IZ_2_MATRIX_REVERSE_PARALLEL_H
#include "matrix.h"

matrix_error_t set_matrix_mmap(matrix_t *matrix, size_t size_x, size_t size_y);
void matrix_reverse_parallel(matrix_t *matrix, long int process_count);
matrix_error_t free_matrix_mmap(matrix_t *matrix);
void *open_mmap(size_t len);

#endif //IZ_2_MATRIX_REVERSE_PARALLEL_H
