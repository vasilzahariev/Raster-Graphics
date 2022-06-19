#pragma once

#include "Command.h"
#include "../Session/Session.h"
#include "../Exceptions/SessionException.h"

class SessionInfoCommand : public Command {
public:
	SessionInfoCommand(Session* const session);

protected:
	std::string executor() override;

private:
	Session* const m_session;
};
