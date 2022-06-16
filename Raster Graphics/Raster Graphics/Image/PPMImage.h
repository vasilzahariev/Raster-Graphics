#ifndef PPMIMAGE_H
#define PPMIMAGE_H

#include "Image.h"
#include "Vector3.h"

class PPMImage : public Image {
public:
	PPMImage(std::string_view fileName);
	PPMImage(const PPMImage& other);

	PPMImage* clone() override;

	void readFromFile(std::ifstream& file) override;
	void writeToFile(std::ofstream& file) override;

	void rotate(std::string direction) override;

	void grayscale() override;
	void monochrome() override;

private:
	Matrix<Vector3<std::uint16_t>> m_pixels;

	void readRowsAndColsFromFileAndResizePixels(std::ifstream& file) override;

	void writeRowsAndColsToFile(std::ofstream& file) const override;

	void copy(Image* const image) override;
};

#endif // !PPMIMAGE_H
