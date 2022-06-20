#include "../PGMImage.h"

PGMImage::PGMImage(std::string_view fileName)
	: Image(fileName, true, false, 1) {
	//
}

PGMImage::PGMImage(const PGMImage& other)
	: Image(other), m_pixels(other.m_pixels) {
	//
}

PGMImage* PGMImage::clone() {
	return new PGMImage(*this);
}

void PGMImage::readFromFile(std::ifstream& file) {
	readMagicNumberFromFile(file);
	readRowsAndColsFromFileAndResizePixels(file);
	readMaxColorValueFromFile(file);
	m_pixels.readFromFile(file);
}

void PGMImage::writeToFile(std::ofstream& file) {
	writeMagicNumberToFile(file);
	writeRowsAndColsToFile(file);
	writeMaxColorValue(file);
	m_pixels.writeToFile(file);

	clearPreviousVersions();
}

void PGMImage::rotate(std::string direction) {
	m_previousVersion = clone();

	ImageUtilities<std::uint16_t>::rotatePixels(direction, m_pixels);
}

void PGMImage::grayscale() {
	throw ImageException("Grayscale Image cannot be converted into grayscale");
}

void PGMImage::monochrome() {
	m_previousVersion = clone();

	for (size_t row = 0; row < m_pixels.getRows(); ++row)
		for (size_t col = 0; col < m_pixels.getCols(); ++col)
			m_pixels.getElementAt(row, col) = m_maxColorValue * std::round((double)m_pixels.getElementAt(row, col) / m_maxColorValue);
}

void PGMImage::negative() {
	m_previousVersion = clone();

	ImageUtilities<std::uint16_t>::negativeTransformation(m_pixels, m_maxColorValue);
}

void PGMImage::setPixels(const Matrix<std::uint16_t>& matrix) {
	m_pixels = matrix;
}

Matrix<std::uint16_t> PGMImage::getPixels() const {
	return m_pixels;
}

void PGMImage::readRowsAndColsFromFileAndResizePixels(std::ifstream& file) {
	ImageUtilities<std::uint16_t>::readParamsToResizeMatrixFromFile(file, m_pixels);
}

void PGMImage::writeRowsAndColsToFile(std::ofstream& file) const {
	ImageUtilities<std::uint16_t>::writePixelsRowsAndColsToFile(file, m_pixels);
}

void PGMImage::copy(Image* image) {
	PGMImage* pgm = dynamic_cast<PGMImage*>(image);

	if (pgm == nullptr)
		throw ImageException("Incorrect image type");

	m_pixels = pgm->m_pixels;

	Image::copy(image);
}
