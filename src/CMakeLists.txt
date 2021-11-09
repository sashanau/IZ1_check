cmake_minimum_required(VERSION 3.16)
project(IZ_2)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Werror -Wpedantic)

option(WITH_COVERAGE "Add coverage estimation" OFF)
if(WITH_COVERAGE)
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

option(WITH_SANITIZERS "Add address sanitizer" OFF)
if(WITH_SANITIZERS)
    add_compile_options(-fno-omit-frame-pointer -fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

option(WITH_TESTS "Build tests" OFF)
if(WITH_TESTS OR WITH_SANITIZERS OR WITH_COVERAGE)
    enable_testing()
    find_package(GTest REQUIRED)
    set(BUILD_TESTS ON)
endif()

add_subdirectory(lib/utils)
add_subdirectory(lib/matrix)
add_subdirectory(lib/errors)
add_subdirectory(lib/matrix_reverse)
add_subdirectory(lib/matrix_reverse_parallel_copy_interface)
add_subdirectory(lib/matrix_reverse_parallel)
add_subdirectory(lib/stress_tests)

set(CHOOSE_MODE 1) #0 - linear else - parallel
if(CHOOSE_MODE STREQUAL 0)
    add_executable(main src/main.c)
    target_link_libraries(main matrix matrix_reverse)
else()
    add_executable(main src/main.c)
    target_link_libraries(main matrix matrix_reverse_parallel_copy_interface)
endif()
