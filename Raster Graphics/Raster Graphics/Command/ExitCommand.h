#pragma once

#include "Command.h"

class ExitCommand : public Command {
protected:
	std::string executor() override;
};
