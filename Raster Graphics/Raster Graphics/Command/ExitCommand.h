#pragma once

#include "Command.h"

class ExitCommand : public Command {
public:
	static size_t getNumberOfArgs();

	std::string execute() override;

protected:
	static const size_t nArgs = 0;
};
