#pragma once

#include "Command.h"
#include "../Session/SessionMaster.h"

class SwitchCommand : public Command {
public:
	SwitchCommand(SessionMaster* const sessionMaster, const int id);

protected:
	std::string executor() override;

private:
	SessionMaster* const m_sessionMaster;
	int m_id;
};
