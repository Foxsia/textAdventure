#pragma once
#include "GameTypes.h"

struct Game
{
    bool gameRunning = true;
    Player player;
    vector<Room> world;
    int winRoom;

    void displayRoom();
    void lookAround();
    void applyEnvironment();
    void movePlayer(string direction);

    void useItem(const string& itemName);
    void takeItemByName(const std::string& name);
};
