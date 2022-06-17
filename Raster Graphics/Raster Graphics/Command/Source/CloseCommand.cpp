#include "../CloseCommand.h"

CloseCommand::CloseCommand(Session* const session)
	: m_session(session) {
}

std::string CloseCommand::execute() {
	std::string output = "";

	try {
		m_session->close();

		output = "Close was successful";
	}
	catch (std::exception err) {
		output = err.what();
	}

	return output;
}
