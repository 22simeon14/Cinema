#include <iostream>
#include "System.h" 
#include "Session.h"
#include "CommandFactory.h"

void run_command_loop(System* sys) {
	Session* session = new Session();
	mystring input;
	while (true) {
		std::cout << "> ";
		input.getline(std::cin);
		if (input == "") continue;
		Command* cmd = CommandFactory::createCommand(sys, session, input);
		cmd->execute(sys, session, input);
	}
}

int main()
{
	System* system = new System();
	run_command_loop(system);
}

