#pragma once

#include "../Image/Image.h"

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

	bool operator==(const ImageVectorIterator& other);

	bool operator!=(const ImageVectorIterator& other);

private:
	PointerType m_ptr;
};

class ImageVector {
public:
	using Iterator = ImageVectorIterator;

public:
	ImageVector();
	ImageVector(const ImageVector& other);
	~ImageVector();

	void push_back(Image* element);
	void remove_at(const int index);

	size_t size() const;

	Image* operator[](const int index);
	const Image* operator[](const int index) const;

	Iterator begin();
	Iterator end();

	ImageVector& operator=(const ImageVector& other);

private:
	Image** m_data;
	size_t nSize;
	size_t nCapacity;

	void deleteData();
	void allocData(size_t newCapacity);
	void copy(const ImageVector& other);

	Image* getElementAtIndex(const int index) const;
};
