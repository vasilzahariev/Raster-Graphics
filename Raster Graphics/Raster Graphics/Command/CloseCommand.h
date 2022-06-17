#pragma once

#include "Command.h"
#include "../Session/Session.h"

class CloseCommand : public Command {
public:
	CloseCommand(Session* const session);

	std::string execute() override;

private:
	Session* const m_session;
};
