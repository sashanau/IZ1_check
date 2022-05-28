#include "matrix.h"
#include "errors.h"
#include "matrix_reverse_parallel.h"

matrix_error_t reverse_matrix(matrix_t *matrix, long int process_count) {
    return (matrix_reverse_parallel(matrix, process_count));
}

matrix_error_t new_matrix(matrix_t *matrix, size_t size_x, size_t size_y) {
    return (new_matrix_mmap(matrix, size_x, size_y));
}

matrix_error_t free_matrix(matrix_t *matrix) {
    return (free_matrix_mmap(matrix));
}

