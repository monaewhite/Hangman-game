# Hangman Game

## Overview
This project implements a text-based Hangman game in C++ using object-oriented programming principles. The game fetches random words and their definitions from the Merriam-Webster API to enhance user engagement and learning.

## Features
- Text-based Hangman game with dynamic word fetching
- Integration with Merriam-Webster API for random word and definition retrieval
- Gradual word reveal with each correct guess
- Stick figure drawing that updates with each incorrect guess

## Usage
1. When you run the game, it will start by fetching a random word and its definition from the Merriam-Webster API.
2. You will see the word represented by asterisks (`*`), with the number of attempts left and the guessed letters displayed.
3. Guess a letter by typing it and pressing Enter.
4. The game will reveal the guessed letters if they are correct, or draw another part of the stick figure if the guess is incorrect.
5. The game ends when you either guess the word correctly or run out of attempts.

## Acknowledgements
- [CURL](https://curl.se/) for HTTP requests
- [nlohmann/json](https://github.com/nlohmann/json) for JSON parsing
- [Merriam-Webster API](https://dictionaryapi.com/) for word and definition retrieval
