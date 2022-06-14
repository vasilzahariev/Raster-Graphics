#include "../Image.h"

Image::Image(std::string_view fileName, const bool grayscale, const bool monochrome, const std::uint16_t maxColorValue)
	: m_fileName(fileName), bGrayscale(grayscale), bMonochrome(monochrome), m_maxColorValue(maxColorValue) {
}

std::string_view Image::getFileName() const {
	return m_fileName;
}

bool Image::isGrayscale() const {
	return bGrayscale;
}

bool Image::isMonochrome() const {
	return bMonochrome;
}

void Image::readMagicNumberFromFile(std::ifstream& file) {
	file.ignore();
	file >> m_magicNumber;
}

void Image::readCommentsFromFile(std::ifstream& file) {
	std::string line = "";

	while (file.peek() == '#')
		readCommentLineFromFile(file, line);
}

void Image::readCommentLineFromFile(std::ifstream& file, std::string& line) {
	std::getline(file, line);

	m_comments.push_back(line);
}

void Image::readMaxColorValueFromFile(std::ifstream& file) {
	file >> m_maxColorValue;
}

void Image::writeMagicNumberToFile(std::ofstream& file) const {
	file << 'P' << m_magicNumber << '\n';
}

void Image::writeCommentsToFile(std::ofstream& file) const {
	for (std::vector<std::string>::const_iterator commentIt = m_comments.begin(); commentIt != m_comments.end(); ++commentIt)
		writeCommentLineToFile(file, *commentIt);
}

void Image::writeCommentLineToFile(std::ofstream& file, std::string_view comment) const {
	file << comment;
}

void Image::writeMaxColorValue(std::ofstream& file) const {
	file << m_maxColorValue << '\n';
}
