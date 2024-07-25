/*
Monae White
This file contains the implementation for a function that displays the hangman stick figure based on the user's progress
*/

#include "picturedisplay.hpp"

/*
    @param: integer attempts left that the user has
    @post: displays the stick figure depending on the user's remaining attempts
    @return: n/a
*/
void picturedisplay(int attempts_left){
    if(attempts_left == 6){
        std::cout << "\n"
                  << "    ---------- \n"
                  << "    |     |\n"
                  << "    |     \n"
                  << "    |     \n"
                  << "    |     \n"
                  << "    |     \n"
                  << "    |     \n"
                  << "    |     \n"
                  << "______________" << std::endl;
    }
    else if(attempts_left == 5){ // hangman after one mistake
        std::cout << "\n"
                  << "    ---------- \n"
                  << "    |     |\n"
                  << "    |     @\n"
                  << "    |     \n"
                  << "    |     \n"
                  << "    |     \n"
                  << "    |     \n"
                  << "    |     \n"
                  << "______________" << std::endl;
    }
    else if(attempts_left == 4){ // hangman after two mistakes
        std::cout << "\n"
                  << "    ---------- \n"
                  << "    |     |\n"
                  << "    |     @\n"
                  << "    |     |\n"
                  << "    |     |\n"
                  << "    |     \n"
                  << "    |     \n"
                  << "    |     \n"
                  << "______________" << std::endl;
    }
    else if(attempts_left == 3){ // hangman after three mistakes
        std::cout << "\n"
                  << "    ---------- \n"
                  << "    |     |\n"
                  << "    |     @\n"
                  << "    |     |\n"
                  << "    |     |\n"
                  << "    |    / \n"
                  << "    |     \n"
                  << "    |     \n"
                  << "______________" << std::endl;
    }
    else if(attempts_left == 2){ // hangman after four mistakes
        std::cout << "\n"
                  << "    ---------- \n"
                  << "    |     |\n"
                  << "    |     @\n"
                  << "    |     |\n"
                  << "    |     |\n"
                  << "    |    / \\\n"
                  << "    |     \n"
                  << "    |     \n"
                  << "______________" << std::endl;
    }
    else if(attempts_left == 1){ // hangman after five mistakes
        std::cout << "\n"
                  << "    ---------- \n"
                  << "    |     |\n"
                  << "    |     @\n"
                  << "    |    /|\\\n"
                  << "    |     |\n"
                  << "    |    / \\\n"
                  << "    |     \n"
                  << "    |     \n"
                  << "______________" << std::endl;
    }
    else if(attempts_left == 0){ // hangman after six mistakes
        std::cout << "\n"
                  << "    ---------- \n"
                  << "    |     |\n"
                  << "    |     @\n"
                  << "    |    /|\\\n"
                  << "    |     |\n"
                  << "    |    / \\\n"
                  << "    |     \n"
                  << "    |     \n"
                  << "______________" << std::endl;
    }
}