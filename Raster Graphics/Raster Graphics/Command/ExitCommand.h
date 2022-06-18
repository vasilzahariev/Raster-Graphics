#pragma once

#include "Command.h"

class ExitCommand : public Command {
public:
	std::string execute();
};
