#include "LevelLoader.h"
#include <iostream>
#include <fstream>

using namespace std;
void loadLevelFromFile(Game& game, const string& filename)
{

    game.world.clear();
    game.player.currentLocation = 0;
    game.player.oxygen = 100;
    game.player.inventory.clear();

    ifstream file(filename);
    if (!file)
    {
        cout << "Failed to open level file!\n";
        return;
    }

    string line;
    Room currentRoom;

    while (getline(file, line))
    {
        if (line.empty()) continue;

        if (line == "ROOM")
        {
            if (!currentRoom.name.empty())game.world.push_back(currentRoom);

            currentRoom = Room(); // reset
        }
        else if (line.find("name:") == 0)
        {
            currentRoom.name = line.substr(6);
        }
        else if (line.find("desc:") == 0)
        {
            currentRoom.description = line.substr(6);
        }
        else if (line.find("exit:") == 0)
        {
            string data = line.substr(6); // "east 1"

            string dir;
            string numberStr;

            size_t index = 0;

            while (index < data.size() && data[index] != ' ')dir += data[index++];

            while (index < data.size() && data[index] == ' ')index++;

            while (index < data.size())
                numberStr += data[index++];

            int target = stoi(numberStr);//string to int

            currentRoom.exits[dir] = target;
        }
        else if(line.find("item:") == 0)
        {
            string data = line.substr(6); // "key Key"

            string name;
            string type;

            size_t index = 0;

            while (index < data.size() && data[index] != ' ')name += data[index++];

            while (index < data.size() && data[index] == ' ')index++;

            while (index < data.size())type += data[index++];

            Item item;
            item.name = name;

            if (type == "Key") 
            {
                item.type = ItemType::Key;
            }
            else 
            {
                item.type = ItemType::Clothing;
            }

            currentRoom.items.push_back(item);
        }
        else if (line.find("flooded:") == 0)
        {
            currentRoom.flooded = (line.find("true") !=string::npos);
        }
        else if (line.find("fixable:") == 0)
        {
            currentRoom.fixable = (line.find("true") !=string::npos);
        }
        else if (line.find("locked:") == 0)
        {
            currentRoom.locked = (line.find("true") != string::npos);
        }
        else if (line.find("requiredKey:") == 0)
        {
            currentRoom.requiredKey = line.substr(13);
        }
    }

    if (!currentRoom.name.empty())game.world.push_back(currentRoom);

    game.winRoom = game.world.size() - 1;
}

void loadLevel(Game& game, int level) {

    switch (level) {
    case 1:
        loadLevelFromFile(game, "Levels/level1.txt");
        break;
    }
}