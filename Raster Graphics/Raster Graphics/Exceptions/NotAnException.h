#pragma once

#include <iostream>
#include <string>

class NotAnException : public std::exception {
public:
	NotAnException(const std::string& message);

	const char* what() const noexcept override final;

private:
	std::string m_message;
};
