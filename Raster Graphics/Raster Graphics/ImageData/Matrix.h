#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>

#include "RGBData.h"
#include "../Exceptions/OutOfBoundsException.h"
#include <functional>

template <typename T>
class Matrix {
public:
	Matrix(const size_t rows = 0, const size_t cols = 0);
	Matrix(const Matrix<T>& other);
	~Matrix();

	size_t getRows() const;
	size_t getCols() const;

	void readFromFile(std::ifstream& file);
	void writeToFile(std::ofstream& file) const;

	void resize(const size_t rows, const size_t cols);

	void rotateRight();
	void rotateLeft();

	static Matrix<T> combineHorizontally(const Matrix<T>& matrix1, const Matrix<T>& matrix2, const std::uint16_t maxValues[3]);
	static Matrix<T> combineVertically(const Matrix<T>& matrix1, const Matrix<T>& matrix2, const std::uint16_t maxValues[3]);

	T& getElementAt(const size_t row, const size_t col);
	const T& getElementAt(const size_t row, const size_t col) const;

	Matrix<T>& operator=(const Matrix<T>& other);

private:
	T** m_data;
	size_t nRows;
	size_t nCols;

	void deleteData();
	void copyMatrix(const Matrix<T>& other);
	void copy(const Matrix<T>& other);

	void fillMatrix(const size_t rows, const size_t cols, std::function<void(T&, size_t, size_t)> filler);

	void fillMatrixWithZeroes(const size_t rows, const size_t cols);
	void transpose();
	void reverseRows();

	T& getElement(const size_t row, const size_t col) const;
};


template<typename T>
inline Matrix<T>::Matrix(const size_t rows, const size_t cols)
	: m_data(nullptr), nRows(0), nCols(0) {
	fillMatrixWithZeroes(rows, cols);
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix<T>& other)
	: m_data(nullptr), nRows(0), nCols(0) {
	copy(other);
}

template<typename T>
inline Matrix<T>::~Matrix() {
	deleteData();
}

template<typename T>
inline size_t Matrix<T>::getRows() const {
	return nRows;
}

template<typename T>
inline size_t Matrix<T>::getCols() const {
	return nCols;
}

template<typename T>
inline void Matrix<T>::readFromFile(std::ifstream& file) {
	for (size_t row = 0; row < nRows; ++row)
		for (size_t col = 0; col < nCols; ++col)
			file >> m_data[row][col];
}

template<typename T>
inline void Matrix<T>::writeToFile(std::ofstream& file) const {
	for (size_t row = 0; row < nRows; ++row)
		for (size_t col = 0; col < nCols; ++col)
			file << m_data[row][col] << (col == nCols - 1 ? '\n' : ' ');
}

template<typename T>
inline void Matrix<T>::resize(const size_t rows, const size_t cols) {
	fillMatrix(rows, cols, [=](T& elem, size_t row, size_t col) {
		if (row < nRows && col < nCols)
			elem = m_data[row][col];
		else
			elem = 0;
		});
}

template<typename T>
inline void Matrix<T>::rotateRight() {
	reverseRows();
	transpose();
}

template<typename T>
inline void Matrix<T>::rotateLeft() {
	transpose();
	reverseRows();
}

template<typename T>
inline Matrix<T> Matrix<T>::combineVertically(const Matrix<T>& matrix1, const Matrix<T>& matrix2, const std::uint16_t maxValues[3]) {
	const size_t rows = matrix1.getRows() + matrix2.getRows();
	const size_t cols = std::max(matrix1.getCols(), matrix2.getCols());

	Matrix<T> out(rows, cols);

	for (size_t row = 0; row < rows; ++row) {
		const Matrix<T>& source = (row < matrix1.getRows() ? matrix1 : matrix2);
		const size_t rowIndex = row < matrix1.getRows() ? row : row - matrix1.getRows();

		for (size_t col = 0; col < cols; ++col) {
			if (col < source.getCols()) {
				if (&source == &matrix1 && maxValues[0] == maxValues[2] || &source == &matrix2 && maxValues[1] == maxValues[2])
					out.getElementAt(row, col) = source.m_data[rowIndex][col];
				else
					out.getElementAt(row, col) = source.m_data[rowIndex][col] * (maxValues[2] / (&source == &matrix1 ? maxValues[0] : maxValues[1]));
			}
			else
				out.getElementAt(row, col) = 0;
		}
	}

	return out;
}

template<typename T>
inline Matrix<T> Matrix<T>::combineHorizontally(const Matrix<T>& matrix1, const Matrix<T>& matrix2, const std::uint16_t maxValues[3]) {
	const size_t rows = std::max(matrix1.getRows(), matrix2.getRows());
	const size_t cols = matrix1.getCols() + matrix2.getCols();

	Matrix<T> out(rows, cols);

	for (size_t row = 0; row < rows; ++row) {
		for (size_t col = 0; col < cols; ++col) {
			const Matrix<T>& source = (col < matrix1.getCols() ? matrix1 : matrix2);
			const size_t colIndex = col < matrix1.getCols() ? col : col - matrix1.getCols();

			if (row < source.getRows())
				if (&source == &matrix1 && maxValues[0] == maxValues[2] || &source == &matrix2 && maxValues[1] == maxValues[2])
					out.getElementAt(row, col) = source.m_data[row][colIndex];
				else
					out.getElementAt(row, col) = source.m_data[row][colIndex] * (maxValues[2] / (&source == &matrix1 ? maxValues[0] : maxValues[1]));
			else
				out.getElementAt(row, col) = 0;
		}
	}

	return out;
}

template<typename T>
inline T& Matrix<T>::getElementAt(const size_t row, const size_t col) {
	return getElement(row, col);
}

template<typename T>
inline const T& Matrix<T>::getElementAt(const size_t row, const size_t col) const {
	return getElement(row, col);
}

template<typename T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
	if (this != &other) copy(other);

	return *this;
}

template<typename T>
inline void Matrix<T>::deleteData() {
	if (m_data == nullptr)
		return;

	for (size_t row = 0; row < nRows; ++row) {
		delete[] m_data[row];
		m_data[row] = nullptr;
	}

	delete[] m_data;
	m_data = nullptr;
}

template<typename T>
inline void Matrix<T>::copyMatrix(const Matrix<T>& other) {
	nRows = other.nRows;
	nCols = other.nCols;

	m_data = new T * [nRows];

	for (size_t row = 0; row < nRows; ++row) {
		m_data[row] = new T[nCols];

		for (size_t col = 0; col < nCols; ++col)
			m_data[row][col] = other.m_data[row][col];
	}
}

template<typename T>
inline void Matrix<T>::copy(const Matrix<T>& other) {
	deleteData();
	copyMatrix(other);
}

template<typename T>
inline void Matrix<T>::fillMatrix(const size_t rows, const size_t cols, std::function<void(T&, size_t, size_t)> filler) {
	T** blockOfMem = new T * [rows];

	for (size_t row = 0; row < rows; ++row) {
		blockOfMem[row] = new T[cols];

		for (size_t col = 0; col < cols; ++col)
			filler(blockOfMem[row][col], row, col);
	}

	deleteData();
	m_data = blockOfMem;
	nRows = rows;
	nCols = cols;
}

template<typename T>
inline void Matrix<T>::fillMatrixWithZeroes(const size_t rows, const size_t cols) {
	fillMatrix(rows, cols, [](T& elem, size_t, size_t) { elem = 0; });
}

template<typename T>
inline void Matrix<T>::transpose() {
	fillMatrix(nCols, nRows, [=](T& elem, size_t row, size_t col) { elem = m_data[col][row]; });
}

template<typename T>
inline void Matrix<T>::reverseRows() {
	fillMatrix(nRows, nCols, [=](T& elem, size_t row, size_t col) { elem = m_data[nRows - row - 1][col]; });
}

template<typename T>
inline T& Matrix<T>::getElement(const size_t row, const size_t col) const {
	if (row < 0 || row >= nRows || col < 0 || col >= nCols)
		throw OutOfBoundsException("Out of bounds position");

	return m_data[row][col];
}
