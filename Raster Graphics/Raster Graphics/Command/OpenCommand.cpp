#include "OpenCommand.h"

OpenCommand::OpenCommand(Image* const image, std::string_view fileLocation)
				: m_image(image), m_fileLocation(fileLocation) {
}

void OpenCommand::execute() {
	*m_image = Image();
}
