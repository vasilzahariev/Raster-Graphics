#include "../AddCommand.h"

AddCommand::AddCommand(SessionMaster* const sessionMaster, Session* const session, std::string_view fileLocation)
	: m_sessionMaster(sessionMaster), m_session(session), m_fileLocation(fileLocation) {
}

size_t AddCommand::getNumberOfArgs() {
	return nArgs;
}

std::string AddCommand::execute() {
	if (m_sessionMaster->checkIfFileAlreadyExists(m_fileLocation))
		throw CommandException("File is already open");

	std::ifstream file(m_fileLocation);

	if (!file.is_open())
		throw FileException("File \"" + m_fileLocation + "\" didn't open correctly");

	Image* image = ImageFactory::createImage(m_fileLocation);

	m_session->addImage(image);

	if (image == nullptr)
		throw ImageException("Image creation failed");

	image->readFromFile(file);

	file.close();

	return "Image \"" + m_fileLocation + "\" added";
}
