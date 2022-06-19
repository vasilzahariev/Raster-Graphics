#pragma once

#include "Command.h"
#include "../Session/Session.h"

class NegativeCommand : public Command {
public:
	NegativeCommand(Session* const session);

protected:
	std::string executor() override;

private:
	Session* const m_session;
};
