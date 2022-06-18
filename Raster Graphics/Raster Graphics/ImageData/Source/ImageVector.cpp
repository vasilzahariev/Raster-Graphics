#include "../ImageVector.h"

ImageVectorIterator::ImageVectorIterator(PointerType ptr)
	: m_ptr(ptr) {
}

ImageVectorIterator& ImageVectorIterator::operator++() {
	m_ptr++;

	return *this;
}

ImageVectorIterator ImageVectorIterator::operator++(int) {
	ImageVectorIterator iterator = *this;

	++(*this);

	return iterator;
}

ImageVectorIterator& ImageVectorIterator::operator--() {
	m_ptr--;

	return *this;
}

ImageVectorIterator ImageVectorIterator::operator--(int) {
	ImageVectorIterator iterator = *this;

	--(*this);

	return iterator;
}

ImageVectorIterator::ReferenceType ImageVectorIterator::operator[](const int index) {
	return *(m_ptr + index);
}

ImageVectorIterator::PointerType ImageVectorIterator::operator->() {
	return m_ptr;
}

ImageVectorIterator::ReferenceType ImageVectorIterator::operator*() {
	return *m_ptr;
}

bool ImageVectorIterator::operator==(const ImageVectorIterator& other) {
	return m_ptr == other.m_ptr;
}

bool ImageVectorIterator::operator!=(const ImageVectorIterator& other) {
	return !(*this == other);
}

ImageVector::ImageVector()
	: m_data(nullptr), nSize(0), nCapacity(0) {
	allocData(2);
}

ImageVector::ImageVector(const ImageVector& other)
	: m_data(nullptr), nSize(0), nCapacity(0) {
	copy(other);
}

ImageVector::~ImageVector() {
	deleteData();
}

void ImageVector::push_back(Image* element) {
	if (nSize >= nCapacity)
		allocData(nCapacity * 2);

	m_data[nSize++] = element;
}

void ImageVector::remove_at(const int index) {
	if (index < 0 || index >= nSize)
		throw OutOfBoundsException("Index out of bounds");

	std::swap(m_data[index], m_data[--nSize]);
}

size_t ImageVector::size() const {
	return nSize;
}

Image* ImageVector::operator[](const int index) {
	return getElementAtIndex(index);
}

const Image* ImageVector::operator[](const int index) const {
	return getElementAtIndex(index);
}

ImageVector::Iterator ImageVector::begin() {
	return Iterator(m_data);
}

ImageVector::Iterator ImageVector::end() {
	return Iterator(m_data + nSize);
}

ImageVector& ImageVector::operator=(const ImageVector& other) {
	if (this != &other) copy(other);

	return *this;
}

void ImageVector::deleteData() {
	for (size_t index = 0; index < nSize; ++index) {
		delete m_data[index];
		m_data[index] = nullptr;
	}

	delete[] m_data;
	m_data = nullptr;
}

void ImageVector::allocData(size_t newCapacity) {
	if (nSize >= newCapacity) newCapacity = nSize + 1;

	Image** blockOfData = new Image * [newCapacity] { nullptr, };

	for (size_t index = 0; index < nSize; ++index)
		blockOfData[index] = m_data[index]->clone();

	deleteData();
	m_data = blockOfData;
	nCapacity = newCapacity;
}

void ImageVector::copy(const ImageVector& other) {
	deleteData();
	nCapacity = other.nCapacity;
	m_data = new Image * [nCapacity] {nullptr, };
	nSize = other.nSize;

	for (size_t index = 0; index < nSize; ++index)
		m_data[index] = other.m_data[index]->clone();
}

Image* ImageVector::getElementAtIndex(const int index) const {
	if (index < 0 || index >= nSize)
		throw OutOfBoundsException("Index out of bounds");

	return m_data[index];
}
