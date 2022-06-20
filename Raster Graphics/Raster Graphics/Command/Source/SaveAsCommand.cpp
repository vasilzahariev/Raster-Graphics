#include "../SaveAsCommand.h"

SaveAsCommand::SaveAsCommand(Session* const session, std::string_view fileName)
	: m_session(session), m_fileName(fileName) {
}

size_t SaveAsCommand::getNumberOfArgs() {
	return nArgs;
}

std::string SaveAsCommand::execute() {
	m_session->saveAs(m_fileName);

	return "SaveAs was successful";
}
