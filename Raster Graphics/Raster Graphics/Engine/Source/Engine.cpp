#include "../Engine.h"

Engine::Engine() {
}

Engine& Engine::getInstance() {
	static Engine engine;

	return engine;
}

void Engine::run() {
	std::string line;

	// TODO: Catch Errors or maybe don't and just get the message of the errors? sounds better?
	
	do {
		std::cout << '>';
		std::getline(std::cin, line);
		Command* cmd = CommandParser::parseCommandLine(line, &m_sessionMaster);

		if (cmd == nullptr)
			throw CommandException("Invalid input arguments");
		
		std::cout << cmd->execute() << std::endl;
	} while (true);
}
