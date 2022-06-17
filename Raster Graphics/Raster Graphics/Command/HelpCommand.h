#pragma once

#include <iostream>
#include "Command.h"

class HelpCommand : public Command {
public:
	std::string execute() override;
};
