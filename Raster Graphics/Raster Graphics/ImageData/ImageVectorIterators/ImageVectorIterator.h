#pragma once

#include "../../Image/Image.h"

class ImageVectorIterator {
public:
	using ValueType = Image*;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	ImageVectorIterator(PointerType ptr);

	ImageVectorIterator& operator++();

	ImageVectorIterator operator++(int);

	ImageVectorIterator& operator--();

	ImageVectorIterator operator--(int);

	ReferenceType operator[](const int index);

	PointerType operator->();

	ReferenceType operator*();

	bool operator==(const ImageVectorIterator& other) const;

	bool operator!=(const ImageVectorIterator& other) const;

private:
	PointerType m_ptr;
};
