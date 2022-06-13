#ifndef PBMIMAGE_H
#define PBMIMAGE_H

#include "Image.h"

class PBMImage : public Image {
public:
	PBMImage(std::string_view fileName);

	PBMImage* clone() const override;

	void readFromFile(std::ifstream& file) override;
	void writeToFile(std::ofstream& file) const override;

	void rotate(std::string_view direction) override;

private:
	static const std::uint16_t MAX_COLOR_VALUE = 1;

private:
	Matrix<std::uint16_t> m_pixels;

	void readRowsAndColsFromFileAndResizePixels(std::ifstream& file) override;

	void writeRowsAndColsToFile(std::ofstream& file) const override;
};

#endif // !PBMIMAGE_H
