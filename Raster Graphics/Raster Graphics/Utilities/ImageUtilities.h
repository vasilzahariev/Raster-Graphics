#pragma once

#include <fstream>
#include <algorithm>

#include "../ImageData/Matrix.h"

template <typename T>
class ImageUtilities {
public:
	static void readParamsToResizeMatrixFromFile(std::ifstream& file, Matrix<T>& pixels);

	static void rotatePixels(std::string direction, Matrix<T>& pixels);

	static void writePixelsRowsAndColsToFile(std::ofstream& file, const Matrix<T>& pixels);

	static void negativeTransformation(Matrix<T>& pixels, const std::uint16_t value);
};

template<typename T>
inline void ImageUtilities<T>::readParamsToResizeMatrixFromFile(std::ifstream& file, Matrix<T>& pixels) {
	size_t rows;
	size_t cols;

	file >> cols >> rows;

	pixels.resize(rows, cols);
}

template<typename T>
inline void ImageUtilities<T>::rotatePixels(std::string direction, Matrix<T>& pixels) {
	std::transform(direction.begin(), direction.end(), direction.begin(), [](unsigned char c) { return std::tolower(c); });

	if (direction == "left")
		pixels.rotateLeft();
	else if (direction == "right")
		pixels.rotateRight();
	else
		throw std::logic_error("Direction should either be left or right");
}

template<typename T>
inline void ImageUtilities<T>::writePixelsRowsAndColsToFile(std::ofstream& file, const Matrix<T>& pixels) {
	file << pixels.getCols() << ' ' << pixels.getRows() << '\n';
}

template<typename T>
inline void ImageUtilities<T>::negativeTransformation(Matrix<T>& pixels, const std::uint16_t value) {
	for (size_t row = 0; row < pixels.getRows(); ++row)
		for (size_t col = 0; col < pixels.getCols(); ++col)
			pixels.getElementAt(row, col) = value - pixels.getElementAt(row, col);
}
