#include "../MonochromeCommand.h"

MonochromeCommand::MonochromeCommand(Session* const session)
	: m_session(session) {
}

std::string MonochromeCommand::executor() {
	m_session->monochrome();

	return "Monochrome was successful";
}