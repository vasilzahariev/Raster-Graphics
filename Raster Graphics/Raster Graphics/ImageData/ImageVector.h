#pragma once

#include "../Image/Image.h"
#include "./ImageVectorIterators/ImageVectorIterator.h"
#include "./ImageVectorIterators/ImageVectorConstIterator.h"

class ImageVector {
public:
	using iterator = ImageVectorIterator;
	using const_iterator = ImageVectorConstIterator;

public:
	ImageVector();
	ImageVector(const ImageVector& other);
	~ImageVector();

	void push_back(Image* element);
	void remove_at(const int index);

	size_t size() const;

	Image* operator[](const int index);
	const Image* operator[](const int index) const;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

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
