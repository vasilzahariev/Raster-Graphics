#include "../MonochromeCommand.h"

MonochromeCommand::MonochromeCommand(Session* const session)
	: m_session(session) {
}

void MonochromeCommand::execute() {
	m_session->monochrome();
}

MonochromeCommand* MonochromeCommand::clone() {
	return new MonochromeCommand(m_session);
}
