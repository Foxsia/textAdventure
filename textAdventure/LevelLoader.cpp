#include "LevelLoader.h"
#include "LevelParser.h"
#include <iostream>
#include <fstream>

using namespace std;

void loadLevelFromFile(Game& game, const string& filename)
{

    game.reset();

    ifstream file(filename);
    if (!file)
    {
        cout << "Failed to open level file!\n";
        return;
    }
    LevelParser parser;

    string line;
    Room currentRoom;

    while (getline(file, line))
    {
        if (line.empty()) continue;

        if (line == "ROOM")
        {
            if (!currentRoom.name.empty())game.getWorld().push_back(currentRoom);

            currentRoom = Room(); // reset
        }
        else {
            parser.parseLine(currentRoom, line);
        }
    }

    if (!currentRoom.name.empty())game.getWorld().push_back(currentRoom);

    game.setWinRoom(game.getWorld().size() - 1);
}

void loadLevel(Game& game, int level) {

    switch (level) {
    case 1:
        loadLevelFromFile(game, "Levels/level1.txt");
        break;
    
    default:
        cout << "Unknown level!\n";
        break;
    }
}