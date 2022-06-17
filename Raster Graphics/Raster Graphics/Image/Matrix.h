#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <cstdint>

#include "Vector3.h"
#include "../Exceptions/OutOfBoundsException.h"


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

	T& getElementAt(const size_t row, const size_t col);
	const T& getElementAt(const size_t row, const size_t col) const;

	Matrix<T>& operator=(const Matrix<T>& other);

private:
	T** m_data;
	size_t nRows;
	size_t nCols;

	void deleteData();
	void copy(const Matrix<T>& other);

	void fillMatrixWithZeroes(const size_t rows, const size_t cols);

	void transpose();
	void reverseRows();

	T& getElement(const size_t row, const size_t col) const;
};

#endif // !MATRIX_H
//
//template<typename T>
//inline Matrix<T>::Matrix(const size_t rows, const size_t cols)
//	: m_data(nullptr), nRows(0), nCols(0) {
//	fillMatrixWithZeroes(rows, cols);
//}
//
//template<typename T>
//inline Matrix<T>::Matrix(const Matrix<T>& other) {
//	copy(other);
//}
//
//template<typename T>
//inline Matrix<T>::~Matrix() {
//	deleteData();
//}
//
//template<typename T>
//inline size_t Matrix<T>::getRows() const {
//	return nRows;
//}
//
//template<typename T>
//inline size_t Matrix<T>::getCols() const {
//	return nCols;
//}
//
//template<typename T>
//inline void Matrix<T>::readFromFile(std::ifstream& file) {
//	for (size_t row = 0; row < nRows; ++row) {
//		for (size_t col = 0; col < nCols; ++col) {
//			file >> m_data[row][col];
//		}
//	}
//}
//
//template<typename T>
//inline void Matrix<T>::writeToFile(std::ofstream& file) const {
//	for (size_t row = 0; row < nRows; ++row) {
//		for (size_t col = 0; col < nCols; ++col) {
//			file << m_data[row][col] << ' ';
//		}
//
//		file << '\n';
//	}
//}
//
//template<typename T>
//inline void Matrix<T>::resize(const size_t rows, const size_t cols) {
//	T** blockOfMem = new T * [rows];
//	
//	for (size_t row = 0; row < rows; ++row) {
//		blockOfMem[row] = new T[cols];
//
//		for (size_t col = 0; col < cols; ++col) {
//			if (nRows <= row || nCols <= col) {
//				blockOfMem[row][col] = 0;
//			}
//			else {
//				blockOfMem[row][col] = m_data[row][col];
//			}
//		}
//	}
//
//	deleteData();
//	m_data = blockOfMem;
//	nRows = rows;
//	nCols = cols;
//}
//
//template<typename T>
//inline void Matrix<T>::rotateRight() {
//	reverseRows();
//	transpose();
//}
//
//template<typename T>
//inline void Matrix<T>::rotateLeft() {
//	transpose();
//	reverseRows();
//}
//
//template<typename T>
//inline T& Matrix<T>::getElementAt(const size_t row, const size_t col) {
//	return getElement(row, col);
//}
//
//template<typename T>
//inline const T& Matrix<T>::getElementAt(const size_t row, const size_t col) const {
//	return getElement(row, col);
//}
//
//template<typename T>
//inline Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
//	if (this != &other) copy(other);
//
//	return *this;
//}
//
//template<typename T>
//inline void Matrix<T>::deleteData() {
//	for (size_t row = 0; row < nRows; ++row) {
//		delete[] m_data[row];
//		m_data[row] = nullptr;
//	}
//
//	delete[] m_data;
//	m_data = nullptr;
//}
//
//template<typename T>
//inline void Matrix<T>::copy(const Matrix<T>& other) {
//	nRows = other.nRows;
//	nCols = other.nCols;
//	deleteData();
//
//	m_data = new T * [nRows];
//
//	for (size_t row = 0; row < nRows; ++row) {
//		m_data[row] = new T[nCols];
//
//		for (size_t col = 0; col < nCols; ++col) {
//			m_data[row][col] = other.m_data[row][col];
//		}
//	}
//}
//
//template<typename T>
//inline void Matrix<T>::fillMatrixWithZeroes(const size_t rows, const size_t cols) {
//	deleteData();
//
//	nRows = rows;
//	nCols = cols;
//
//	m_data = new T * [nRows];
//
//	for (size_t row = 0; row < nRows; ++row) {
//		m_data[row] = new T[nCols];
//
//		for (size_t col = 0; col < nCols; ++col) {
//			m_data[row][col] = 0;
//		}
//	}
//}
//
//template<typename T>
//inline void Matrix<T>::transpose() {
//	size_t tempRows = nCols;
//	size_t tempCols = nRows;
//	T** temp = new T * [tempRows];
//	for (size_t row = 0; row < tempRows; ++row) {
//		temp[row] = new T[tempCols];
//
//		for (size_t col = 0; col < tempCols; ++col) {
//			temp[row][col] = m_data[col][row];
//		}
//	}
//
//	deleteData();
//	m_data = temp;
//	nRows = tempRows;
//	nCols = tempCols;
//}
//
//template<typename T>
//inline void Matrix<T>::reverseRows() {
//	T** temp = new T * [nRows];
//	for (size_t row = 0; row < nRows; ++row) {
//		temp[row] = new T[nCols];
//
//		for (size_t col = 0; col < nCols; ++col) {
//			temp[row][col] = m_data[nRows - row - 1][col];
//		}
//	}
//
//	deleteData();
//	m_data = temp;
//}
//
//template<typename T>
//inline T& Matrix<T>::getElement(const size_t row, const size_t col) const {
//	if (row < 0 || row >= nRows || col < 0 || col >= nCols)
//		throw OutOfBoundsException("Out of bounds position");
//
//	return m_data[row][col];
//}
