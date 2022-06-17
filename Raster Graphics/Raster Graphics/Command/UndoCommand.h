#pragma once

#include "Command.h"
#include "../Session/Session.h"

class UndoCommand : public Command {
public:
	UndoCommand(Session* const session);

	std::string execute() override;

private:
	Session* const m_session;
};
