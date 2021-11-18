#include "gtest/gtest.h"
#include "Read_Json.h"
#include "rapidjson/document.h"
#include <vector>

TEST(Read_Json_strs_to_json, Read_Json_strs_to_json){
    std::string json = "{\"hello\": \"world\","
                       " \"t\": true,"
                       " \"f\": false,"
                       " \"n\": \"null\","
                       " \"i\": \"123\","
                       " \"pi\": 3.1416,"
                       " \"a\": [1, 2, 3, 4]}";
    std::vector<std::string> str_to_json;
    str_to_json.push_back("\"hello\": \"world\"");
    str_to_json.push_back("\"t\": true");
    Read_Json readJson(&str_to_json);
    rapidjson::Document *document = readJson.strs_to_json();
    EXPECT_EQ(document->HasMember("hello"), 1);
    EXPECT_EQ(document->HasMember("t"), 1);
    EXPECT_EQ((*document)["t"].IsBool(), 1);
    EXPECT_EQ((*document)["hello"].IsString(), 1);
}

TEST(Read_Json_strs_to_json, Read_Json_strs_to_json_null){
    Read_Json readJson(NULL);
    rapidjson::Document *document = readJson.strs_to_json();
    EXPECT_EQ(document, NULL);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



