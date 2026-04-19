#include <iostream>
#include "Game.h"
#include "LevelLoader.h"
#include "CommandSystem.h"

using namespace std;

void runLevel(Game& game, CommandSystem& commandSystem, int level) {
    loadLevel(game, level);
    cout << "WARNING: STATION FLOODING\n";

    while (game.gameRunning && game.player.oxygen > 0) {

        game.displayRoom();

        if (game.player.currentLocation == game.winRoom) {
            cout << "\n YOU ESCAPED! YOU WIN!\n";
            game.gameRunning = false;
            return;
        }
        cout << "What would you like to do?\n> ";
        string input;
        getline(cin, input);

        commandSystem.HandleInput(game, input);
        game.applyEnvironment();
    }

    if (game.player.oxygen <= 0) {
        cout << "\nYou ran out of oxygen... GAME OVER\n";
    }
}


int main()
{
    Game game;
    CommandSystem commandSystem;
    runLevel(game, commandSystem, 1);
    return 0;
}
