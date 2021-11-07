#include "gtest/gtest.h"
extern "C" {
#include "matrix.h"
#include "matrix_reverse.h"
}

// Тест прямоугольной матрицы вытянутой по горизонтали,
// делаю выботочную проверку из крайних точек
TEST(reverse_matrix, reverse_matrix_horizontal) {
    matrix_t matrix;
    init_matrix(&matrix);
    new_matrix(&matrix, 100, 10);

    set_matrix_rand_elem_1_9(&matrix);
    set_elem(&matrix, 0, 0, 228);
    set_elem(&matrix, 3, 3, 228);
    set_elem(&matrix, 99, 0, 228);
    reverse_matrix(&matrix, 0);
    EXPECT_EQ(228, matrix.array[99 * matrix.size_x + 9]);
    EXPECT_EQ(228, matrix.array[96 * matrix.size_x + 6]);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 9]);
    free_matrix(&matrix);
}
// Тест прямоугольной матрицы вытянутой по
// вертикали, делаю выботочную проверку из крайних точек
TEST(reverse_matrix, reverse_matrix_vertical) {
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix_rand_elem_1_9(&matrix);
    new_matrix(&matrix, 10, 100);

    set_elem(&matrix, 0, 0, 228);
    set_elem(&matrix, 3, 3, 228);
    set_elem(&matrix, 9, 99, 228);
    reverse_matrix(&matrix, 0);
    EXPECT_EQ(228, matrix.array[9 * matrix.size_x + 99]);
    EXPECT_EQ(228, matrix.array[6 * matrix.size_x + 96]);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 0]);
    free_matrix(&matrix);
}

TEST(reverse_matrix, reverse_matrix_vertical_line) {
    matrix_t matrix;
    init_matrix(&matrix);
    new_matrix(&matrix, 1, 100);

    set_matrix_rand_elem_1_9(&matrix);
    set_elem(&matrix, 0, 0, 228);
    set_elem(&matrix, 0, 99, 228);
    set_elem(&matrix, 0, 50, 228);
    reverse_matrix(&matrix, 0);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 0]);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 49]);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 99]);
    free_matrix(&matrix);
}

TEST(reverse_matrix, reverse_matrix_horizontal_line) {
    matrix_t matrix;
    init_matrix(&matrix);
    new_matrix(&matrix, 100, 1);

    set_matrix_rand_elem_1_9(&matrix);
    set_elem(&matrix, 0, 0, 228);
    set_elem(&matrix, 99, 0, 228);
    set_elem(&matrix, 50, 0, 228);
    reverse_matrix(&matrix, 0);
    EXPECT_EQ(228, matrix.array[0 * matrix.size_x + 0]);
    EXPECT_EQ(228, matrix.array[99 * matrix.size_x + 0]);
    EXPECT_EQ(228, matrix.array[49 * matrix.size_x + 0]);
    free_matrix(&matrix);
}

TEST(reverse_matrix, reverse_matrix_null) {
    matrix_t *matrix = NULL;
    reverse_matrix(matrix, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

