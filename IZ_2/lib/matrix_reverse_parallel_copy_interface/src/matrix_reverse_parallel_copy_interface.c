#include "matrix.h"
#include "errors.h"
#include "matrix_reverse_parallel.h"

#define unlikely(expr) __builtin_expect(!!(expr), 0)

matrix_error_t new_matrix(matrix_t *matrix, size_t size_x, size_t size_y){
    matrix_error_t error = new_matrix_mmap(matrix, size_x, size_y);
    return error;
}

matrix_error_t free_matrix(matrix_t *matrix){
    matrix_error_t error = free_matrix_mmap(matrix);
    return error;
}

matrix_error_t reverse_matrix(matrix_t *matrix, long int process_count){
    matrix_error_t error = matrix_reverse_parallel(matrix, process_count);
    return error;
}


