#ifndef PARSER_ILOAD_TO_DB_H
#define PARSER_ILOAD_TO_DB_H
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <vector>

class ILoad_to_db{
public:
    ILoad_to_db();
    virtual size_t json_to_db();
};

#endif //PARSER_ILOAD_TO_DB_H
