#ifndef PARSER_LOAD_TO_DB_H
#define PARSER_LOAD_TO_DB_H
#include "ILoad_to_db.h"

class Load_to_db : public ILoad_to_db
{
public:
    Load_to_db(rapidjson::Document *jsons);
    ~Load_to_db();
    size_t json_to_db() override;

private:
    size_t connect_db();
    size_t json_parser();
    rapidjson::Document *jsons;
};

#endif //PARSER_LOAD_TO_DB_H
