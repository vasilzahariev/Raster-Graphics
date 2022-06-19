#include "../GrayscaleCommand.h"

GrayscaleCommand::GrayscaleCommand(Session* const session)
	: m_session(session) {
}

std::string GrayscaleCommand::executor() {
	m_session->grayscale();

	return "Grayscale was successful";
}
