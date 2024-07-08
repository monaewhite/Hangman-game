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
    
    // Run the play method to test the full game loop
    game.play();

    return 0;
}