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
	readCommentsFromFile(file);
	readRowsAndColsFromFileAndResizePixels(file);
	readMaxColorValueFromFile(file);
	m_pixels.readFromFile(file);
}

void PGMImage::writeToFile(std::ofstream& file) {
	writeMagicNumberToFile(file);
	writeCommentsToFile(file);
	writeRowsAndColsToFile(file);
	writeMaxColorValue(file);
	m_pixels.writeToFile(file);

	clearPreviousVersions();
}

void PGMImage::rotate(std::string direction) {
	m_previousVersion = clone();

	ImageUtilities<std::uint16_t>::rotatePixels(direction, m_pixels);
}

void PGMImage::readRowsAndColsFromFileAndResizePixels(std::ifstream& file) {
	ImageUtilities<std::uint16_t>::readParamsToResizeMatrixFromFile(file, m_pixels);
}

void PGMImage::writeRowsAndColsToFile(std::ofstream& file) const {
	ImageUtilities<std::uint16_t>::writePixelsRowsAndColsToFile(file, m_pixels);
}

void PGMImage::copy(Image* const image) {
	Image::copy(image);

	PGMImage* pgm = dynamic_cast<PGMImage*>(image);

	if (pgm == nullptr)
		throw ImageException("Incorrect image type");

	m_pixels = pgm->m_pixels;

	// TODO: Check when you should delete image;
}
