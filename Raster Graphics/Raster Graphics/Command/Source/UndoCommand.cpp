#include "../UndoCommand.h"

UndoCommand::UndoCommand(Session* const session)
	: m_session(session) {
}

std::string UndoCommand::execute() {
	m_session->undo(); // TODO: Add try catch and return the proper message
}
