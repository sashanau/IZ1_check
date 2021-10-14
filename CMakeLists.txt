cmake_minimum_required(VERSION 3.16)

project(IZ_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(LIB_SOURCE_FILES find_top.c add_new_blog.c free_all_blog.c)
set(LIB_HEADERS_FILES find_top.h)

add_library(find_top STATIC ${LIB_SOURCE_FILES} ${LIB_HEADERS_FILES})
add_executable(IZ_1 main.c ${LIB_SOURCE_FILES})
target_link_libraries(IZ_1 find_top)

enable_testing()
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
add_executable(IZ_1_test main_test.cpp ${LIB_SOURCE_FILES})
target_link_libraries(IZ_1_test gtest)