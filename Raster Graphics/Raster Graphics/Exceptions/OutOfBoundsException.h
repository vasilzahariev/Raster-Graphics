#ifndef OUTOFBOUNDSEXCEPTION
#define OUTOFBOUNDSEXCEPTION

#include <iostream>

class OutOfBoundsException : std::exception {
public:
	OutOfBoundsException(std::string_view message = "Index out of bounds");

	const char* what() const noexcept override final;

private:
	std::string m_message;
};

#endif // !OUTOFBOUNDSEXCEPTION
