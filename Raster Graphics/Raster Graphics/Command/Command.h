#ifndef COMMAND_H

#include "../Interfaces/ICloneable.h"

class Command {
public:
	virtual void execute() = 0;

};

#endif // !COMMAND_H
