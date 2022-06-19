#pragma once

#include "Command.h"
#include "../Session/Session.h"
#include "../Session/SessionMaster.h"

class CloseCommand : public Command {
public:
	CloseCommand(SessionMaster* const sessionMaster);

protected:
	std::string executor() override;

private:
	SessionMaster* const m_sessionMaster;
};
