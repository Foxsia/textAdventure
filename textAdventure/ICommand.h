#pragma once
#include <vector>
#include <string>

using namespace std;

class Game;

struct ICommand {
	virtual ~ICommand() = default;
	virtual void Execute(Game& game, const vector<string>& args) = 0;
};