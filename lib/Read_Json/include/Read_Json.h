#ifndef PARSER_READ_JSON_H
#define PARSER_READ_JSON_H
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <vector>

class Read_Json{
public:
    Read_Json(std::vector<std::string>*);
    ~Read_Json();
    rapidjson::Document *strs_to_json();

private:
    rapidjson::Document *str_to_json();
    rapidjson::Document *json_join(rapidjson::Document*, rapidjson::Document*);
    std::vector<std::string>  context;
    rapidjson::Document jsons;
};

#endif //PARSER_READ_JSON_H
