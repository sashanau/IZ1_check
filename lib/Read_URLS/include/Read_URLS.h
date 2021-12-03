#ifndef PARSER_READ_URLS_H
#define PARSER_READ_URLS_H
#include "IRead_URLS.h"

class Read_URLS : public IRead_URLS
{
public:
    Read_URLS(std::string, std::string);
    ~Read_URLS();
    std::vector<std::string>* set_urls() override;
    std::vector<std::string>* parser_urls(std::vector<std::string>*) override;
    std::string get_status();

private:
    std::string parser_page(std::string);
    std::string base_url;
    std::string get_param_url;
};

#endif //PARSER_READ_URLS_H
