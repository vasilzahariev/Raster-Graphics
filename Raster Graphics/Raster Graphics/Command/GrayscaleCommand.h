#pragma once

#include "Command.h"
#include "../Session/Session.h"

class GrayscaleCommand : public Command {
public:
	GrayscaleCommand(Session* const session);

protected:
	std::string executor() override;

private:
	Session* const m_session;
};
