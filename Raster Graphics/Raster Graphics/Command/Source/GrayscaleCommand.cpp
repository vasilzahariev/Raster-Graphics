#include "../GrayscaleCommand.h"

GrayscaleCommand::GrayscaleCommand(Session* const session)
	: m_session(session) {
}

std::string GrayscaleCommand::execute() {
	m_session->grayscale();// TODO: Add try catch and return the proper message
}
