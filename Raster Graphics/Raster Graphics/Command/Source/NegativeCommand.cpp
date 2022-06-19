#include "../NegativeCommand.h"

NegativeCommand::NegativeCommand(Session* const session)
	: m_session(session) {
}

std::string NegativeCommand::executor() {
	m_session->negative();

	return "Negative was successful";
}
