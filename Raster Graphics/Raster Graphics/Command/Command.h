#ifndef COMMAND_H

#include <string>

#include "../Interfaces/ICloneable.h"

class Command : public ICloneable {
public:
	virtual void execute() = 0;

	virtual Command* clone() = 0;
};

#endif // !COMMAND_H
