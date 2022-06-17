#pragma once

#include <iostream>
#include <string>

class OutOfBoundsException : public std::exception {
public:
	OutOfBoundsException(const std::string& message);

	const char* what() const noexcept override final;

private:
	std::string m_message;
};
