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

	ImageUtilities<std::uint16_t>::rotatePixels(direction, m_pixels);
}

void PBMImage::grayscale() {
	throw ImageException("Monochrome Images cannot be grayscaled!");
}

void PBMImage::readRowsAndColsFromFileAndResizePixels(std::ifstream& file) {
	ImageUtilities<std::uint16_t>::readParamsToResizeMatrixFromFile(file, m_pixels);
}

void PBMImage::writeRowsAndColsToFile(std::ofstream& file) const {
	ImageUtilities<std::uint16_t>::writePixelsRowsAndColsToFile(file, m_pixels);
}

void PBMImage::copy(Image* const image) {
	Image::copy(image);

	PBMImage* pbm = dynamic_cast<PBMImage*>(image);

	if (pbm == nullptr)
		throw ImageException("Incorrect image type");

	m_pixels = pbm->m_pixels;

	// TODO: Check when you should delete image;
}
