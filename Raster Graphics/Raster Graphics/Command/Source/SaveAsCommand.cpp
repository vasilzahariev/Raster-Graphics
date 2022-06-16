#include "../SaveAsCommand.h"

SaveAsCommand::SaveAsCommand(Session* const session, std::string_view fileName)
	: m_session(session), m_fileName(fileName) {
}

void SaveAsCommand::execute() {
	m_session->saveAs(m_fileName);
}

SaveAsCommand* SaveAsCommand::clone() {
	return new SaveAsCommand(m_session, m_fileName);
}
