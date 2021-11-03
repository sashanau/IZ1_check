#include <stdlib.h>
#include <stdio.h>
#include "errors.h"
#include "matrix.h"

#include "matrix_reverse.h"

int main() {
    matrix_t matrix;
    init_matrix(&matrix);
    matrix_error_t error = set_matrix(&matrix, 10000,5000);
    if (error != ERROR_OK)
        return -1;
    for (int i = 0; i < matrix.size_y; i++){
            for (int j = 0; j < matrix.size_x; j++) {
                error = set_elem(&matrix, j, i, (rand() % 10));
                if (error != ERROR_OK)
                    return -1;
            }
    }
    reverse_matrix(&matrix);
    error = free_matrix(&matrix);
    if (error != ERROR_OK)
        return -1;
    return 0;
}
