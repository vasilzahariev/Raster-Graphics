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
}

void Session::addImage(Image* image) {
	m_images.push_back(image);
}

void Session::rotate(std::string& direction) {
	for (size_t index = 0; index < m_images.size(); ++index)
		m_images[index]->rotate(direction);
}

void Session::saveChanges() {
	// TODO: PolymorphicIterator
	for (size_t index = 0; index < m_images.size(); ++index) {
		saveImageToFile(m_images[index], m_images[index]->getFileName());
	}
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
	for (size_t index = 0; index < m_images.size(); ++index)
		m_images[index]->undo();
}

void Session::saveImageToFile(Image* image, const std::string& fileName) {
	std::ofstream file(fileName);

	image->writeToFile(file);
}
