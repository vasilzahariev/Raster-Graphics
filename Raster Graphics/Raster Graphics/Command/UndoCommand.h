#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H

#include "Command.h"
#include "../Session/Session.h"

class UndoCommand : public Command {
public:
	UndoCommand(Session* const session);

	std::string execute() override;

private:
	Session* const m_session;
};

#endif // !UNDOCOMMAND_H
