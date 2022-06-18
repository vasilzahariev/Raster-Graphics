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
	//m_previousVersion = clone(); // TODO: Do something about the previousVersions

	ImageUtilities<std::uint16_t>::rotatePixels(direction, m_pixels);
}

void PBMImage::grayscale() {
	throw ImageException("Monochrome Images cannot be grayscaled!");
}

void PBMImage::monochrome() {
	throw ImageException("Cannot convert Monochrome image to monochrome");
}

void PBMImage::negative() {
	for (size_t row = 0; row < m_pixels.getRows(); ++row) {
		for (size_t col = 0; col < m_pixels.getCols(); ++col) {
			std::uint16_t& pixel = m_pixels.getElementAt(row, col);

			pixel = m_maxColorValue - pixel;
		}
	}
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
