#include "../CloseCommand.h"

CloseCommand::CloseCommand(SessionMaster* const sessionMaster)
	: m_sessionMaster(sessionMaster) {
}

std::string CloseCommand::executor() {
	m_sessionMaster->closeActiveSession();

	return "Close was successful";
}
