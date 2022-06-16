#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "Command.h"
#include "../Session/Session.h"

class SaveCommand : public Command {
public:
	SaveCommand(Session* const session);

	void execute() override;

	Command* clone() override;

private:
	Session* const m_session;
};

#endif // !SAVECOMMAND_H
