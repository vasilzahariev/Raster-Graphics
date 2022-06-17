#include "../RGBData.h"

double RGBData::GRAY_MULTIPLIERS[3] = { .299, .587, .114 };

RGBData::RGBData(const std::uint16_t val)
	: red(val), green(val), blue(val) {
}

RGBData::RGBData(const std::uint16_t red, const std::uint16_t green, const std::uint16_t blue)
	: red(red), green(green), blue(blue) {
}

bool RGBData::operator==(const RGBData& other) const {
	return (red == other.red && green == other.green && blue == other.blue);
}

void RGBData::readFrom(std::istream& in) {
	in >> *this;
}

void RGBData::writeTo(std::ostream& out) const {
	out << *this;
}

void RGBData::transformToGrayscale() {
	std::uint16_t gray = std::round((GRAY_MULTIPLIERS[0] * red) + (GRAY_MULTIPLIERS[1] * green) + (GRAY_MULTIPLIERS[2] * blue));

	red = gray;
	green = gray;
	blue = gray;
}

void RGBData::normalizeByValue(const std::uint16_t value) {
	red = std::round((double)red / value);
	green = std::round((double)green / value);
	blue = std::round((double)blue / value);
}

void RGBData::transformToNegative(const std::uint16_t value) {
	red = value - red;
	green = value - green;
	blue = value - blue;
}

std::istream& operator>>(std::istream& in, RGBData& RGBData) {
	return (in >> RGBData.red >> RGBData.green >> RGBData.blue);
}

std::ostream& operator<<(std::ostream& out, const RGBData& RGBData) {
	return (out << RGBData.red << ' ' << RGBData.green << ' ' << RGBData.blue);
}
