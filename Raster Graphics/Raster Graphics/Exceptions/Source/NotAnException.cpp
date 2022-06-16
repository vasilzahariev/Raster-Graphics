#include "../NotAnException.h"

NotAnException::NotAnException(const std::string& message)
	: m_message(message) {
}

const char* NotAnException::what() const noexcept {
	return m_message.c_str();
}
