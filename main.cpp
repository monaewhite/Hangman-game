#include "playbyplay.hpp"

int main() {
    playByPlay game;
    
    game.displayStatus(); // Initial display of game status
    
    // Test guessing letters
    game.guessLetter('e');
    game.displayStatus();
    
    game.guessLetter('x');
    game.displayStatus();
    
    game.guessLetter('a');
    game.displayStatus();
    
    game.guessLetter('z'); // Incorrect guess
    game.displayStatus();
    
    game.guessLetter('m');
    game.displayStatus();
    
    game.guessLetter('p');
    game.displayStatus();
    
    game.guessLetter('l');
    game.displayStatus();
    
    game.guessLetter('e');
    game.displayStatus();
    
    // game.play();

    return 0;
}
// g++ -std=c++17 main.cpp playbyplay.cpp picturedisplay.cpp wordfetcher.cpp -lcurl -o hangman
