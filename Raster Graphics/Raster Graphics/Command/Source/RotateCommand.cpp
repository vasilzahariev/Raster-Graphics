#include "../RotateCommand.h"

RotateCommand::RotateCommand(Session* const sessionMaster, std::string_view direction)
	: m_session(sessionMaster), m_direction(direction) {
}

std::string RotateCommand::executor() {
	m_session->rotate(m_direction);

	return "Rotate was successful";
}
