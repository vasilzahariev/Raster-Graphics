#include "../OutOfBoundsException.h"

OutOfBoundsException::OutOfBoundsException(const std::string& message)
	: m_message(message) {
}

const char* OutOfBoundsException::what() const noexcept {
	return (const char*) m_message.c_str();
}
