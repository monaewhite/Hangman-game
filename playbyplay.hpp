/*
Monae White
This file contains string functions that uses the Merriam Webster's API for word and definiton generation
*/

#ifndef PLAYBYPLAY_HPP
#define PLAYBYPLAY_HPP
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
#include <curl/curl.h>
#include "wordfetcher.hpp"
#include "picturedisplay.hpp"

class playByPlay{
private:
    wordFetcher word_fetcher;
    std::string word;
    std::string definition;
    std::vector<char> hidden_word;
    int attempts_left;
    std::set<char> guessed_letters;
public:
    playByPlay() : attempts_left(6) {
        word = word_fetcher.fetchWord();
        definition = word_fetcher.fetchDefinition(word);
        hidden_word = std::vector<char>(word.length(), '*');
    }
    int getAttemptsLeft();
    void setAttemptsLeft();
    bool checkValidity(char letter);
    void guessLetter(char letter);
    void displayStatus();
    bool checkWin();
    bool checkLoss();
    void play();
};

#endif //PLAYBYPLAY_HPP