#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H

#include <iostream>
#include "Command.h"

class HelpCommand : public Command {
public:
	void execute() override;
};

#endif // !HELPCOMMAND_H