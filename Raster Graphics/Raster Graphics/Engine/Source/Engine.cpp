#include "../Engine.h"

Engine::Engine() {
}

Engine& Engine::getInstance() {
	static Engine engine;

	return engine;
}

void Engine::run() {
	std::string line;

	// TODO: Catch Errors
	
	do {
		std::cout << '>';
		std::getline(std::cin, line);
		Command* cmd = CommandParser::parseCommandLine(line, &m_sessionMaster);

		if (cmd == nullptr)
			throw CommandException("Invalid input arguments");
		
		cmd->execute();
	} while (true);
}
