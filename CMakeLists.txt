cmake_minimum_required(VERSION 3.20)
project(Parser)

set(CMAKE_CXX_STANDARD 14)

if(WITH_TESTS OR WITH_SANITIZERS OR WITH_COVERAGE)
    enable_testing()
    find_package(GTest REQUIRED)
    set(BUILD_TESTS ON)
endif()

enable_testing()
find_package(GTest REQUIRED)
set(BUILD_TESTS ON)

find_package(CURL)
find_package(RapidJSON)

add_subdirectory(lib/Load_to_db)
add_subdirectory(lib/Read_Json)
add_subdirectory(lib/Read_URLS)
add_subdirectory(lib/Parser_Apartments)

add_executable(Parser src/main.cpp)
target_link_libraries(Parser CURL::libcurl rapidjson Parser_Apartments)
