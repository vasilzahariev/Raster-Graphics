#pragma once

#include "Command.h"
#include "../Session/SessionMaster.h"

class SwitchCommand : public Command {
public:
	SwitchCommand(SessionMaster* const sessionMaster, const int id);

	static size_t getNumberOfArgs();

	std::string execute() override;

private:
	SessionMaster* const m_sessionMaster;
	int m_id;

	static const size_t nArgs = 1;
};
