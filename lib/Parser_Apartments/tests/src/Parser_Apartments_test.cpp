#include "gtest/gtest.h"
#include "Parser_Apartments.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <vector>

TEST(Parser_Apartments_all, Parser_Apartments_URLS_to_str){
    Parser_Apartments *apartments;
    apartments = new Parser_Apartments("https://www.domofond.ru", "arenda-kvartiry-moskva-c3584?RentalRate=Month&Page=2", 10000);
    apartments->URLS_to_str();
    apartments->str_to_json();
    apartments->json_to_db();
    //проверка на наличе полей в бд. Пока не понятно как тестить
}

TEST(Parser_Apartments_all, Parser_Apartments_URLS_to_str_null){
    Parser_Apartments *apartments;
    apartments = new Parser_Apartments("", "", 1000);
    apartments->URLS_to_str();
    apartments->str_to_json();
    apartments->json_to_db();
    EXPECT_EQ(apartments, NULL);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

