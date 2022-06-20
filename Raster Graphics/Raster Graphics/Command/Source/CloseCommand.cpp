#include "../CloseCommand.h"

CloseCommand::CloseCommand(SessionMaster* const sessionMaster)
	: m_sessionMaster(sessionMaster) {
}

size_t CloseCommand::getNumberOfArgs() {
	return nArgs;
}

std::string CloseCommand::execute() {
	m_sessionMaster->closeActiveSession();

	return "Close was successful";
}
