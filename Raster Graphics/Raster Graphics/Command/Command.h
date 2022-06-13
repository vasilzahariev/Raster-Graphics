#ifndef COMMAND_H

#include "../Interfaces/ICloneable.h"

class Command : ICloneable {
public:
	virtual void execute() = 0;

	// TODO: CHECK: virtual Command* clone() const = 0;

};

#endif // !COMMAND_H
