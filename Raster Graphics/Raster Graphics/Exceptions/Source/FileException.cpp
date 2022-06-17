#include "../FileException.h"

FileException::FileException(const std::string& message)
	: m_message(message) {
}

const char* FileException::what() const noexcept {
	return m_message.c_str();
}
