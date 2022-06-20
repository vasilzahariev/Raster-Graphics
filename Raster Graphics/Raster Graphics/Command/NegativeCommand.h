#pragma once

#include "Command.h"
#include "../Session/Session.h"

class NegativeCommand : public Command {
public:
	NegativeCommand(Session* const session);

	static size_t getNumberOfArgs();

	std::string execute() override;

private:
	Session* const m_session;

	static const size_t nArgs = 0;
};
