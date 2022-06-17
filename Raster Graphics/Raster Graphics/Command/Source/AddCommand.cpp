#include "../AddCommand.h"

AddCommand::AddCommand(Session* const session, std::string_view fileLocation)
	: m_session(session), m_fileLocation(fileLocation) {
}

std::string AddCommand::execute() {
	std::string output = "";
	
	try {
		std::ifstream file(m_fileLocation);

		if (!file.is_open())
			throw FileException("File \"" + m_fileLocation + "\" didn't open correctly");

		Image* image = ImageFactory::createImage(m_fileLocation);

		m_session->addImage(image);

		if (image == nullptr)
			throw ImageException("Image creation failed");

		image->readFromFile(file);

		file.close();

		output = "Image \"" + m_fileLocation + "\" added";
	}
	catch (std::exception err) {
		output = err.what();
	}
	
	return output;
}
