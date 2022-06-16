#include "../RotateCommand.h"

RotateCommand::RotateCommand(Session* const sessionMaster, std::string_view direction)
	: m_session(sessionMaster), m_direction(direction) {
}

void RotateCommand::execute() {
	m_session->rotate(m_direction);
}

RotateCommand* RotateCommand::clone() {
	return new RotateCommand(m_session, m_direction);
}
