add_library(matrix_reverse src/matrix_reverse.c)

target_include_directories(matrix_reverse PUBLIC include)

target_link_libraries(matrix_reverse PUBLIC errors)
target_link_libraries(matrix_reverse PUBLIC matrix)
target_link_libraries(matrix_reverse PUBLIC utils)

add_subdirectory(tests)