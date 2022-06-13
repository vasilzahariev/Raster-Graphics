#include "../OutOfBoundsException.h"

OutOfBoundsException::OutOfBoundsException(std::string_view message)
	: m_message(message) {
}

const char* OutOfBoundsException::what() const noexcept {
	return m_message.c_str();
}
