add_executable(Load_to_db_test src/Load_to_db_test.cpp)

target_link_libraries(Load_to_db_test Load_to_db GTest::Main)
add_test(NAME Load_to_db_test COMMAND Load_to_db_test)