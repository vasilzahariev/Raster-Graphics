#include "CloseCommand.h"

CloseCommand::CloseCommand(Session* const session)
	: m_session(session) {
}

void CloseCommand::execute() {
	m_session->close();
}

CloseCommand* CloseCommand::clone() {
	return new CloseCommand(m_session);
}
