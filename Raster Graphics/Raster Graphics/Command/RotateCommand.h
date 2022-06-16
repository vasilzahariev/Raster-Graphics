#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include <string_view>

#include "Command.h"
#include "../Session/Session.h"

class RotateCommand : public Command {
public:
	RotateCommand(Session* const session, std::string_view direction);

	void execute() override;

	RotateCommand* clone() override;

private:
	Session* const m_session;
	std::string m_direction;
};

#endif // !ROTATECOMMAND_H
