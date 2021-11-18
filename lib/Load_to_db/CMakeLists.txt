add_library(Load_to_db src/Load_to_db.cpp)

target_include_directories(Load_to_db PUBLIC include)
target_link_libraries(Load_to_db rapidjson)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()