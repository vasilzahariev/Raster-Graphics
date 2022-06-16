#include "../RotateCommand.h"

RotateCommand::RotateCommand(Session* const sessionMaster, std::string_view direction)
	: m_session(sessionMaster), m_direction(direction) {
}

std::string RotateCommand::execute() {
	m_session->rotate(m_direction);// TODO: Add try catch and return the proper message
}
