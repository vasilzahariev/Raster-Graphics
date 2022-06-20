#pragma once

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
	void negative() override;

	void setPixels(const Matrix<std::uint16_t>& matrix);
	Matrix<std::uint16_t> getPixels() const;

private:
	Matrix<std::uint16_t> m_pixels;

	void readRowsAndColsFromFileAndResizePixels(std::ifstream& file) override;

	void writeRowsAndColsToFile(std::ofstream& file) const override;

	void copy(Image* image) override;
};
