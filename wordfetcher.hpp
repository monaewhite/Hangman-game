/*
Monae White
This file contains the declaration for string functions that uses the Merriam Webster's API for word and definiton generation
*/

#ifndef WORDFETCHER_HPP
#define WORDFETCHER_HPP
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <curl/curl.h> 
#include "json.hpp"

class wordFetcher{
public:
    wordFetcher();
    std::string fetchWord();
    std::string fetchDefinition(const std::string &word);
    std::string fetchType(const std::string &word);

private:
    std::vector<std::string> wordList;
    void loadWords();
    std::string makeAPICall(const std::string &url);
    static size_t writeCallBack(void *contents, size_t size, size_t nmemb, void *userp);
};

#endif //WORDFETCHER_HPP