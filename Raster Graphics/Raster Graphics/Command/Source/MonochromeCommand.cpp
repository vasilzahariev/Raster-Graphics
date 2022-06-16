#include "../MonochromeCommand.h"

MonochromeCommand::MonochromeCommand(Session* const session)
	: m_session(session) {
}

std::string MonochromeCommand::execute() {
	m_session->monochrome();// TODO: Add try catch and return the proper message
}