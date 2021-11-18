#include "gtest/gtest.h"
#include "Load_to_db.h"
#include "rapidjson/document.h"
#include <vector>

TEST(Load_to_db_json_to_db, Load_to_db_json_to_db){
    std::string json = "{\"hello\": \"world\","
                       " \"t\": true,"
                       " \"f\": false,"
                       " \"n\": \"null\","
                       " \"i\": \"123\","
                       " \"pi\": 3.1416,"
                       " \"a\": [1, 2, 3, 4]}";
    rapidjson::Document *document;
    document->Parse(json.c_str());
    Load_to_db *loadToDb;
    loadToDb = new Load_to_db(document);
    size_t error = loadToDb->json_to_db();
    // Здесь обращение к бд и проверка что поля есть, сейчас это написать невозможно.
    EXPECT_EQ(error, 0);
}


TEST(Load_to_db_json_to_db, Load_to_db_json_to_db_null){
    Load_to_db *loadToDb;
    loadToDb = new Load_to_db(NULL);
    size_t error = loadToDb->json_to_db();
    EXPECT_EQ(error, 1);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

