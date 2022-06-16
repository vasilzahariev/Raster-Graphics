#include "../NegativeCommand.h"

NegativeCommand::NegativeCommand(Session* const session)
	: m_session(session) {
}

std::string NegativeCommand::execute() {
	m_session->negative();// TODO: Add try catch and return the proper message
}
