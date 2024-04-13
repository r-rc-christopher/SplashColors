#include <cstdlib>
#include <iostream>
#include "game.hpp"

int main()
{    
    Game* game = new Game();
    game->onStart();

    delete game;
    return EXIT_SUCCESS;
}
