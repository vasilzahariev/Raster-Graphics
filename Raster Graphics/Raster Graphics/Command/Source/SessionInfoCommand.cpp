#include "../SessionInfoCommand.h"

SessionInfoCommand::SessionInfoCommand(Session* const session)
	: m_session(session) {
}

size_t SessionInfoCommand::getNumberOfArgs() {
	return nArgs;
}

std::string SessionInfoCommand::execute() {
	if (m_session == nullptr)
		throw SessionException("There is no active session");

	return m_session->info();
}
