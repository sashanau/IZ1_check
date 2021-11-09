#include "gtest/gtest.h"

extern "C"{
#include "matrix.h"
#include "matrix_reverse_parallel.h"
#include "errors.h"
}

// Тест прямоугольной матрицы вытянутой по горизонтали, делаю выботочную проверку из крайних точек
TEST(matrix_reverse_parallel, matrix_reverse_parallel_horizontal) {
    matrix_t matrix;
    init_matrix(&matrix);
    new_matrix_mmap(&matrix, 100, 10);

    set_matrix_rand_elem_1_9(&matrix);
    set_elem(&matrix, 0, 0, 228);
    set_elem(&matrix, 3, 3, 228);
    set_elem(&matrix, 99, 0, 228);
    matrix_reverse_parallel(&matrix, 4);
    EXPECT_EQ(228, matrix.array[99 * matrix.size_x + 9]);
    EXPECT_EQ(228, matrix.array[96 * matrix.size_x + 6]);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 9]);
    free_matrix_mmap(&matrix);
}
// Тест прямоугольной матрицы вытянутой по вертикали, делаю выботочную проверку из крайних точек
TEST(matrix_reverse_parallel, matrix_reverse_parallel_vertical) {
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix_rand_elem_1_9(&matrix);
    new_matrix_mmap(&matrix, 10, 100);

    set_elem(&matrix, 0, 0, 228);
    set_elem(&matrix, 3, 3, 228);
    set_elem(&matrix, 9, 99, 228);
    matrix_reverse_parallel(&matrix, 4);
    EXPECT_EQ(228, matrix.array[9 * matrix.size_x + 99]);
    EXPECT_EQ(228, matrix.array[6 * matrix.size_x + 96]);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 0]);
    free_matrix_mmap(&matrix);
}

TEST(matrix_reverse_parallel, matrix_reverse_parallel_vertical_line) {
    matrix_t matrix;
    init_matrix(&matrix);
    new_matrix_mmap(&matrix, 1, 100);

    set_matrix_rand_elem_1_9(&matrix);
    set_elem(&matrix, 0, 0, 228);
    set_elem(&matrix, 0, 99, 228);
    set_elem(&matrix, 0, 50, 228);
    matrix_reverse_parallel(&matrix, 4);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 0]);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 49]);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 99]);
    free_matrix_mmap(&matrix);
}

TEST(matrix_reverse_parallel, matrix_reverse_parallel_horizontal_line) {
    matrix_t matrix;
    init_matrix(&matrix);
    new_matrix_mmap(&matrix, 100, 1);

    set_matrix_rand_elem_1_9(&matrix);
    set_elem(&matrix, 0, 0, 228);
    set_elem(&matrix, 99, 0, 228);
    set_elem(&matrix, 50, 0, 228);
    matrix_reverse_parallel(&matrix, 4);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 0]);
    EXPECT_EQ(228, matrix.array[99 * matrix.size_x + 0]);
    EXPECT_EQ(228, matrix.array[49 * matrix.size_x + 0]);
    free_matrix_mmap(&matrix);
}
// Тест если процесссов больше чем размер матрицы
TEST(matrix_reverse_parallel, matrix_reverse_parallel_process_count) {
    matrix_t matrix;
    init_matrix(&matrix);
    new_matrix_mmap(&matrix, 2, 2);
    set_elem(&matrix, 0, 0, 228);
    matrix_error_t  error = matrix_reverse_parallel(&matrix, 8);
    EXPECT_EQ(error, OK);
    EXPECT_EQ(228, matrix.array[1 * matrix.size_x + 1]);
    error = free_matrix_mmap(&matrix);
    EXPECT_EQ(error, OK);
}

TEST(matrix_reverse_parallel, matrix_reverse_parallel_null) {
    matrix_error_t  error = matrix_reverse_parallel(NULL, 4);
    EXPECT_EQ(error, ERROR_NULL_PTR_REFERENCE);
}

TEST(new_matrix_mmap, new_matrix_mmap) {
    matrix_error_t error;
    matrix_t matrix;
    init_matrix(&matrix);
    error = new_matrix_mmap(&matrix, 10, 10);
    EXPECT_EQ(error, OK);
    for (size_t i = 0; i < 10 * 10; i++) {
        EXPECT_EQ(matrix.array[i], 0);
    }
    error = free_matrix_mmap(&matrix);
    EXPECT_EQ(error, OK);
}

TEST(new_matrix_mmap, new_matrix_mmap_null) {
    matrix_error_t error;
    error = new_matrix_mmap(NULL, 10, 10);
    EXPECT_EQ(error, ERROR_NULL_PTR_REFERENCE);
}

TEST(new_matrix_mmap, new_matrix_mmap_out_range) {
    matrix_error_t error;
    matrix_t matrix;
    init_matrix(&matrix);
    error = new_matrix_mmap(&matrix, 0, 10);
    EXPECT_EQ(error, ERROR_OUT_RANGE_SET);
}

TEST(free_matrix_mmap, free_matrix_mmap) {
    matrix_t matrix;
    init_matrix(&matrix);
    matrix_error_t error = new_matrix_mmap(&matrix, 10000, 5000);
    EXPECT_EQ(error, OK);
    error = free_matrix_mmap(&matrix);
    EXPECT_EQ(error, OK);
}

TEST(free_matrix_mmap, free_matrix_mmap_null) {
    matrix_error_t error = free_matrix_mmap(NULL);
    EXPECT_EQ(error, ERROR_NULL_PTR_REFERENCE);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}