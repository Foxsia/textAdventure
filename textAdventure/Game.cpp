#include "Game.h"
#include <iostream>
using namespace std;

//player
void Player::showInventory() {
    cout << "Inventory:\n";
    for (Item item : inventory) {
        cout << "-> " << item.name << "\n";
    }
}

bool Player::hasItem(const Item& item) {
    for (auto& i : inventory)
    {
        if (i.name == item.name) return true;
    }
    return false;
}
//game
void Game::displayRoom() {
    Room& currentRoom = world[player.currentLocation];
    cout << currentRoom.name << "\n" << currentRoom.description << "\n";
    cout << (currentRoom.flooded ? "flooded" : "not flooded");
    cout << "\nOxygen: " << player.oxygen << "\n";

    for (auto exit : currentRoom.exits)
    {
        cout << exit.first << "\n";
    }
}

void Game::lookAround() {
    Room& currentRoom = world[player.currentLocation];


    cout << "You search the area carefully...\n";

    if (!currentRoom.items.empty())
    {
        for (Item item : currentRoom.items)
        {
            cout << "-> " << item.name << "\n";
        }
    }
    else
    {
        cout << "You found nothing useful\n";
    }
    currentRoom.searched = true;
}

void Game::applyEnvironment() {
    if (world[player.currentLocation].flooded)
    {
        player.oxygen -= 5;
        cout << "You struggle to breathe (-5 oxygen)\n";
    }
}

void Game::movePlayer(string direction) {
    Room& currentRoom = world[player.currentLocation];
    if (!currentRoom.exits.count(direction))
    {
        cout << "You can't go that way.\n";
        return;
    }

    int nextRoom = currentRoom.exits[direction];
    if (world[nextRoom].locked) {
        cout << "The door is locked.\n";
        return;
    }

    player.currentLocation = nextRoom;
    cout << "You moved " << direction << ".\n";
}

void Game::takeItemByName(const std::string& name)
{
    Room& currentRoom = world[player.currentLocation];

    if (!currentRoom.searched)
    {
        std::cout << "You should look around first.\n";
        return;
    }

    for (int i = 0; i < currentRoom.items.size(); i++)
    {
        if (currentRoom.items[i].name == name)
        {
            player.inventory.push_back(currentRoom.items[i]);
            currentRoom.items.erase(currentRoom.items.begin() + i);

            std::cout << "You picked up: " << name << "\n";
            return;
        }
    }

    std::cout << "No such item here\n";
}

void Game::useItem(const string& itemName) {
    Room& currentRoom = world[player.currentLocation];

    for (int i = 0; i < player.inventory.size(); i++)
    {
        Item& item = player.inventory[i];
        if (item.name == itemName)
        {
            if (item.type == ItemType::Key) {

                // check all exits
                for (auto& exit : currentRoom.exits) {
                    int nextRoom = exit.second;

                    if (world[nextRoom].locked)
                    {
                        if (world[nextRoom].requiredKey == item.name)
                        {
                            world[nextRoom].locked = false;

                            cout << "You unlocked the door to the "
                                << exit.first << ".\n";

                            // remove after use
                            player.inventory.erase(player.inventory.begin() + i);
                            return;
                        }
                    }
                }

                cout << "Nothing to unlock here.\n";
                return;
            }

            if (item.type == ItemType::Clothing) {
                if (currentRoom.flooded && currentRoom.fixable) {
                    currentRoom.flooded = false;

                    cout << "You plug the holes with the cloth. The water stops flowing.\n";

                    // remove after use
                    player.inventory.erase(player.inventory.begin() + i);
                    return;
                }
            }

            cout << "You can't use that here.\n";
            return;
        }
    }
    cout << "You don't have that item.\n";
    return;
}