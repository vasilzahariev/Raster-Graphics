#ifndef PBMIMAGE_H
#define PBMIMAGE_H

#include <algorithm>

#include "Image.h"

class PBMImage : public Image {
public:
	PBMImage(std::string_view fileName);
	PBMImage(const PBMImage& other);

	PBMImage* clone() override;

	void readFromFile(std::ifstream& file) override;
	void writeToFile(std::ofstream& file) override;

	void rotate(std::string direction) override;

	void grayscale() override;

private:
	static const std::uint16_t MAX_COLOR_VALUE = 1;

private:
	Matrix<std::uint16_t> m_pixels;

	void readRowsAndColsFromFileAndResizePixels(std::ifstream& file) override;

	void writeRowsAndColsToFile(std::ofstream& file) const override;

	void copy(Image* const image) override;
};

#endif // !PBMIMAGE_H
