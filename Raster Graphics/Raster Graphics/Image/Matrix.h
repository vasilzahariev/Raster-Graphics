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
	Matrix(const T** matrix, const size_t rows, const size_t cols);
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

	void deleteData(T** data, const size_t rows);
	void deleteArrObj(T* obj);

	static T getValueAtRowAndCol(const T**, const size_t, const size_t, const size_t);
	static T getZeroValue(const T**, const size_t, const size_t, const size_t);
	static T getTransposedValue(const T**, const size_t, const size_t, const size_t);
	static T getReversedRowsValue(const T**, const size_t, const size_t, const size_t);
	void setData(const T** destination, size_t& destinationRows, size_t& destinationCols, const T** source, const size_t sourceRows, const size_t sourceCols, T(*getValue)(const T**, const size_t, const size_t, const size_t));
	void setDataRows(const T** destination, size_t& destinationRows, size_t& destinationCols, const T** source, T(*getValue)(const T**, const size_t, const size_t, const size_t));
	void setDataRowCols(const T** destination, const size_t row, const size_t rows, size_t& destinationCols, const T** source, T(*getValue)(const T**, const size_t, const size_t, const size_t));

	void copy(const Matrix<T>& other);

	T& getElement(const size_t row, const size_t col) const;

	void configureMatrix(const size_t tempRows, const size_t tempCols, T(*configureFunction)(const T**, const size_t, const size_t, const size_t));
	void transpose();
	void reverseRows();

	void rotate(void(Matrix<T>::*firstOperation)(), void(Matrix<T>::*secondOperation)());
};

#endif // !MATRIX_H

template<typename T>
inline Matrix<T>::Matrix(const size_t rows, const size_t cols)
	: m_data(nullptr), nRows(rows), nCols(cols) {
	setData(m_data, nRows, nCols, nullptr, rows, cols, &getZeroValue);
}

template<typename T>
inline Matrix<T>::Matrix(const T** matrix, const size_t rows, const size_t cols) {
	setData(m_data, nRows, nCols, matrix, rows, cols, &getValueAtRowAndCol);
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix<T>& other)
	: m_data(nullptr) {
	copy(other);
}

template<typename T>
inline Matrix<T>::~Matrix() {
	deleteData(m_data, nRows);
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
	for (size_t row = 0; row < nRows; ++row) {
		for (size_t col = 0; col < nCols; ++col)
			file << m_data[row][col];

		file << '\n';
	}
}

template<typename T>
inline void Matrix<T>::resize(const size_t rows, const size_t cols) {
	deleteData(m_data, nRows);
	setData(m_data, nRows, nCols, nullptr, rows, cols, &getZeroValue);
}

template<typename T>
inline void Matrix<T>::rotateRight() {
	rotate(&transpose, &reverseRows);
}

template<typename T>
inline void Matrix<T>::rotateLeft() {
	rotate(&reverseRows , &transpose);
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
inline void Matrix<T>::deleteData(T** data, const size_t rows) {
	for (size_t row = 0; row < rows; ++row)
		deleteArrObj(data[row]);

	delete[] data;
	data = nullptr;
}

template<typename T>
inline void Matrix<T>::deleteArrObj(T* obj) {
	delete[] obj;
	obj = nullptr;
}

template<typename T>
inline T Matrix<T>::getValueAtRowAndCol(const T** data, const size_t row, const size_t col, const size_t) {
	return data[row][col];
}

template<typename T>
inline T Matrix<T>::getZeroValue(const T**, const size_t, const size_t, const size_t) {
	return 0;
}

template<typename T>
inline T Matrix<T>::getTransposedValue(const T** matrix, const size_t col, const size_t row, const size_t) {
	return matrix[row][col];
}

template<typename T>
inline T Matrix<T>::getReversedRowsValue(const T** matrix, const size_t row, const size_t col, const size_t rows) {
	return matrix[rows - row - 1][col];
}

template<typename T>
inline void Matrix<T>::setData(const T** destination, size_t& destinationRows, size_t& destinationCols, const T** source, const size_t sourceRows, const size_t sourceCols, T(*getValue)(const T**, const size_t, const size_t, const size_t)) {
	destinationRows = sourceRows;
	destinationCols = sourceCols;
	destination = new T * [destinationRows] {nullptr, };

	setDataRows(destination, destinationRows, destinationCols, source, getValue);
}

template<typename T>
inline void Matrix<T>::setDataRows(const T** destination, size_t& destinationRows, size_t& destinationCols, const T** source, T(*getValue)(const T**, const size_t, const size_t, const size_t)) {
	for (size_t row = 0; row < destinationRows; ++row) {
		destination[row] = new T[destinationCols];

		setDataRowCols(destination, destinationRows, row, destinationCols, source, getValue);
	}
}

template<typename T>
inline void Matrix<T>::setDataRowCols(const T** destination, const size_t rows, const size_t row, size_t& destinationCols, const T** source, T(*getValue)(const T**, const size_t, const size_t, const size_t)) {
	for (size_t col = 0; col < destinationCols; ++col)
		m_data[row][col] = getValue(source, row, col, rows);
}

template<typename T>
inline void Matrix<T>::copy(const Matrix<T>& other) {
	deleteData(m_data, nRows);
	setData(m_data, nRows, nCols, other.m_data, other.nRows, other.nCols, &getValueAtRowAndCol);
}

template<typename T>
inline T& Matrix<T>::getElement(const size_t row, const size_t col) const {
	if (row < 0 || row >= nRows || col < 0 || col >= nCols)
		throw OutOfBoundsException("Out of bounds position");
	
	return m_data[row][col];
}

template<typename T>
inline void Matrix<T>::configureMatrix(const size_t tempRows, const size_t tempCols, T(*configureFunction)(const T**, const size_t, const size_t, const size_t)) {
	size_t rows = tempRows;
	size_t cols = tempCols;
	T** temp = nullptr;

	setData(temp, rows, cols, m_data, rows, cols, configureFunction);
	deleteData(m_data, nRows);
	setData(m_data, nRows, nCols, temp, rows, cols, &getValueAtRowAndCol);
	deleteData(temp, rows);
}

template<typename T>
inline void Matrix<T>::transpose() {
	configureMatrix(nCols, nRows, &getTransposedValue);
}

template<typename T>
inline void Matrix<T>::reverseRows() {
	configureMatrix(nRows, nCols, &getReversedRowsValue);
}

template<typename T>
inline void Matrix<T>::rotate(void(Matrix<T>::*firstOperation)(), void(Matrix<T>::*secondOperation)()) {
	firstOperation;
	secondOperation;
}
