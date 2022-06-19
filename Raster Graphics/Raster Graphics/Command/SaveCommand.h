#pragma once

#include "Command.h"
#include "../Session/Session.h"

class SaveCommand : public Command {
public:
	SaveCommand(Session* const session);

protected:
	std::string executor() override;

private:
	Session* const m_session;
};
