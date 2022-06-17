#include "../OpenCommand.h"

OpenCommand::OpenCommand(SessionMaster* const sessionMaster, std::string_view fileLocation)
	: m_sessionMaster(sessionMaster), m_fileLocation(fileLocation) {
}

std::string OpenCommand::execute() {
	std::ifstream file(m_fileLocation);

	if (!file.is_open())
		throw FileException("File \"" + m_fileLocation + "\" didn't open correctly");

	m_sessionMaster->addSession(Session());

	Image* image = ImageFactory::createImage(m_fileLocation);

	if (image == nullptr)
		throw ImageException("Image creation failed");

	image->readFromFile(file);

	m_sessionMaster->getActiveSession()->addImage(image);

	file.close();// TODO: Add try catch and return the proper message
}
