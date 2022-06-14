#include "../CommandException.h"

CommandException::CommandException(const std::string& message)
	: m_message(message) {
}

const char* CommandException::what() const noexcept {
	return m_message.c_str();
}
