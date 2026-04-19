#include "CommandSystem.h"
#include "ICommand.h"

#include "Commands/MoveCommand.h"
#include "Commands/TakeCommand.h"
#include "Commands/UseCommand.h"
#include "Commands/LookCommand.h"
#include "Commands/InventoryCommand.h"
#include "Commands/HelpCommand.h"
#include "Commands/QuitCommand.h"

#include <iostream>

using namespace std;

CommandSystem::CommandSystem() {
	commands["move"] = new MoveCommand();
	commands["take"] = new TakeCommand();
	commands["use"] = new UseCommand();
	commands["inventory"] = new InventoryCommand();
	commands["help"] = new HelpCommand();
	commands["quit"] = new QuitCommand();
	commands["look"] = new LookCommand();
}

void CommandSystem::HandleInput(Game& game, const string& input) 
{
	string commandName;
	vector<string> args;

	size_t index = 0;
	while (index < input.size() && input[index] == ' ') index++;

	while (index < input.size() && input[index] != ' ') commandName += input[index++];

	while (index < input.size()) {
		while (index < input.size() && input[index] == ' ') index++;

		string arg;
		while (index < input.size() && input[index] != ' ') arg += input[index++];

		if (!arg.empty()) args.push_back(arg);
	}

	auto commandPair = commands.find(commandName);

	if (commandPair != commands.end()) 
	{
		auto command = commandPair->second;
		command->Execute(game, args);
	}
	else
	{
		cout << "Unknown command.\n";
	}
}

CommandSystem::~CommandSystem()
{
	for (auto& pair : commands)
	{
		delete pair.second;
	}
}