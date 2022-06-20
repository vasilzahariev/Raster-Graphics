#include "../GrayscaleCommand.h"

GrayscaleCommand::GrayscaleCommand(Session* const session)
	: m_session(session) {
}

size_t GrayscaleCommand::getNumberOfArgs() {
	return nArgs;
}

std::string GrayscaleCommand::execute() {
	m_session->grayscale();

	return "Grayscale was successful";
}
