#pragma once

#include "../../Image/Image.h"

class ImageVectorConstIterator {
public:
	using ValueType = const Image*;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	ImageVectorConstIterator(PointerType ptr);

	ImageVectorConstIterator& operator++();

	ImageVectorConstIterator operator++(int);

	ImageVectorConstIterator& operator--();

	ImageVectorConstIterator operator--(int);

	ReferenceType operator[](const int index) const;

	PointerType operator->() const;

	ReferenceType operator*() const;

	bool operator==(const ImageVectorConstIterator& other) const;

	bool operator!=(const ImageVectorConstIterator& other) const;

private:
	PointerType m_ptr;
};
