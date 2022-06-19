#pragma once

#include <string>
#include "../Exceptions/CommandException.h"
#include "../Exceptions/FileException.h"
#include "../Exceptions/ImageException.h"
#include "../Exceptions/NotAnException.h"
#include "../Exceptions/OutOfBoundsException.h"
#include "../Exceptions/SessionException.h"

class Command {
public:
	std::string execute();

protected:
	virtual std::string executor() = 0;
};
