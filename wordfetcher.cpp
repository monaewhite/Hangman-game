/*
Monae White
This file contains the implementation for string functions that uses the Merriam Webster's API for word and definiton generation
*/

#include "wordfetcher.hpp"

/**
    @param: pointer to the data received by the API call, sizes of each data chunk received, pointer to the string where the data will be stored
    @post: handles the data received from the API call.
    @return: the random word for the user to guess.
*/
size_t wordFetcher::writeCallBack(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp) -> append((char *)contents, size * nmemb); 
    return size * nmemb; //returns the total data of the size processed
}

/**
    @param: a const reference to the url.
    @post: handles the data received from the API call.
    @return: the data received from the API call.
*/
std::string wordFetcher::makeAPICall(const std::string &url){
    CURL *curl;
    CURLcode res;
    std::string buffer;

    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); // the url to send the request to
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallBack); // the function to call when data is received
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer); // the string to receive the stored data
        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl); // frees excess resources used
    } 
    else{
        std::cerr << "Failed to initialize CURL" << std::endl;
    }

    return buffer;
}

/**
    @param: n/a
    @post: parses the name of the word in the json file 
    @return: the word
*/
std::string wordFetcher::fetchWord(){
    std::string url = "https://www.dictionaryapi.com/api/v3/references/collegiate/json/random?key=your_api_key_here";
    std::string response = makeAPICall(url);

    if(response.empty()){
        std::cerr << "Error: Failed to fetch word from API" << std::endl;
        return "";
    }

    json jsonResponse = json::parse(response);
    if(!jsonResponse.is_array() || jsonResponse.empty() || !jsonResponse[0].is_object()){
        std::cerr << "Error: Invalid JSON response format" << std::endl;
        return "";
    }
    std::string word = jsonResponse[0]["meta"]["id"];

    return word;
}

/**
    @param: n/a
    @post: parses the definition of the word in the json file
    @return: the definition
*/
std::string wordFetcher::fetchDefinition(const std::string &word){
    std::string url = "https://www.dictionaryapi.com/api/v3/references/collegiate/json/" + word + "?key=your_api_key_here";
    std::string response = makeAPICall(url);

    if (response.empty()) {
        std::cerr << "Error: Failed to fetch definition from API" << std::endl;
        return "";
    }

    json jsonResponse = json::parse(response);
    if (!jsonResponse.is_array() || jsonResponse.empty() || !jsonResponse[0].is_object()) {
        std::cerr << "Error: Invalid JSON response format" << std::endl;
        return "";
    }
    std::string definition = jsonResponse[0]["shortdef"][0];

    return definition;
}
