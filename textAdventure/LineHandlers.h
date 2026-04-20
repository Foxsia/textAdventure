#pragma once
#include "ILineHandler.h"
#include "GameTypes.h"
#include <string>

class NameHandler : public ILineHandler 
{
public:
	void handle(Room& room, const std::string& data) override;
};

class DescHandler : public ILineHandler
{
public:
    void handle(Room& room, const std::string& data) override;
};

class ExitHandler : public ILineHandler
{
public:
    void handle(Room& room, const std::string& data) override;
};

class ItemHandler : public ILineHandler
{
public:
    void handle(Room& room, const std::string& data) override;
};

class FloodedHandler : public ILineHandler
{
public:
    void handle(Room& room, const std::string& data) override;
};

class FixableHandler : public ILineHandler
{
public:
    void handle(Room& room, const std::string& data) override;
};

class LockedHandler : public ILineHandler
{
public:
    void handle(Room& room, const std::string& data) override;
};

class RequiredKeyHandler : public ILineHandler
{
public:
    void handle(Room& room, const std::string& data) override;
};
