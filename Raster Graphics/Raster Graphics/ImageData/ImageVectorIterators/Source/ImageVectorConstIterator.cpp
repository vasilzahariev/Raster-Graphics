#include "../ImageVectorConstIterator.h"

ImageVectorConstIterator::ImageVectorConstIterator(PointerType ptr)
	: m_ptr(ptr) {
}

ImageVectorConstIterator& ImageVectorConstIterator::operator++() {
	m_ptr++;

	return *this;
}

ImageVectorConstIterator ImageVectorConstIterator::operator++(int) {
	ImageVectorConstIterator iterator = *this;

	++(*this);

	return iterator;
}

ImageVectorConstIterator& ImageVectorConstIterator::operator--() {
	m_ptr--;

	return *this;
}

ImageVectorConstIterator ImageVectorConstIterator::operator--(int) {
	ImageVectorConstIterator iterator = *this;

	--(*this);

	return iterator;
}

ImageVectorConstIterator::ReferenceType ImageVectorConstIterator::operator[](const int index) const {
	return *(m_ptr + index);
}

ImageVectorConstIterator::PointerType ImageVectorConstIterator::operator->() const {
	return m_ptr;
}

ImageVectorConstIterator::ReferenceType ImageVectorConstIterator::operator*() const {
	return *m_ptr;
}

bool ImageVectorConstIterator::operator==(const ImageVectorConstIterator& other) const {
	return m_ptr == other.m_ptr;
}

bool ImageVectorConstIterator::operator!=(const ImageVectorConstIterator& other) const {
	return !(*this == other);
}
