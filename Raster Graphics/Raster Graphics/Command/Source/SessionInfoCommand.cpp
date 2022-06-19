#include "../SessionInfoCommand.h"

SessionInfoCommand::SessionInfoCommand(Session* const session)
	: m_session(session) {
}

std::string SessionInfoCommand::executor() {
	if (m_session == nullptr)
		throw SessionException("There is no active session");

	return m_session->info();
}
