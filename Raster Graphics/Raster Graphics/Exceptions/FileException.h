#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H

#include <iostream>
#include <string>
#include <string_view>

class FileException : public std::exception {
public:
	FileException(std::string_view message);

	const char* what() const noexcept override final;

private:
	std::string m_message;
};

#endif // !FILEEXCEPTION_H
