#include "../NegativeCommand.h"

NegativeCommand::NegativeCommand(Session* const session)
	: m_session(session) {
}

size_t NegativeCommand::getNumberOfArgs() {
	return nArgs;
}

std::string NegativeCommand::execute() {
	m_session->negative();

	return "Negative was successful";
}
