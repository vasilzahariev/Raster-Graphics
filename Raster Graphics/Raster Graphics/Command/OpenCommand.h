#ifndef OPENCOMMAND_H
#define OPENCOMMAND_H

#include <string>
#include <string_view>

#include "Command.h"
#include "../Image/Image.h"

class OpenCommand : Command {
public:
	OpenCommand(Image* const image, std::string_view fileLocation);

	void execute() override;

private:
	std::string m_fileLocation;
	Image* const m_image;
};

#endif // !OPENCOMMAND_H
