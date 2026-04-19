#pragma once
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Game;
struct ICommand;

class CommandSystem
{
private:
	//making a pointer to the function
	unordered_map<string, ICommand*> commands;
public:
    void HandleInput(Game& game, const string& input);
    CommandSystem();

    ~CommandSystem();
};
