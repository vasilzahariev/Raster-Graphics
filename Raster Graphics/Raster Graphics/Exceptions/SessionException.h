#pragma once

#include <iostream>
#include <string>

class SessionException : public std::exception {
public:
	SessionException(const std::string& message);

	const char* what() const noexcept override final;

private:
	std::string m_message;
};
