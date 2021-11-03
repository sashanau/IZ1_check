#include "gtest/gtest.h"

extern "C"{
#include "matrix.h"
#include "matrix_reverse.h"
}

// Тест прямоугольной матрицы вытянутой по горизонтали, делаю выботочную проверку из крайних точек
TEST(reverse_matrix, reverse_matrix_horizontal){
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix(&matrix, 100,10);
    int value = 0, temp_00, temp_33, temp_90, temp_999;

    for (size_t i = 0; i < matrix.size_y; i++) {
        for (size_t j = 0; j < matrix.size_x; j++) {
            value = rand() % 10;
            set_elem(&matrix, j, i, value);
            if (i == 0 && j == 0)
                temp_00 = value;
            else if (i == 3 && j == 3)
                temp_33 = value;
            else if (i == 9 && j == 0)
                temp_90 = value;
            else if(i == 9 && j == 99)
                temp_999 = value;
        }
    }
    reverse_matrix(&matrix);
    EXPECT_EQ(temp_00, matrix.array[9 * matrix.size_x + 9]);
    EXPECT_EQ(temp_33, matrix.array[6 * matrix.size_x + 6]);
    EXPECT_EQ(temp_90, matrix.array[9 * matrix.size_x + 0]);
    EXPECT_EQ(temp_999, matrix.array[9 * matrix.size_x + 99]);
    free_matrix(&matrix);
}
// Тест прямоугольной матрицы вытянутой по вертикали, делаю выботочную проверку из крайних точек
TEST(reverse_matrix, reverse_matrix_vertical){
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix(&matrix, 10,100);
    int value = 0, temp_00, temp_909, temp_900, temp_933;

    for (size_t i = 0; i < matrix.size_y; i++) {
        for (size_t j = 0; j < matrix.size_x; j++) {
            value = rand() % 10;
            set_elem(&matrix, j, i, value);
            if (i == 0 && j == 0)
                temp_00 = value;
            else if (i == 90 && j == 9)
                temp_909 = value;
            else if (i == 90 && j == 0)
                temp_900 = value;
            else if (i == 93 && j == 3)
                temp_933 = value;
        }
    }
    reverse_matrix(&matrix);
    EXPECT_EQ(temp_00, matrix.array[0 * matrix.size_x + 0]);
    EXPECT_EQ(temp_909, matrix.array[90 * matrix.size_x + 9]);
    EXPECT_EQ(temp_900, matrix.array[99 * matrix.size_x + 9]);
    EXPECT_EQ(temp_933, matrix.array[96 * matrix.size_x + 6]);
    free_matrix(&matrix);
}

TEST(reverse_matrix, reverse_matrix_vertical_line){
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix(&matrix, 1,100);
    int value = 0, temp_00, temp_90;

    for (size_t i = 0; i < matrix.size_y; i++) {
        for (size_t j = 0; j < matrix.size_x; j++) {
            value = rand() % 10;
            set_elem(&matrix, j, i, value);
            if (i == 0 && j == 0)
                temp_00 = value;
            else if (i == 9 && j == 0)
                temp_90 = value;
        }
    }
    reverse_matrix(&matrix);
    EXPECT_EQ(temp_00, matrix.array[0 * matrix.size_x + 0]);
    EXPECT_EQ(temp_90, matrix.array[9 * matrix.size_x + 0]);
    free_matrix(&matrix);
}

TEST(reverse_matrix, reverse_matrix_horizontal_line){
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix(&matrix, 100,1);
    int value = 0, temp_00, temp_09;

    for (size_t i = 0; i < matrix.size_y; i++) {
        for (size_t j = 0; j < matrix.size_x; j++) {
            value = rand() % 10;
            set_elem(&matrix, j, i, value);
            if (i == 0 && j == 0)
                temp_00 = value;
            else if (i == 0 && j == 9)
                temp_09 = value;
        }
    }
    reverse_matrix(&matrix);
    EXPECT_EQ(temp_00, matrix.array[0 * matrix.size_x + 0]);
    EXPECT_EQ(temp_09, matrix.array[0 * matrix.size_x + 9]);
    free_matrix(&matrix);
}

TEST(reverse_matrix, reverse_matrix_null){
    matrix_t *matrix = NULL;
    reverse_matrix(matrix);
}

TEST(set_matrix, set_matrix){
    matrix_t matrix;
    init_matrix(&matrix);
    matrix_error_t error = set_matrix(&matrix, 10000, 5000);
    EXPECT_EQ(error, ERROR_OK);
    for(int i = 0; i < 5000; i++){
        for(int j = 0; j < 10000; j++){
            EXPECT_EQ(matrix.array[i * matrix.size_x + j], 0);
        }
    }
    free_matrix(&matrix);
}

TEST(set_matrix, set_matrix_less_than_0){
    matrix_t matrix;
    init_matrix(&matrix);
    matrix_error_t error = set_matrix(&matrix, 0, 5000);
    EXPECT_EQ(error, ERROR_OUT_RANGE_SET);
}

TEST(set_matrix, set_matrix_null){
    matrix_error_t error = set_matrix(NULL, 10000, 5000);
    EXPECT_EQ(error, ERROR_NULL_PTR_REFERENCE);
}

TEST(free_matrix, free_matrix){
    matrix_t matrix;
    init_matrix(&matrix);
    matrix_error_t error = set_matrix(&matrix, 10000, 5000);
    EXPECT_EQ(error, ERROR_OK);
    error = free_matrix(&matrix);
    EXPECT_EQ(error, ERROR_OK);
}

TEST(free_matrix, free_matrix_null){
    matrix_error_t error = free_matrix(NULL);
    EXPECT_EQ(error, ERROR_NULL_PTR_REFERENCE);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}