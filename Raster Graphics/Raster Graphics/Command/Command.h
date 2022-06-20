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
	virtual std::string execute() = 0;

	static size_t getNumberOfArgs();

private:
	static const size_t nArgs = 0;
};
