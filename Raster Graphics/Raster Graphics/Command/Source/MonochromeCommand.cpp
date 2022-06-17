#include "../MonochromeCommand.h"

MonochromeCommand::MonochromeCommand(Session* const session)
	: m_session(session) {
}

std::string MonochromeCommand::execute() {
	std::string output = "";

	try {
		m_session->monochrome();

		output = "Monochrome was successful";
	}
	catch (std::exception err) {
		output = err.what();
	}

	return output;
}