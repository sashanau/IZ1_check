#include <stdlib.h>
#include <unistd.h>
#include "matrix.h"
#include "matrix_reverse_parallel.h"


int main(int argc, char **argv) {
    //выбор кол-ва процессов
    long int COUNT_PROCESS = 6;
    if (argc != 2){
        COUNT_PROCESS = sysconf(_SC_NPROCESSORS_ONLN);
    } else {
        COUNT_PROCESS = (long int)atoi(argv[1]);
        if (COUNT_PROCESS <= 0)
            return -1;
    }
    matrix_t matrix;
    matrix_error_t error;
    error = set_matrix_mmap(&matrix, 10000, 5000);
    if (error != ERROR_OK)
        return -1;
    for (int i = 0; i < matrix.size_y; i++){
        for (int j = 0; j < matrix.size_x; j++) {
            error = set_elem(&matrix, j, i, (rand() % 10));
            if (error != ERROR_OK)
                return -1;
        }
    }
    matrix_reverse_parallel(&matrix, COUNT_PROCESS);
    error = free_matrix_mmap(&matrix);
    if (error != ERROR_OK)
        return -1;
    return 0;
}
