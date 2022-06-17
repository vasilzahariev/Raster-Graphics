#pragma once

#include <string>

class Command {
public:
	virtual std::string execute() = 0;
};
