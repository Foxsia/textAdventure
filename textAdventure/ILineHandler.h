#pragma once
#include <string>

struct Room;

struct ILineHandler
{
	virtual ~ILineHandler() = default;
	virtual void handle(Room& room, const std::string& data) = 0;
};
