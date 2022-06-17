#include "../ImageException.h"

ImageException::ImageException(const std::string& message)
	:m_message(message) {
}

const char* ImageException::what() const noexcept {
	return m_message.c_str();
}
