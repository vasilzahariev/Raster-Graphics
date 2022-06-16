#ifndef PGMIMAGE_H
#define PGMIMAGE_H

#include <algorithm>

#include "Image.h"

class PGMImage : public Image {
public:
	PGMImage(std::string_view fileName);
	PGMImage(const PGMImage& other);

	PGMImage* clone() override;

	void readFromFile(std::ifstream& file) override;
	void writeToFile(std::ofstream& file) override;

	void rotate(std::string direction) override;

	void grayscale() override;
	void monochrome() override;

private:
	Matrix<std::uint16_t> m_pixels;

	void readRowsAndColsFromFileAndResizePixels(std::ifstream& file) override;

	void writeRowsAndColsToFile(std::ofstream& file) const override;

	void copy(Image* const image) override;
};

#endif // !PGMIMAGE_H
