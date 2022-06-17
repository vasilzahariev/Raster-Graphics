#pragma once

#include <iostream>
#include <string>

class CommandException : public std::exception {
public:
	CommandException(const std::string& message);

	const char* what() const noexcept override final;

private:
	std::string m_message;
};
