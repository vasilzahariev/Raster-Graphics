#pragma once

#include <fstream>
#include <algorithm>

#include "../ImageData/Matrix.h"
#include "RasterGraphicsUtility.h"

template <typename T>
class ImageUtilities {
public:
	static void readParamsToResizeMatrixFromFile(std::ifstream& file, Matrix<T>& pixels);

	static void rotatePixels(std::string direction, Matrix<T>& pixels);

	static void writePixelsRowsAndColsToFile(std::ofstream& file, const Matrix<T>& pixels);
};

template<typename T>
inline void ImageUtilities<T>::readParamsToResizeMatrixFromFile(std::ifstream& file, Matrix<T>& pixels) {
	size_t rows;
	size_t cols;

	file >> rows >> cols;

	pixels.resize(rows, cols);
}

template<typename T>
inline void ImageUtilities<T>::rotatePixels(std::string direction, Matrix<T>& pixels) {
	RasterGraphicsUtility::toLowerString(direction);

	if (direction == "left")
		pixels.rotateLeft();
	else if (direction == "right")
		pixels.rotateRight();
	else
		throw std::logic_error("Direction should either be left or right");
}

template<typename T>
inline void ImageUtilities<T>::writePixelsRowsAndColsToFile(std::ofstream& file, const Matrix<T>& pixels) {
	file << pixels.getRows() << ' ' << pixels.getCols() << '\n';
}
