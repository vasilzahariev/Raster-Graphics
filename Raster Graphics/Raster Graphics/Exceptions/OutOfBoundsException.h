#ifndef OUTOFBOUNDSEXCEPTION
#define OUTOFBOUNDSEXCEPTION

#include <iostream>

class OutOfBoundsException : std::exception {
public:
	OutOfBoundsException(const std::string& message);/*
		: m_message(message) {
	}*/

	const char* what() const noexcept override final;/* {
		return (const char*) m_message.c_str();
	}*/

private:
	std::string m_message;
};

#endif // !OUTOFBOUNDSEXCEPTION
