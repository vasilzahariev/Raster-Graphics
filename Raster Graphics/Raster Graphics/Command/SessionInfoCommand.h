#pragma once

#include "Command.h"
#include "../Session/Session.h"
#include "../Exceptions/SessionException.h"

class SessionInfoCommand : public Command {
public:
	SessionInfoCommand(Session* const session);

	static size_t getNumberOfArgs();

	std::string execute() override;

private:
	Session* const m_session;

	static const size_t nArgs = 1;
};
