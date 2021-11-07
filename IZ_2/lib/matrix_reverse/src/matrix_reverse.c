#include <string.h>
#include "matrix_reverse.h"

matrix_error_t reverse_matrix(matrix_t *matrix, long int process_count) {
    process_count = 0;
    if (matrix == NULL)
        return ERROR_NULL_PTR_REFERENCE;
    matrix_t matrix_temp;
    init_matrix(&matrix_temp);
    matrix_error_t error = new_matrix(&matrix_temp, matrix->size_y, matrix->size_x);
    if (error != OK)
        return error;
    size_t j = matrix_temp.size_x - 1, k = 0;
    for (size_t i = 0; i < matrix->size_y * matrix->size_x; i++) {
        set_elem(&matrix_temp, j, (matrix_temp.size_y - 1 - k), matrix->array[i]);
        k++;
        if (k == matrix_temp.size_y)
            k = 0;
        if (((i + 1) % matrix->size_x) == 0)
            j--;
    }
    memcpy(matrix->array, matrix_temp.array, (matrix_temp.size_x * matrix_temp.size_y) * sizeof(int));
    matrix->size_x = matrix_temp.size_x;
    matrix->size_y = matrix_temp.size_y;
    error = free_matrix(&matrix_temp);
    if(error != OK)
        return error;
    return OK;
}


