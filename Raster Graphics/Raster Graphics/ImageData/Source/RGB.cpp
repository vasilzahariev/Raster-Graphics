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

	setRGB(gray);
}

void RGBData::normalizeByValue(const std::uint16_t value) {
	std::uint16_t BWVal = std::round((double)(red + green + blue) / (3 * value));

	setRGB(value * BWVal);
}

void RGBData::transformToNegative(const std::uint16_t value) {
	*this = value - *this;
}

void RGBData::setRGB(const std::uint16_t val) {
	red = val;
	green = val;
	blue = val;
}

void RGBData::setRGB(const std::uint16_t R, const std::uint16_t G, const std::uint16_t B) {
	red = R;
	green = G;
	blue = B;
}

RGBData& operator-(const std::uint16_t val, RGBData& rgb) {
	rgb.setRGB(val - rgb.red, val - rgb.green, val - rgb.blue);

	return rgb;
}

std::istream& operator>>(std::istream& in, RGBData& RGBData) {
	return (in >> RGBData.red >> RGBData.green >> RGBData.blue);
}

std::ostream& operator<<(std::ostream& out, const RGBData& RGBData) {
	return (out << RGBData.red << ' ' << RGBData.green << ' ' << RGBData.blue);
}
