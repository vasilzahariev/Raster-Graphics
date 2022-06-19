#include "../SwitchCommand.h"

SwitchCommand::SwitchCommand(SessionMaster* const sessionMaster, const int id)
	: m_sessionMaster(sessionMaster), m_id(id) {
}

std::string SwitchCommand::executor() {
	m_sessionMaster->switchSession(m_id);

	return "Switched to session with ID: " + std::to_string(m_id);
}
