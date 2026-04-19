#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;
enum class ItemType { Key, Clothing };

struct Item {
    string name;
    ItemType type;
};
struct Room
{
    string name;
    string description;
    map<string, int> exits;
    vector<Item> items;

    bool flooded = false;
    bool searched = false;
    bool locked = false;
    bool fixable = false;

    string requiredKey = "";
};

struct Player
{
    int currentLocation = 0;
    int oxygen = 100;
    vector<Item> inventory;

    void showInventory();
    bool hasItem(const Item& item);
};
