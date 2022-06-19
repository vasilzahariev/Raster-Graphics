#include "../Engine.h"

Engine::Engine() {
}

Engine& Engine::getInstance() {
	static Engine engine;

	return engine;
}

void Engine::run(std::istream& in, std::ostream& out) {
	std::string line;
	Command* cmd = nullptr;
	
	do {
		if (&in == &std::cin) out << '>';

		std::getline(in, line);

		try {
			cmd = CommandParser::parseCommandLine(line, &m_sessionMaster);

			if (cmd == nullptr)
				throw CommandException("Invalid input arguments");

			out << cmd->execute() << std::endl;
		}
		catch (CommandException err) {
			out << err.what() << std::endl;
		}
		catch (FileException err) {
			out << err.what() << std::endl;
		}
		catch (ImageException err) {
			out << err.what() << std::endl;
		}
		catch (NotAnException err) { // TODO: Add an easter egg =)
			out << err.what() << std::endl;
		}
		catch (OutOfBoundsException err) {
			out << err.what() << std::endl;
		}
		catch (SessionException err) {
			out << err.what() << std::endl;
		}
		catch (std::exception err) {
			out << err.what() << std::endl;
		}

	} while (dynamic_cast<ExitCommand*>(cmd) == nullptr);
}
