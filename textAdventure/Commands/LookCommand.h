#pragma once
#include "../ICommand.h"
#include "../Game.h"

using namespace std;

struct LookCommand : ICommand
{
	void Execute(Game& game, const vector<string>& args) override
	{
		game.lookAround();
	}
};