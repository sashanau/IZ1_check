#ifndef ERRORS_H
#define ERRORS_H

typedef enum{
    OK = 0,
    ERROR_NULL_PTR_REFERENCE,
    ERROR_MEMORY_ALLOCATION_ERROR,
    ERROR_OUT_RANGE_SET,
    ERROR_FORK_OPEN,
    ERROR_FORK_CLOSE
} matrix_error_t;

#endif
