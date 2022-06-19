#pragma once

#include "../Session/Session.h"
#include "Command.h"

class SaveAsCommand : public Command {
public:
	SaveAsCommand(Session* const session, std::string_view fileName);

protected:
	std::string executor() override;

private:
	Session* const m_session;
	std::string m_fileName;
};
