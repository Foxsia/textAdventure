#pragma once
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

struct Game;
struct ICommand;

struct CommandSystem
{
	//making a pointer to the function
	unordered_map<string, ICommand*> commands;
    void HandleInput(Game& game, const string& input);
    CommandSystem();

    ~CommandSystem();
};
