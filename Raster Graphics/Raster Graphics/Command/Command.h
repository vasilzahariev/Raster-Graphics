#ifndef COMMAND_H

#include "../Interfaces/ICloneable.h"

// TODO: Add ICloneable
class Command {
public:
	virtual void execute() = 0;

	// TODO: CHECK: virtual Command* clone() const = 0;

};

#endif // !COMMAND_H
