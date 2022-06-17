#include "../SessionException.h"

SessionException::SessionException(const std::string& message)
	: m_message(message) {
}

const char* SessionException::what() const noexcept {
	return m_message.c_str();
}
