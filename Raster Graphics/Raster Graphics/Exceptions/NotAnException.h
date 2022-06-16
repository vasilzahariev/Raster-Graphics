#ifndef NOTANEXCEPTION_H
#define NOTANEXCEPTION_H

#include <iostream>
#include <string>

class NotAnException : public std::exception {
public:
	NotAnException(const std::string& message);

	const char* what() const noexcept override final;

private:
	std::string m_message;
};

#endif // !NOTANEXCEPTION_H
