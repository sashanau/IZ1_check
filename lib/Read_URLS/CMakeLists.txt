add_library(Read_URLS src/Read_URLS.cpp)

target_include_directories(Read_URLS PUBLIC include)
target_link_libraries(Read_URLS CURL::libcurl)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()