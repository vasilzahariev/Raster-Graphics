#include "../CloseCommand.h"

CloseCommand::CloseCommand(Session* const session)
	: m_session(session) {
}

std::string CloseCommand::execute() {
	m_session->close();// TODO: Add try catch and return the proper message
}
