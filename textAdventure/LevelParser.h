#pragma once
#include <unordered_map>
#include <string>

struct Room;
struct ILineHandler;

class LevelParser
{
private:
    std::unordered_map<std::string, ILineHandler*> handlers;

public:
    LevelParser();
    ~LevelParser();

    void parseLine(Room& room, const std::string& line);
};