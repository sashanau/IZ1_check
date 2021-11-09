add_executable(matrix_reverse_test src/main_test.cpp)

target_link_libraries(matrix_reverse_test matrix matrix_reverse GTest::GTest)
add_test(NAME matrix_reverse_test COMMAND matrix_reverse_test)