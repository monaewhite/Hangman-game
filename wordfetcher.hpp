/*
Monae White
This file contains the declaration for string functions that uses the Merriam Webster's API for word and definiton generation
*/

#ifndef WORDFETCHER_HPP
#define WORDFETCHER_HPP
#include <iostream>
#include <vector>
#include <string>
#include <curl/curl.h>
using json = nlohmann::json;

class wordFetcher{
public:
    std::string fetchWord();
    std::string fetchDefinition(const std::string &word);

private:
    std::string makeAPICall(const std::string &url);
    static size_t writeCallBack(void *contents, size_t size, size_t nmemb, void *userp);
};

#endif //WORDFETCHER_HPP