#include "gtest/gtest.h"

extern "C" {
#include "matrix.h"
#include "matrix_reverse.h"
#include "matrix_reverse_parallel.h"
#include "errors.h"
}

TEST(stress_tests, stress_tests) {
    for (int k = 0; k < 4; k++) {
        matrix_t matrix1, matrix2;
        init_matrix(&matrix1);
        init_matrix(&matrix2);
        size_t size_x = rand() % 10000;
        size_t size_y = rand() % 10000;
        matrix_error_t error;
        error = new_matrix_mmap(&matrix1, size_x, size_y);
        EXPECT_EQ(error, OK);
        error = new_matrix(&matrix2, size_x, size_y);
        EXPECT_EQ(error, OK);
        int val = 0;
        for (size_t i = 0; i < size_y; ++i) {
            for (size_t j = 0; j < size_x; j++) {
                val = int(rand() % 10000);
                error = set_elem(&matrix1, j, i, val);
                EXPECT_EQ(error, OK);
                error = set_elem(&matrix2, j, i, val);
                EXPECT_EQ(error, OK);
            }
        }

        matrix_reverse_parallel(&matrix1, (long int)(rand() % 8));
        reverse_matrix(&matrix2, 0);

        for (size_t i = 0; i < size_x * size_y; i++)
            EXPECT_EQ(matrix1.array[i], matrix2.array[i]);

        error = free_matrix_mmap(&matrix1);
        EXPECT_EQ(error, OK);
        error = free_matrix(&matrix2);
        EXPECT_EQ(error, OK);
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

