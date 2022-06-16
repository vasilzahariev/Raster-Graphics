#ifndef GRAYSCALECOMMAND_H
#define GRAYSCALECOMMAND_H

#include "Command.h"
#include "../Session/Session.h"

class GrayscaleCommand : public Command {
public:
	GrayscaleCommand(Session* const session);

	std::string execute() override;

private:
	Session* const m_session;
};

#endif // !GRAYSCALECOMMAND_H
