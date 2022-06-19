#include "../SaveAsCommand.h"

SaveAsCommand::SaveAsCommand(Session* const session, std::string_view fileName)
	: m_session(session), m_fileName(fileName) {
}

std::string SaveAsCommand::executor() {
	m_session->saveAs(m_fileName);

	return "SaveAs was successful";
}
