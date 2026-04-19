#pragma once
#include "../ICommand.h"
#include "../Game.h"
#include <iostream>

using namespace std;

struct TakeCommand : ICommand
{
	void Execute(Game& game, const vector<string>& args) override
	{
		if (args.empty()) {
			cout << "Take what?\n";
			return;
		}
		game.takeItemByName(args[0]);
	}
};
