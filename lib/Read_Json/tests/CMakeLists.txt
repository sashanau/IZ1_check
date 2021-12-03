add_executable(Read_Json_test src/Read_Json_test.cpp)

target_link_libraries(Read_Json_test Read_Json GTest::Main)
add_test(NAME Read_Json_test COMMAND Read_Json_test)