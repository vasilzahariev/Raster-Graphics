#include "../SessionInfoCommand.h"

SessionInfoCommand::SessionInfoCommand(Session* const session)
	: m_session(session) {
}

std::string SessionInfoCommand::execute() {
	return m_session->info();
}
