#include "../Session.h"

int Session::sIdCounter = 0;

Session::Session()
	: nId(++sIdCounter) {
}

int Session::getId() const {
	return nId;
}

void Session::grayscale() {
	// Create Iterators for the vector
	for (size_t index = 0; index < m_images.size(); ++index)
		if (!m_images[index]->isGrayscale() && !m_images[index]->isMonochrome())
			m_images[index]->grayscale();

	m_unsavedChanges.push_back("grayscale");
}

void Session::addImage(Image* image) {
	m_images.push_back(image);
}

void Session::rotate(std::string& direction) {
	for (size_t index = 0; index < m_images.size(); ++index)
		m_images[index]->rotate(direction);

	m_unsavedChanges.push_back("rotate" + direction);
}

void Session::monochrome() {
	for (size_t index = 0; index < m_images.size(); ++index) {
		if (!m_images[index]->isMonochrome()) {
			m_images[index]->monochrome();
		}
	}

	m_unsavedChanges.push_back("monochrome");
}

void Session::saveChanges() {
	// TODO: PolymorphicIterator
	for (size_t index = 0; index < m_images.size(); ++index) {
		saveImageToFile(m_images[index], m_images[index]->getFileName());
	}

	m_unsavedChanges.clear();
}

void Session::negative() {
	for (size_t index = 0; index < m_images.size(); ++index) {
		m_images[index]->negative();
	}

	m_unsavedChanges.push_back("negative");
}

void Session::saveAs(const std::string& fileName) {
	saveImageToFile(m_images[0], fileName);
}

void Session::close() {
	// TODO: PolymorphicIterator

	for (size_t index = 0; index < m_images.size(); ++index) {
		m_images[index]->removeUnsavedChanges();
	}
}

void Session::undo() {
	for (size_t index = m_images.size() - 1; index >= 0; --index)
		m_images[index]->undo();

	m_unsavedChanges.pop_back();
}

void Session::saveImageToFile(Image* image, const std::string& fileName) {
	std::ofstream file(fileName);

	image->writeToFile(file);
}

std::string Session::info(std::ostream& out) const {
	std::string infoStr = "";

	infoStr += "Session ID: " + std::to_string(nId) + '\n';

	infoStr += "Names of images in the session: ";
	for (size_t index = 0; index < m_images.size(); ++index)
		infoStr += m_images[index]->getFileName() + ' ';
	infoStr += '\n';

	infoStr += "Pending transformations: ";
	for (std::vector<std::string>::const_iterator unsavedChange = m_unsavedChanges.begin(); unsavedChange != m_unsavedChanges.end(); ++unsavedChange)
		infoStr += *unsavedChange + ' ';
	infoStr += '\n';

	return infoStr;
}
