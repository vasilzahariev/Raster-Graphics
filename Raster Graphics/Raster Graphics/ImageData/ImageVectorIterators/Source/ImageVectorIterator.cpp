#include "../ImageVectorIterator.h"

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

bool ImageVectorIterator::operator==(const ImageVectorIterator& other) const {
	return m_ptr == other.m_ptr;
}

bool ImageVectorIterator::operator!=(const ImageVectorIterator& other) const {
	return !(*this == other);
}
