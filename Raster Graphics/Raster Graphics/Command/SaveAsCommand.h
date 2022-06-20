#pragma once

#include "../Session/Session.h"
#include "Command.h"

class SaveAsCommand : public Command {
public:
	SaveAsCommand(Session* const session, std::string_view fileName);

	static size_t getNumberOfArgs();

	std::string execute() override;

private:
	Session* const m_session;
	std::string m_fileName;

	static const size_t nArgs = 1;
};
