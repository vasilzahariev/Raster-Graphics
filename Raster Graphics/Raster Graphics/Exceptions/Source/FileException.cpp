#include "../FileException.h"

FileException::FileException(std::string_view message)
	: m_message(message) {
}

const char* FileException::what() const noexcept {
	return m_message.c_str();
}
