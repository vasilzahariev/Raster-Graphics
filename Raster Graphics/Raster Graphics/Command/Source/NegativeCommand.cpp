#include "../NegativeCommand.h"

NegativeCommand::NegativeCommand(Session* const session)
	: m_session(session) {
}

void NegativeCommand::execute() {
	m_session->negative();
}

NegativeCommand* NegativeCommand::clone() {
	return new NegativeCommand(m_session);
}
