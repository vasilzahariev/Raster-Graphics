#ifndef SESSIONEXCEPTION_H
#define SESSIONEXCEPTION_H

#include <iostream>
#include <string>
#include <string_view>

class SessionException : public std::exception {
public:
	SessionException(std::string_view message);

	const char* what() const noexcept override final;

private:
	std::string m_message;
};

#endif // !SESSIONEXCEPTION_H
