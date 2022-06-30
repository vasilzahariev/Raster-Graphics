#include "../PPMImage.h"

PPMImage::PPMImage(std::string_view fileName)
	: Image(fileName, false, false, 1) {
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
	readRowsAndColsFromFileAndResizePixels(file);
	readMaxColorValueFromFile(file);
	m_pixels.readFromFile(file);
}

void PPMImage::writeToFile(std::ofstream& file) {
	writeMagicNumberToFile(file);
	writeRowsAndColsToFile(file);
	writeMaxColorValue(file);
	m_pixels.writeToFile(file);

	clearPreviousVersions();
}

void PPMImage::rotate(std::string direction) {
	m_previousVersion = clone();

	ImageUtilities<RGBData>::rotatePixels(direction, m_pixels);
}

void PPMImage::grayscale() {
	m_previousVersion = clone();

	for (size_t row = 0; row < m_pixels.getRows(); ++row)
		for (size_t col = 0; col < m_pixels.getCols(); ++col)
			m_pixels.getElementAt(row, col).transformToGrayscale();
}

void PPMImage::monochrome() {
	m_previousVersion = clone();

	for (size_t row = 0; row < m_pixels.getRows(); ++row)
		for (size_t col = 0; col < m_pixels.getCols(); ++col)
			m_pixels.getElementAt(row, col).normalizeByValue(m_maxColorValue);
}

void PPMImage::negative() {
	m_previousVersion = clone();

	ImageUtilities<RGBData>::negativeTransformation(m_pixels, m_maxColorValue);
}

void PPMImage::setPixels(const Matrix<RGBData>& matrix) {
	m_pixels = matrix;
}

Matrix<RGBData> PPMImage::getPixels() const {
	return m_pixels;
}

void PPMImage::readRowsAndColsFromFileAndResizePixels(std::ifstream& file) {
	ImageUtilities<RGBData>::readParamsToResizeMatrixFromFile(file, m_pixels);
}

void PPMImage::writeRowsAndColsToFile(std::ofstream& file) const {
	ImageUtilities<RGBData>::writePixelsRowsAndColsToFile(file, m_pixels);
}

void PPMImage::copy(Image* image) {
	PPMImage* ppm = dynamic_cast<PPMImage*>(image);

	if (ppm == nullptr)
		throw ImageException("Incorrect image type");

	m_pixels = ppm->m_pixels;

	Image::copy(image);
}
