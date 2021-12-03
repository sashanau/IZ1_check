#ifndef PARSER_IREAD_URLS_H
#define PARSER_IREAD_URLS_H

class IRead_URLS{
public:
    IRead_URLS();
    virtual std::vector<std::string>* set_urls();
    virtual std::vector<std::string>* parser_urls(std::vector<std::string>*);
};

#endif //PARSER_IREAD_URLS_H
