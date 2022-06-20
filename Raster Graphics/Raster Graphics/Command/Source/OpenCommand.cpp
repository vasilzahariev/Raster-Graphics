#include "../OpenCommand.h"


OpenCommand::OpenCommand(SessionMaster* const sessionMaster, std::string_view fileLocation)
	: m_sessionMaster(sessionMaster), m_fileLocation(fileLocation) {
}

size_t OpenCommand::getNumberOfArgs() {
	return nArgs;
}

std::string OpenCommand::execute() {
	if (m_sessionMaster->checkIfFileAlreadyExists(m_fileLocation))
		throw CommandException("File is already open");

	std::ifstream file(m_fileLocation);

	if (!file.is_open())
		throw FileException("File \"" + m_fileLocation + "\" didn't open correctly");

	Image* image = ImageFactory::createImage(m_fileLocation);

	if (image == nullptr)
		throw ImageException("Image creation failed");


	image->readFromFile(file);

	m_sessionMaster->addSession(Session());
	m_sessionMaster->getActiveSession()->addImage(image);

	file.close();

	return "Session with ID: " + std::to_string(m_sessionMaster->getActiveSession()->getId()) + " was created successfuly. File was also added successfuly";

}
