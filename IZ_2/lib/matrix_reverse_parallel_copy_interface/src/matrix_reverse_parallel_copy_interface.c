#include "matrix.h"
#include "errors.h"
#include "matrix_reverse_parallel.h"

matrix_error_t reverse_matrix(matrix_t *matrix, long int process_count) {
    return (matrix_reverse_parallel(matrix, process_count));
}


