#include <stdlib.h>
#include <unistd.h>
#include "matrix.h"
#include "matrix_reverse.h"

int main(int argc, char **argv) {
    long int COUNT_PROCESS = 0;
    if (argc != 2) {
        COUNT_PROCESS = sysconf(_SC_NPROCESSORS_ONLN);
    } else {
        COUNT_PROCESS = (long int)atoi(argv[1]);
        if (COUNT_PROCESS <= 0)
            return -1;
    }
    matrix_t matrix;
    init_matrix(&matrix);
    matrix_error_t error = new_matrix(&matrix, 10000, 5000);
    if (error != OK)
        return -1;
    error = set_matrix_rand_elem_1_9(&matrix);
    if (error != OK)
        return -1;
    error = reverse_matrix(&matrix, COUNT_PROCESS);
    if (error != OK)
        return -1;
    error = free_matrix(&matrix);
    if (error != OK)
        return -1;
    return 0;
}
