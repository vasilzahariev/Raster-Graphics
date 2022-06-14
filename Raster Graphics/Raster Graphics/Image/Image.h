#ifndef IMAGE_H
#define IMAGE_H

#include <fstream>
#include <string>
#include <string_view>
#include <vector>

#include "Matrix.h"
#include "../Interfaces/ICloneable.h"

class Image : public ICloneable {
public:
	std::string_view getFileName() const;

	bool isGrayscale() const;
	bool isMonochrome() const;

	virtual Image* clone() = 0;

	virtual void readFromFile(std::ifstream& file) = 0;
	virtual void writeToFile(std::ofstream& file) const = 0;

	virtual void rotate(std::string direction) = 0;

protected:
	Image(std::string_view fileName, const bool grayscale = false, const bool monochrome = false, const std::uint16_t maxColorValue = 0);

protected:
	std::string m_fileName;
	std::vector<std::string> m_comments;
	std::uint16_t m_magicNumber;
	std::uint16_t m_maxColorValue;
	bool bGrayscale;
	bool bMonochrome;

protected:
	void readMagicNumberFromFile(std::ifstream& file);
	void readCommentsFromFile(std::ifstream& file);
	void readCommentLineFromFile(std::ifstream& file, std::string& line);
	void readMaxColorValueFromFile(std::ifstream& file);
	virtual void readRowsAndColsFromFileAndResizePixels(std::ifstream& file) = 0;

	void writeMagicNumberToFile(std::ofstream& file) const;
	void writeCommentsToFile(std::ofstream& file) const;
	void writeCommentLineToFile(std::ofstream& file, std::string_view comment) const;
	void writeMaxColorValue(std::ofstream& file) const;
	virtual void writeRowsAndColsToFile(std::ofstream& file) const = 0;
};

#endif // !IMAGE_H
