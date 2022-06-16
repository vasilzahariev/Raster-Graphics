#include "../GrayscaleCommand.h"

GrayscaleCommand::GrayscaleCommand(Session* const session)
	: m_session(session) {
}

void GrayscaleCommand::execute() {
	m_session->grayscale();
}

GrayscaleCommand* GrayscaleCommand::clone() {
	return new GrayscaleCommand(m_session);
}
