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
	readRowsAndColsFromFileAndResizePixels(file);
	m_pixels.readFromFile(file);
}

void PBMImage::writeToFile(std::ofstream& file) {
	writeMagicNumberToFile(file);
	writeRowsAndColsToFile(file);
	m_pixels.writeToFile(file);
}

void PBMImage::rotate(std::string direction) {
	m_previousVersion = clone();

	ImageUtilities<std::uint16_t>::rotatePixels(direction, m_pixels);
}

void PBMImage::grayscale() {
	throw ImageException("Monochrome Images cannot be grayscaled!");
}

void PBMImage::monochrome() {
	throw ImageException("Cannot convert Monochrome image to monochrome");
}

void PBMImage::negative() {
	m_previousVersion = clone();

	ImageUtilities<std::uint16_t>::negativeTransformation(m_pixels, m_maxColorValue);
}

void PBMImage::setPixels(const Matrix<std::uint16_t>& matrix) {
	m_pixels = matrix;
}

Matrix<std::uint16_t> PBMImage::getPixels() const {
	return m_pixels;
}

void PBMImage::readRowsAndColsFromFileAndResizePixels(std::ifstream& file) {
	ImageUtilities<std::uint16_t>::readParamsToResizeMatrixFromFile(file, m_pixels);
}

void PBMImage::writeRowsAndColsToFile(std::ofstream& file) const {
	ImageUtilities<std::uint16_t>::writePixelsRowsAndColsToFile(file, m_pixels);
}

void PBMImage::copy(Image* image) {
	PBMImage* pbm = dynamic_cast<PBMImage*>(image);

	if (pbm == nullptr)
		throw ImageException("Trying to copy incorrect image type");

	m_pixels = pbm->m_pixels;

	Image::copy(image);
}
