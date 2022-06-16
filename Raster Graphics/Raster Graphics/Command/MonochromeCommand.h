#ifndef MONOCHROMECOMMAND_H
#define MONOCHROMECOMMAND_H

#include "Command.h"
#include "../Session/Session.h"

class MonochromeCommand : public Command {
public:
	MonochromeCommand(Session* const session);

	std::string execute() override;

private:
	Session* const m_session;
};

#endif // !MONOCHROMECOMMAND_H
