#ifndef SESSIONINFOCOMMAND_H
#define SESSIONINFOCOMMAND_H

#include "Command.h"
#include "../Session/Session.h"

class SessionInfoCommand : public Command {
public:
	SessionInfoCommand(Session* const session);

	std::string execute() override;

private:
	Session* const m_session;
};

#endif // !SESSIONINFOCOMMAND_H
