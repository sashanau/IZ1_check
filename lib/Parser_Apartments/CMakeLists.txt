add_library(Parser_Apartments src/Parser_Apartments.cpp)

target_include_directories(Parser_Apartments PUBLIC include)
target_link_libraries(Parser_Apartments CURL::libcurl rapidjson Load_to_db Read_Json Read_URLS)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()