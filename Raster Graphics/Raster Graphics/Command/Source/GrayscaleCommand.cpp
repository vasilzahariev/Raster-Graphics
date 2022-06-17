#include "../GrayscaleCommand.h"

GrayscaleCommand::GrayscaleCommand(Session* const session)
	: m_session(session) {
}

std::string GrayscaleCommand::execute() {
	std::string output = "";

	try {
		m_session->grayscale();

		output = "Grayscale was successful";
	}
	catch (std::exception err) {
		output = err.what();
	}

	return output;
}
