cmake_minimum_required(VERSION 3.16)
project(IZ_2)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Werror -Wpedantic -g)

enable_testing()
find_package(GTest REQUIRED)

add_subdirectory(lib/utils)
add_subdirectory(lib/matrix)
add_subdirectory(lib/errors)
add_subdirectory(lib/matrix_reverse)
add_subdirectory(lib/matrix_reverse_parallel)
add_subdirectory(lib/stress_tests)

add_executable(main src/main.c)
add_executable(main_parallel src/main_parallel.c)
target_link_libraries(main matrix matrix_reverse)
target_link_libraries(main_parallel matrix matrix_reverse_parallel_shared)