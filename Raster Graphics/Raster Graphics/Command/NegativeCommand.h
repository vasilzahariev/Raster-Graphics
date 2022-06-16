#ifndef NEGATIVECOMMAND_H
#define NEGATIVECOMMAND_H

#include "Command.h"
#include "../Session/Session.h"

class NegativeCommand : public Command {
public:
	NegativeCommand(Session* const session);

	std::string execute() override;

private:
	Session* const m_session;
};

#endif // !NEGATIVECOMMAND_H
