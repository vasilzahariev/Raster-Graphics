#include "../RotateCommand.h"

RotateCommand::RotateCommand(Session* const sessionMaster, std::string_view direction)
	: m_session(sessionMaster), m_direction(direction) {
}

std::string RotateCommand::execute() {
	std::string output = "";

	try {
		m_session->rotate(m_direction);

		output = "SaveAs was successful";
	}
	catch (std::exception err) {
		output = err.what();
	}

	return output;
}
