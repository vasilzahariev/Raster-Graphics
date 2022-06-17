#pragma once

#include "../Session/Session.h"
#include "Command.h"

class SaveAsCommand : public Command {
public:
	SaveAsCommand(Session* const session, std::string_view fileName);

	std::string execute() override;

private:
	Session* const m_session;
	std::string m_fileName;
};
