#pragma once

#include <string_view>

#include "Command.h"
#include "../Session/Session.h"

class RotateCommand : public Command {
public:
	RotateCommand(Session* const session, std::string_view direction);

	static size_t getNumberOfArgs();

	std::string execute() override;

private:
	Session* const m_session;
	std::string m_direction;

	static const size_t nArgs = 1;
};
