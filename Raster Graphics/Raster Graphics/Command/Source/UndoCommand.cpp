#include "../UndoCommand.h"

UndoCommand::UndoCommand(Session* const session)
	: m_session(session) {
}

size_t UndoCommand::getNumberOfArgs() {
	return nArgs;
}

std::string UndoCommand::execute() {
	m_session->undo();

	return "Undo was successful";
}
