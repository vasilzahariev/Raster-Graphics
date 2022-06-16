#include "../PBMImage.h"

PBMImage::PBMImage(std::string_view fileName)
	: Image(fileName, false, true, MAX_COLOR_VALUE) {
}

PBMImage::PBMImage(const PBMImage& other)
	: Image(other), m_pixels(other.m_pixels) {
}

PBMImage* PBMImage::clone() {
	return new PBMImage(*this);
}

void PBMImage::readFromFile(std::ifstream& file) {
	readMagicNumberFromFile(file);
	readCommentsFromFile(file);
	readRowsAndColsFromFileAndResizePixels(file);
	m_pixels.readFromFile(file);
}

void PBMImage::writeToFile(std::ofstream& file) {
	writeMagicNumberToFile(file);
	writeCommentsToFile(file);
	writeRowsAndColsToFile(file);
	m_pixels.writeToFile(file);

	clearPreviousVersions();
}

void PBMImage::rotate(std::string direction) {
	m_previousVersion = clone();
	std::transform(direction.begin(), direction.end(), direction.begin(), [](unsigned char c) { return std::tolower(c); });

	TODO: if (direction == "left")
		m_pixels.rotateLeft();
	else if (direction == "right")
		m_pixels.rotateRight();
	else
		throw std::logic_error("Direction should either be left or right");
}

void PBMImage::readRowsAndColsFromFileAndResizePixels(std::ifstream& file) {
	size_t rows;
	size_t cols;

	file >> rows >> cols;

	m_pixels.resize(rows, cols);
}

void PBMImage::writeRowsAndColsToFile(std::ofstream& file) const {
	file << m_pixels.getRows() << ' ' << m_pixels.getCols() << '\n';
}
