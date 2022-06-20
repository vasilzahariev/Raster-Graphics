#pragma once

#include "Command.h"
#include "../Session/Session.h"
#include "../Session/SessionMaster.h"

class CloseCommand : public Command {
public:
	CloseCommand(SessionMaster* const sessionMaster);

	static size_t getNumberOfArgs();

	std::string execute() override;

private:
	SessionMaster* const m_sessionMaster;

	static const size_t nArgs = 0;
};
