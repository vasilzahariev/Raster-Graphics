#include "../Engine.h"

Engine::Engine()
	: m_cmd(nullptr), m_in(nullptr), m_out(nullptr) {
}

Engine& Engine::getInstance() {
	static Engine engine;

	return engine;
}

void Engine::run(std::istream& in, std::ostream& out) {
	setInAndOut(in, out);

	do {
		mainEngineLoop();
	} while (dynamic_cast<ExitCommand*>(m_cmd) == nullptr);

	checkForUnsavedChanges(); // TODO: nqkude se hvyrlq greshka vij kude

	printToOut("Goodbye");
}

void Engine::mainEngineLoop() {
	checkIfTheStreamsAreCorrect();
	printInputSymbol();
	readLine();
	parseAndExecuteCommand();
}

void Engine::setInAndOut(std::istream& in, std::ostream& out) {
	m_in = &in;
	m_out = &out;
}

void Engine::checkIfTheStreamsAreCorrect() const {
	if (m_in == nullptr || m_out == nullptr)
		throw std::exception("There are no valid streams");
}

void Engine::printInputSymbol() const {
	if (m_in == &std::cin) *m_out << '>';
}

void Engine::readLine() {
	std::getline(*m_in, m_line);
}

void Engine::parseAndExecuteCommand() {
	try {
		m_cmd = CommandParser::parseCommandLine(m_line, &m_sessionMaster);

		checkIfCommandIsCorrect();
		printToOut(m_cmd->execute());
	}
	catch (const NotAnException& err) {
		// =) (molq ne vzimai tochki moga da proverrqvam predi try-catch-a prosto i gotovo, tova e za maitapa) =)
	}
	catch (const std::exception& err) {
		printToOut(err.what());
	}
}

void Engine::checkIfCommandIsCorrect() const {
	if (m_cmd == nullptr)
		throw CommandException("Invalid input arguments");
}

void Engine::printToOut(std::string_view output) {
	*m_out << output << std::endl;
}

void Engine::checkForUnsavedChanges() {
	if (m_sessionMaster.areThereUnsavedChanges()) {
		do {
			printToOut("There are unsaved changes. Choose to either save them or exit the application (save | exit)");
			readLine();
		} while (m_line != "save" && m_line != "exit");

		if (m_line == "save") {
			CommandFactory::createCommand(std::vector<std::string>{"save"}, & m_sessionMaster)->execute();
		}
	}
}
