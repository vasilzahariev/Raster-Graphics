#pragma once

#include "Command.h"
#include "../Session/Session.h"

class SessionInfoCommand : public Command {
public:
	SessionInfoCommand(Session* const session);

	std::string execute() override;

private:
	Session* const m_session;
};
