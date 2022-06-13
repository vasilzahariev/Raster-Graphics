#include "../PBMImage.h"

PBMImage::PBMImage(std::string_view fileName)
	: Image(fileName) {
	m_maxColorValue = MAX_COLOR_VALUE;
}

PBMImage* PBMImage::clone() const {
	return new PBMImage(m_fileName);
}

void PBMImage::readFromFile(std::ifstream& file) {
	readMagicNumberFromFile(file);
	readCommentsFromFile(file);
	readRowsAndColsFromFileAndResizePixels(file);
	//TODO: m_pixels.readFromFile(file);
}

void PBMImage::writeToFile(std::ofstream& file) const {
	writeMagicNumberToFile(file);
	writeCommentsToFile(file);
	writeRowsAndColsToFile(file);
	//TODO: m_pixels.writeToFile(file);
}

/*
* Някъде добави това:
* std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });
*/
void PBMImage::rotate(std::string_view direction) {
	//TODO: if (direction == "left")
	//	m_pixels.rotateLeft();
	//else if (direction == "right")
	//	m_pixels.rotateRight();
	//else
	//	throw std::logic_error("Direction should either be left or right");
}

void PBMImage::readRowsAndColsFromFileAndResizePixels(std::ifstream& file) {
	size_t rows;
	size_t cols;

	file >> rows >> cols;

	// TODO: m_pixels.resize(rows, cols);
}

void PBMImage::writeRowsAndColsToFile(std::ofstream& file) const {
	file << m_pixels.getRows() << ' ' << m_pixels.getCols() << '\n';
}
