#include "gtest/gtest.h"
#include "Read_URLS.h"
#include <vector>

TEST(Read_URLS_set_urls, Read_URLS_set_urls){
    Read_URLS *readUrls;
    readUrls = new Read_URLS("https://www.domofond.ru", "arenda-kvartiry-moskva-c3584?RentalRate=Month&Page=2");
    std::vector<std::string> *urls_set = readUrls->set_urls();
    for(int i = 0; i < urls_set->size(); i++) {
        EXPECT_EQ(urls_set[i].empty(), 1);
    }
}

TEST(Read_URLS_set_urls, Read_URLS_set_urls_null){
    Read_URLS *readUrls;
    readUrls = new Read_URLS(NULL, NULL);
    EXPECT_EQ(readUrls, NULL);
}

TEST(Read_URLS_parser_urls, Read_URLS_parser_urls){
    Read_URLS *readUrls;
    readUrls = new Read_URLS("https://www.domofond.ru", "arenda-kvartiry-moskva-c3584?RentalRate=Month&Page=2");
    std::vector<std::string> *urls_set = readUrls->set_urls();
    std::vector<std::string> *context =  readUrls->parser_urls(urls_set);
    EXPECT_EQ(readUrls->get_status(), 200);
}

TEST(Read_URLS_parser_urls, Read_URLS_parser_urls_error){
    Read_URLS *readUrls;
    readUrls = new Read_URLS(" ", " ");
    std::vector<std::string> *urls_set = readUrls->set_urls();
    std::vector<std::string> *context =  readUrls->parser_urls(urls_set);
    EXPECT_EQ(readUrls->get_status(), 404);
}

TEST(Read_URLS_parser_urls, Read_URLS_parser_urls_null){
    Read_URLS *readUrls;
    std::vector<std::string> *context =  readUrls->parser_urls(NULL);
    EXPECT_EQ(context, NULL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



