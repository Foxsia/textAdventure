#pragma once
#include "../ICommand.h"
#include "../Game.h"
#include <iostream>

using namespace std;

struct HelpCommand : ICommand
{
	void Execute(Game& game, const vector<string>& args) override
	{
        cout << "Commands:\n";
        cout << "move <direction>\n";
        cout << "take <item>\n";
        cout << "use <item>\n";
        cout << "look\n";
        cout << "inventory\n";
        cout << "help\n";
        cout << "quit\n";
	}
};

