/*
Monae White
This file contains the implementation for string functions that uses the Merriam Webster's API for word and definiton generation
*/

#include "wordfetcher.hpp"
#include "json.hpp"

using json = nlohmann::json;

/**
    @param: n/a
    @post: loads words when class object is initialized
    @return: n/a
*/
wordFetcher::wordFetcher(){
    loadWords(); 
    std::srand(std::time(0));
}

/**
    @param: pointer to the data received by the API call, sizes of each data chunk received, pointer to the string where the data will be stored
    @post: handles the data received from the API call.
    @return: the random word for the user to guess.
*/
size_t wordFetcher::writeCallBack(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp) -> append((char *)contents, size * nmemb); 
    return size * nmemb; // returns the total data of the size processed
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
    @post: loads words from words.txt into the vector wordList
    @return: n/a
*/
void wordFetcher::loadWords(){
    std::ifstream file("words.txt");
    if(!file.is_open()){
        std::cerr << "Error: Could not open words file" << std::endl;
        return;
    }

    std::string word;
    while(std::getline(file, word)){
        wordList.push_back(word);
    }

    file.close();
}

/**
    @param: n/a
    @post: fetches a word from the vector wordList
    @return: the word
*/
std::string wordFetcher::fetchWord(){
    if(wordList.empty()){
        std::cerr << "Error: Word list is empty." << std::endl;
        return "";
    }

    int index = std::rand() % wordList.size();
    std::string word = wordList[index];

    return word;
}

/**
    @param: n/a
    @post: parses the definition of the word in the json file
    @return: the definition
*/
std::string wordFetcher::fetchDefinition(const std::string &word){
    std::string url = "https://www.dictionaryapi.com/api/v3/references/collegiate/json/" + word + "?key=243002c1-6010-412a-9ec4-8a0dedba2ec8";
    std::string response = makeAPICall(url);

    if(response.empty()){
        std::cerr << "Error: Failed to fetch definition from API." << std::endl;
        return "";
    }

    json jsonResponse = json::parse(response);

    std::string definition;
    
    try{
        if(jsonResponse[0].contains("shortdef") && jsonResponse[0]["shortdef"].is_array()){
            definition = jsonResponse[0]["shortdef"][0];
            definition[0] = std::toupper(definition[0]); // capitalize the first character since the definitions are automatically lowercase 
            
            // size_t colonPosition = definition.find(':');
            // if(colonPosition != std::string::npos){ 
            //     definition = definition.substr(0, colonPosition); // makes the definitions more concise 
            // }
        } 
        else{
            std::cerr << "Error: Definition not found in the response." << std::endl;
        }
    } 
    catch(const std::exception &e){
        std::cerr << "Error parsing definition: " << e.what() << std::endl;
    }

    return definition;
}