#pragma once
#include "../ICommand.h"
#include "../Game.h"
#include <iostream>

using namespace std;

struct MoveCommand : ICommand
{
	void Execute(Game& game, const vector<string>& args) override 
	{
		if (args.empty()) {
			cout << "Move where?\n";
			return;
		}
		game.movePlayer(args[0]);
	}
};
