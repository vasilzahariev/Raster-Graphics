#include "../NegativeCommand.h"

NegativeCommand::NegativeCommand(Session* const session)
	: m_session(session) {
}

std::string NegativeCommand::execute() {
	std::string output = "";

	try {
		m_session->negative();
		
		output = "Negative was successful";
	}
	catch (std::exception err) {
		output = err.what();
	}

	return output;
}
