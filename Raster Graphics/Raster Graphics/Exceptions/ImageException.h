#pragma once

#include <iostream>
#include <string>

class ImageException : public std::exception {
public:
	ImageException(const std::string& message);

	const char* what() const noexcept override final;

private:
	std::string m_message;
};
