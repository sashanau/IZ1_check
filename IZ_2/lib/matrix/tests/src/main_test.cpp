#include "gtest/gtest.h"

extern "C"{
#include "matrix.h"
#include "matrix_reverse.h"
}

TEST(init_matrix, init_matrix) {
    matrix_t matrix;
    init_matrix(&matrix);
    EXPECT_EQ(matrix.array, (void *)NULL);
    EXPECT_EQ(matrix.size_x, 0);
    EXPECT_EQ(matrix.size_y, 0);
}

TEST(init_matrix, init_matrix_null) {
    matrix_t *matrix = NULL;
    init_matrix(matrix);
}

TEST(set_elem, set_elem){
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix(&matrix, 10, 10);
    EXPECT_EQ(matrix.array[0], 0);
    matrix_error_t error = set_elem(&matrix, 0, 0, 1);
    EXPECT_EQ(error, ERROR_OK);
    EXPECT_EQ(matrix.array[0], 1);
    free_matrix(&matrix);
}

TEST(set_elem, set_elem_null){
    matrix_error_t error = set_elem(NULL, 1, 1, 1);
    EXPECT_EQ(error, ERROR_NULL_PTR_REFERENCE);
}

TEST(set_elem, set_elem_out_range){
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix(&matrix, 10, 10);
    matrix_error_t error = set_elem(&matrix, 100, 100, 1);
    EXPECT_EQ(error, ERROR_OUT_RANGE_SET);
    free_matrix(&matrix);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}