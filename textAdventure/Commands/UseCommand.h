#pragma once
#include "../ICommand.h"
#include "../Game.h"
#include <iostream>

using namespace std;

struct UseCommand : ICommand
{
	void Execute(Game& game, const vector<string>& args) override
	{
		if (args.empty()) {
			cout << "Use what?\n";
			return;
		}
		game.useItem(args[0]);
	}
};
