#pragma once
#include "GameTypes.h"

class Game
{
private:
    bool gameRunning = true;
    Player player;
    vector<Room> world;
    int winRoom;

public:
    void displayRoom();
    void lookAround();
    void applyEnvironment();
    void movePlayer(string direction);

    void useItem(const string& itemName);
    void takeItemByName(const std::string& name);

    void reset();

    Player& getPlayer() { return player; }
    std::vector<Room>& getWorld() { return world; }
    void setWinRoom(int room) { winRoom = room; }
    int getWinRoom() { return winRoom; }
    bool isGameRunning() { return gameRunning; }
    void setGameRunning(bool running) { gameRunning = running; }
};
