#include "../UndoCommand.h"

UndoCommand::UndoCommand(Session* const session)
	: m_session(session) {
}

std::string UndoCommand::executor() {
	m_session->undo();

	return "Undo was successful";
}
