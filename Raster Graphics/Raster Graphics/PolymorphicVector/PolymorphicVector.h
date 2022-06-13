#ifndef POLYMORPHICVECTOR_H
#define POLYMORPHICVECTOR_H

#include <iostream>

#include "../Interfaces/ICloneable.h"
#include "../Exceptions/OutOfBoundsException.h"

template <class T>
class PolymorphicVector {
public:
	PolymorphicVector();
	PolymorphicVector(const PolymorphicVector& other);
	~PolymorphicVector();

	void push_back(ICloneable* element);
	void remove_at(const int index);

	T* operator[](const int index);
	const T* operator[](const int index) const;

	PolymorphicVector& operator=(const PolymorphicVector& other);

private:
	ICloneable** m_data;
	size_t nSize;
	size_t nCapacity;

	void deleteData();
	void allocData(size_t newCapacity);
	void copy(const PolymorphicVector& other);

	T* getElementAtIndex(const int index) const;
};

#endif // !POLYMORPHICVECTOR_H

template<class T>
inline PolymorphicVector<T>::PolymorphicVector()
								: m_data(nullptr), nSize(0), nCapacity(0) {
	allocData(2);
}

template<class T>
inline PolymorphicVector<T>::PolymorphicVector(const PolymorphicVector<T>& other)
								: m_data(nullptr), nSize(0), nCapacity(0) {
	copy(other);
}

template<class T>
inline PolymorphicVector<T>::~PolymorphicVector() {
	deleteData();
}

template<class T>
inline void PolymorphicVector<T>::push_back(ICloneable* element) {
	if (nSize >= nCapacity) allocData(nCapacity * 2);

	m_data[nSize++] = element;
}

template<class T>
inline void PolymorphicVector<T>::remove_at(const int index) {
	if (index < 0 || index >= nSize)
		throw OutOfBoundsException("Index out of bounds");

	std::swap(m_data[index], m_data[--nSize]);
}

template<class T>
inline T* PolymorphicVector<T>::operator[](const int index) {
	return getElementAtIndex(index);
}

template<class T>
inline const T* PolymorphicVector<T>::operator[](const int index) const {
	return getElementAtIndex(index);
}

template<class T>
inline PolymorphicVector<T>& PolymorphicVector<T>::operator=(const PolymorphicVector<T>& other) {
	if (this != &other) copy(other);

	return *this;
}

template<class T>
inline void PolymorphicVector<T>::deleteData() {
	for (size_t index = 0; index < nSize; ++index) {
		delete m_data[index];
		m_data[index] = nullptr;
	}

	delete[] m_data;
	m_data = nullptr;
}

template<class T>
inline void PolymorphicVector<T>::allocData(size_t newCapacity) {
	if (nSize >= newCapacity) newCapacity = nSize + 1;

	ICloneable** blockOfData = new ICloneable * [newCapacity]{ nullptr, };

	for (size_t index = 0; index < nSize; ++index)
		blockOfData[index] = m_data[index]->clone();

	deleteData();
	m_data = blockOfData;
	nCapacity = newCapacity;
}

template<class T>
inline void PolymorphicVector<T>::copy(const PolymorphicVector<T>& other) {
	deleteData();
	nCapacity = other.nCapacity;
	m_data = new ICloneable*[nCapacity] {nullptr, };
	nSize = other.nSize;

	for (size_t index = 0; index < nSize; ++index)
		m_data[index] = other.m_data[index]->clone();
}

template<class T>
inline T* PolymorphicVector<T>::getElementAtIndex(const int index) const {
	if (index < 0 || index >= nSize)
		throw OutOfBoundsException("Index out of bounds");

	return dynamic_cast<T*>(m_data[index]);
}
