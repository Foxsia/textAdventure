#include "LineHandlers.h"
#include "LevelParser.h"

LevelParser::LevelParser()
{
    handlers["name:"] = new NameHandler();
    handlers["desc:"] = new DescHandler();
    handlers["exit:"] = new ExitHandler();
    handlers["item:"] = new ItemHandler();
    handlers["flooded:"] = new FloodedHandler();
    handlers["fixable:"] = new FixableHandler();
    handlers["locked:"] = new LockedHandler();
    handlers["requiredKey:"] = new RequiredKeyHandler();
}

void LevelParser::parseLine(Room& room, const std::string& line)
{
    for (auto& pair : handlers)
    {
        const std::string& key = pair.first;

        if (line.rfind(key, 0) == 0)
        {
            std::string data = line.substr(key.size()+1);
            pair.second->handle(room, data);
            return;
        }
    }
}

LevelParser::~LevelParser()
{
    for (auto& pair : handlers)
    {
        delete pair.second;
    }
}