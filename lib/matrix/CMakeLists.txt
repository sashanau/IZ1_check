add_library(matrix src/matrix.c)

target_include_directories(matrix PUBLIC include)

target_link_libraries(matrix PUBLIC errors)
target_link_libraries(matrix PUBLIC matrix_reverse)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()