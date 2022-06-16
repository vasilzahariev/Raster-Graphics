#include "../UndoCommand.h"

UndoCommand::UndoCommand(Session* const session)
	: m_session(session) {
}

void UndoCommand::execute() {
	m_session->undo();
}

UndoCommand* UndoCommand::clone() {
	return new UndoCommand(m_session);
}
