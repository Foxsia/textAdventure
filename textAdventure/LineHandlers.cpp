#include "LineHandlers.h"

// Name
void NameHandler::handle(Room& room, const std::string& data)
{
    room.name = data;
}

// Desc
void DescHandler::handle(Room& room, const std::string& data)
{
    room.description = data;
}

// Exit
void ExitHandler::handle(Room& room, const std::string& data)
{
    size_t space = data.find(' ');
    if (space == std::string::npos) return;

    std::string dir = data.substr(0, space);
    int target = std::stoi(data.substr(space + 1));

    room.exits[dir] = target;
}

// Item
void ItemHandler::handle(Room& room, const std::string& data)
{
    size_t space = data.find(' ');
    if (space == std::string::npos) return;

    std::string name = data.substr(0, space);
    std::string type = data.substr(space + 1);

    Item item;
    item.name = name;
    item.type = (type == "Key") ? ItemType::Key : ItemType::Clothing;

    room.items.push_back(item);
}

// Flooded
void FloodedHandler::handle(Room& room, const std::string& data)
{
    room.flooded = (data.find("true") != std::string::npos);
}

// Fixable
void FixableHandler::handle(Room& room, const std::string& data)
{
    room.fixable = (data.find("true") != std::string::npos);
}

// Locked
void LockedHandler::handle(Room& room, const std::string& data)
{
    room.locked = (data.find("true") != std::string::npos);
}

// RequiredKey
void RequiredKeyHandler::handle(Room& room, const std::string& data)
{
    room.requiredKey = data;
}