/*
Monae White
This file contains the implementation for string functions that uses the Merriam Webster's API for word and definiton generation
*/

#include "wordfetcher.hpp"

/*
    @param: pointer to the data received by the API call, sizes of each data chunk received, pointer to the string where the data will be stored
    @post: handles the data received from the API call.
    @return: the random word for the user to guess.
*/
size_t wordFetcher::writeCallBack(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp) -> append((char *)contents, size * nmemb); 
    return size * nmemb; //returns the total data of the size processed
}

/*
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

std::string wordFetcher::fetchWord(){
    std::string url = "https://www.dictionaryapi.com/api/v3/references/collegiate/json/random?key=your_api_key_here";
    std::string response = makeAPICall(url);

    if(response.empty()){
        std::cerr << "Error: Failed to fetch word from API" << std::endl;
        return "";
    }

    // Parse the response to extract the word (simplified for example purposes)
    // Note: You should use a proper JSON library to parse the response in a real-world application.
    std::string word = "example"; // Replace with actual parsing logic
    return word;
}

std::string wordFetcher::fetchDefinition(const std::string &word){
    std::string url = "https://www.dictionaryapi.com/api/v3/references/collegiate/json/" + word + "?key=your_api_key_here";
    std::string response = makeAPICall(url);

    if (response.empty()) {
        std::cerr << "Error: Failed to fetch definition from API" << std::endl;
        return "";
    }

    // Parse the response to extract the definition (simplified for example purposes)
    // Note: You should use a proper JSON library to parse the response in a real-world application.
    std::string definition = "A representative form or pattern"; // Replace with actual parsing logic
    return definition;
}
