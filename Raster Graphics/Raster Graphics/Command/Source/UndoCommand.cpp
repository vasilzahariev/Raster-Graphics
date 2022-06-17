#include "../UndoCommand.h"

UndoCommand::UndoCommand(Session* const session)
	: m_session(session) {
}

std::string UndoCommand::execute() {
	std::string output = "";
	
	try {
		m_session->undo();
		
		output = "Undo was successful";
	}
	catch (std::exception err) {
		output = err.what();
	}

	return output;
}
