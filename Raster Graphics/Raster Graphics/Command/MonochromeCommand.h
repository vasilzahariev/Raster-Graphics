#pragma once

#include "Command.h"
#include "../Session/Session.h"

class MonochromeCommand : public Command {
public:
	MonochromeCommand(Session* const session);

	static size_t getNumberOfArgs();

	std::string execute() override;

private:
	Session* const m_session;

	static const size_t nArgs = 0;
};
