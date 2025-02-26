/*
 * Author(s): Daniel Lebedev
 * Description: Puts everything together.
 */

#include "Player.h"
#include "Game.cpp"
#include <QCoreApplication>

// Current working product, user can create player, start game, and test some functionality
int main()
{
    // Create Game object
    Game game;

    // Create player by calling startGame()
    Player player = game.startGame();

    // Starts game loop. Not yet finished
    game.gameLoop(player);

}
