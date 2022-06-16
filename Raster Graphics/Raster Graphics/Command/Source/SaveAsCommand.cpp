#include "../SaveAsCommand.h"

SaveAsCommand::SaveAsCommand(Session* const session, std::string_view fileName)
	: m_session(session), m_fileName(fileName) {
}

std::string SaveAsCommand::execute() {
	m_session->saveAs(m_fileName);// TODO: Add try catch and return the proper message
}
