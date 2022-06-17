#include "../SaveAsCommand.h"

SaveAsCommand::SaveAsCommand(Session* const session, std::string_view fileName)
	: m_session(session), m_fileName(fileName) {
}

std::string SaveAsCommand::execute() {
	std::string output = "";

	try {
		m_session->saveAs(m_fileName);
		
		output = "SaveAs was successful";
	}
	catch (std::exception err) {
		output = err.what();
	}

	return output;
}
