#pragma once

#include <iostream>
#include "Command.h"

class HelpCommand : public Command {
public:
	static size_t getNumberOfArgs();

	std::string execute() override;
protected:

	static const size_t nArgs = 0;
};
