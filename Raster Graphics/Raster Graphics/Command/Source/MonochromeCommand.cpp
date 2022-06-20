#include "../MonochromeCommand.h"

MonochromeCommand::MonochromeCommand(Session* const session)
	: m_session(session) {
}

size_t MonochromeCommand::getNumberOfArgs() {
	return nArgs;
}

std::string MonochromeCommand::execute() {
	m_session->monochrome();

	return "Monochrome was successful";
}