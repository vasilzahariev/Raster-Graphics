#ifndef SAVEASCOMMAND_H
#define SAVEASCOMMAND_H

#include "../Session/Session.h"
#include "Command.h"

class SaveAsCommand : public Command {
public:
	SaveAsCommand(Session* const session, std::string_view fileName);

	void execute() override;

	SaveAsCommand* clone() override;

private:
	Session* const m_session;
	std::string m_fileName;
};

#endif // !SAVEASCOMMAND_H
