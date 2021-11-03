#include "gtest/gtest.h"

extern "C"{
#include "matrix.h"
#include "matrix_reverse_parallel.h"
#include "errors.h"
}

// Тест прямоугольной матрицы вытянутой по горизонтали, делаю выботочную проверку из крайних точек
TEST(matrix_reverse_parallel, reverse_matrix_horizontal){
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix_mmap(&matrix, 100,10);
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
    matrix_reverse_parallel(&matrix, 4);
    EXPECT_EQ(temp_00, matrix.array[9 * matrix.size_x + 9]);
    EXPECT_EQ(temp_33, matrix.array[6 * matrix.size_x + 6]);
    EXPECT_EQ(temp_90, matrix.array[9 * matrix.size_x + 0]);
    EXPECT_EQ(temp_999, matrix.array[9 * matrix.size_x + 99]);
    matrix_error_t error = free_matrix_mmap(&matrix);
    EXPECT_EQ(error, ERROR_OK);
}
// Тест прямоугольной матрицы вытянутой по вертикали, делаю выботочную проверку из крайних точек
TEST(matrix_reverse_parallel, reverse_matrix_vertical){
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix_mmap(&matrix, 10,100);
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
    matrix_reverse_parallel(&matrix, 4);
    EXPECT_EQ(temp_00, matrix.array[0 * matrix.size_x + 0]);
    EXPECT_EQ(temp_909, matrix.array[90 * matrix.size_x + 9]);
    EXPECT_EQ(temp_900, matrix.array[99 * matrix.size_x + 9]);
    EXPECT_EQ(temp_933, matrix.array[96 * matrix.size_x + 6]);
    matrix_error_t error = free_matrix_mmap(&matrix);
    EXPECT_EQ(error, ERROR_OK);
}

TEST(matrix_reverse_parallel, reverse_matrix_vertical_line){
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix_mmap(&matrix, 1,100);
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
    matrix_reverse_parallel(&matrix, 4);
    EXPECT_EQ(temp_00, matrix.array[0 * matrix.size_x + 0]);
    EXPECT_EQ(temp_90, matrix.array[9 * matrix.size_x + 0]);
    matrix_error_t error = free_matrix_mmap(&matrix);
    EXPECT_EQ(error, ERROR_OK);
}

TEST(matrix_reverse_parallel, reverse_matrix_horizontal_line){
    matrix_t matrix;
    init_matrix(&matrix);
    set_matrix_mmap(&matrix, 100,1);
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
    matrix_reverse_parallel(&matrix, 4);
    EXPECT_EQ(temp_00, matrix.array[0 * matrix.size_x + 0]);
    EXPECT_EQ(temp_09, matrix.array[0 * matrix.size_x + 9]);
    matrix_error_t error = free_matrix_mmap(&matrix);
    EXPECT_EQ(error, ERROR_OK);
}

TEST(matrix_reverse_parallel, reverse_matrix_null){
    matrix_t *matrix = NULL;
    matrix_reverse_parallel(matrix, 4);
}

TEST(set_matrix_mmap, set_matrix_mmap){
    matrix_error_t error;
    matrix_t matrix;
    init_matrix(&matrix);
    error = set_matrix_mmap(&matrix, 10, 10);
    EXPECT_EQ(error, ERROR_OK);
    for (size_t i = 0; i < 10 * 10; i++){
        EXPECT_EQ(matrix.array[i], 0);
    }
    error = free_matrix_mmap(&matrix);
    EXPECT_EQ(error, ERROR_OK);
}

TEST(set_matrix_mmap, set_matrix_mmap_null){
    matrix_error_t error;
    error = set_matrix_mmap(NULL, 10, 10);
    EXPECT_EQ(error, ERROR_NULL_PTR_REFERENCE);
}

TEST(set_matrix_mmap, set_matrix_mmap_out_range){
    matrix_error_t error;
    matrix_t matrix;
    init_matrix(&matrix);
    error = set_matrix_mmap(&matrix, 0, 10);
    EXPECT_EQ(error, ERROR_OUT_RANGE_SET);
}

TEST(free_matrix, free_matrix){
    matrix_t matrix;
    init_matrix(&matrix);
    matrix_error_t error = set_matrix_mmap(&matrix, 10000, 5000);
    EXPECT_EQ(error, ERROR_OK);
    error = free_matrix_mmap(&matrix);
    EXPECT_EQ(error, ERROR_OK);
}

TEST(free_matrix, free_matrix_null){
    matrix_error_t error = free_matrix_mmap(NULL);
    EXPECT_EQ(error, ERROR_NULL_PTR_REFERENCE);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}