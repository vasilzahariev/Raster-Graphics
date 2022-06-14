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
	for (size_t index = 0; index < m_images.size(); ++index) {
		if (!m_images[index]->isGrayscale() && !m_images[index]->isMonochrome()) {
			// TODO: m_images[index]->grayscale();
		}
	}
}

void Session::addImage(Image* image) {
	m_images.push_back(image);
}
