add_library(matrix_reverse_parallel_shared SHARED src/matrix_reverse_parallel.c)
target_include_directories(matrix_reverse_parallel_shared PUBLIC include)

target_link_libraries(matrix_reverse_parallel_shared PUBLIC errors)
target_link_libraries(matrix_reverse_parallel_shared PUBLIC matrix)
target_link_libraries(matrix_reverse_parallel_shared PUBLIC utils)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()