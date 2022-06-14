#include "../SessionException.h"

SessionException::SessionException(std::string_view message)
	: m_message(message) {
}

const char* SessionException::what() const noexcept {
	return m_message.c_str();
}
