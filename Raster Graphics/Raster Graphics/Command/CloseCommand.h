#ifndef CLOSECOMMAND_H
#define CLOSECOMMAND_H

#include "Command.h"
#include "../Session/Session.h"

class CloseCommand : public Command {
public:
	CloseCommand(Session* const session);

	std::string execute() override;

private:
	Session* const m_session;
};

#endif // !CLOSECOMMAND_H
