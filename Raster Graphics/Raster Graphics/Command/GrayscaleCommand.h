#pragma once

#include "Command.h"
#include "../Session/Session.h"

class GrayscaleCommand : public Command {
public:
	GrayscaleCommand(Session* const session);

	static size_t getNumberOfArgs();

	std::string execute() override;

private:
	Session* const m_session;

	static const size_t nArgs = 0;
};
