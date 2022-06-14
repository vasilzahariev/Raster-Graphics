#include "../ImageException.h"

ImageException::ImageException(std::string_view message)
	:m_message(message) {
}

const char* ImageException::what() const noexcept {
	return m_message.c_str();
}
