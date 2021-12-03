add_library(Read_Json src/Read_Json.cpp)

target_include_directories(Read_Json PUBLIC include)
target_link_libraries(Read_Json rapidjson)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()