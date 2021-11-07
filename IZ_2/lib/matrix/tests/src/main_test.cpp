#include "gtest/gtest.h"

extern "C"{
#include "matrix.h"
#include "matrix_reverse.h"
}

TEST(init_matrix, init_matrix){
    matrix_t matrix;
    init_matrix(&matrix);
    EXPECT_EQ(matrix.array, (void *)NULL);
    EXPECT_EQ(matrix.size_x, 0);
    EXPECT_EQ(matrix.size_y, 0);
}

TEST(init_matrix, init_matrix_null){
    matrix_t *matrix = NULL;
    init_matrix(matrix);
}

TEST(set_elem, set_elem){
    matrix_t matrix;
    init_matrix(&matrix);
    new_matrix(&matrix, 10, 10);
    EXPECT_EQ(matrix.array[0], 0);
    matrix_error_t error = set_elem(&matrix, 0, 0, 1);
    EXPECT_EQ(error, OK);
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
    new_matrix(&matrix, 10, 10);
    matrix_error_t error = set_elem(&matrix, 100, 100, 1);
    EXPECT_EQ(error, ERROR_OUT_RANGE_SET);
    free_matrix(&matrix);
}

TEST(set_matrix_rand_elem_1_9, set_matrix_rand_elem_1_9){
    matrix_t matrix;
    init_matrix(&matrix);
    matrix_error_t error;
    error = new_matrix(&matrix, 1000, 1000);
    EXPECT_EQ(error, OK);
    error = set_matrix_rand_elem_1_9(&matrix);
    EXPECT_EQ(error, OK);
    for (size_t i = 0; i < matrix.size_x * matrix.size_y; ++i){
        EXPECT_GT(matrix.array[i], 0);
        EXPECT_LT(matrix.array[i], 10);
    }
    error = free_matrix(&matrix);
    EXPECT_EQ(error, OK);
}

TEST(set_matrix_rand_elem_1_9, set_matrix_rand_elem_1_9_null){
    matrix_error_t error;
    error = set_matrix_rand_elem_1_9(NULL);
    EXPECT_EQ(error, ERROR_NULL_PTR_REFERENCE);
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}