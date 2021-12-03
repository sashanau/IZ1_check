#ifndef PARSER_APARTMENTS_H
#define PARSER_APARTMENTS_H

#include <vector>
#include <curl/curl.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


class Parser_Apartments{
public:
    Parser_Apartments(std::string, std::string, size_t);
    ~Parser_Apartments();
    std::vector<std::string> URLS_to_str();
    rapidjson::Document str_to_json();
    size_t json_to_db();

private:
    std::vector<std::string> urls;
    std::vector<std::string>  context;
    rapidjson::Document jsons;
    size_t time_delay;
};

#endif //PARSER_APARTMENTS_H
