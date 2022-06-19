#pragma once

#include <iostream>
#include "Command.h"

class HelpCommand : public Command {
protected:
	std::string executor() override;
};
