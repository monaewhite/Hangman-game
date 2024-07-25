#include <iostream>
#include "playbyplay.hpp"

int main(){

    // wordFetcher wf;
    // std::string word = wf.fetchWord();

    // if(!word.empty()){
    //     std::cout << "Fetched word: " << word << std::endl;
    //     std::string definition = wf.fetchDefinition(word);
    //     std::cout << "Definition: " << definition << std::endl;
    // } 
    // else{
    //     std::cout << "Failed to fetch word." << std::endl;
    // }

    playByPlay game;
    game.play();

    return 0;
}
// g++ -std=c++17 main.cpp playbyplay.cpp picturedisplay.cpp wordfetcher.cpp -lcurl -o hangman
