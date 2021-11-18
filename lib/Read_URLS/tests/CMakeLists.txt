add_executable(Read_URLS_test src/Read_URLS_test.cpp)

target_link_libraries(Read_URLS_test Read_URLS GTest::Main)
add_test(NAME Read_URLS_test COMMAND Read_URLS_test)