#ifndef IMAGEEXCEPTION_H
#define IMAGEEXCEPTION_H

#include <iostream>
#include <string>
#include <string_view>

class ImageException : public std::exception {
public:
	ImageException(std::string_view message);

	const char* what() const noexcept override final;

private:
	std::string m_message;
};

#endif // !IMAGEEXCEPTION_H
