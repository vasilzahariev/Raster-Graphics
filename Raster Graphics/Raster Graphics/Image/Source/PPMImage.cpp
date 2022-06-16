#include "../PPMImage.h"

PPMImage::PPMImage(std::string_view fileName)
	: Image(fileName, true, false, 1) {
	//
}

PPMImage::PPMImage(const PPMImage& other)
	: Image(other), m_pixels(other.m_pixels) {
	//
}

PPMImage* PPMImage::clone() {
	return new PPMImage(*this);
}

void PPMImage::readFromFile(std::ifstream& file) {
	readMagicNumberFromFile(file);
	readCommentsFromFile(file);
	readRowsAndColsFromFileAndResizePixels(file);
	readMaxColorValueFromFile(file);
	m_pixels.readFromFile(file);
}

void PPMImage::writeToFile(std::ofstream& file) {
	writeMagicNumberToFile(file);
	writeCommentsToFile(file);
	writeRowsAndColsToFile(file);
	writeMaxColorValue(file);
	m_pixels.writeToFile(file);

	clearPreviousVersions();
}

void PPMImage::rotate(std::string direction) {
	m_previousVersion = clone();

	ImageUtilities<Vector3<std::uint16_t>>::rotatePixels(direction, m_pixels);
}

void PPMImage::readRowsAndColsFromFileAndResizePixels(std::ifstream& file) {
	ImageUtilities<Vector3<std::uint16_t>>::readParamsToResizeMatrixFromFile(file, m_pixels);
}

void PPMImage::writeRowsAndColsToFile(std::ofstream& file) const {
	ImageUtilities<Vector3<std::uint16_t>>::writePixelsRowsAndColsToFile(file, m_pixels);
}

void PPMImage::copy(Image* const image) {
	Image::copy(image);

	PPMImage* ppm = dynamic_cast<PPMImage*>(image);

	if (ppm == nullptr)
		throw ImageException("Incorrect image type");

	m_pixels = ppm->m_pixels;

	// TODO: Check when you should delete image;
}
