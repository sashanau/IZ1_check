add_executable(matrix_test src/main_test.cpp)

target_link_libraries(matrix_test matrix GTest::GTest)
add_test(NAME matrix_test COMMAND matrix_test)