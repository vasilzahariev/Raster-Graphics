#pragma once

#include <iostream>
#include <cstdint>
#include <cmath>

struct RGBData {
public:
	std::uint16_t red;
	std::uint16_t green;
	std::uint16_t blue;

public:
	RGBData(const std::uint16_t val = 0);
	RGBData(const std::uint16_t red, const std::uint16_t green, const std::uint16_t blue);

	bool operator==(const RGBData& other) const;

	void readFrom(std::istream& in = std::cin);
	void writeTo(std::ostream& out = std::cout) const;

	void transformToGrayscale();
	void normalizeByValue(const std::uint16_t value);
	void transformToNegative(const std::uint16_t value);

	void setRGB(const std::uint16_t val);
	void setRGB(const std::uint16_t R, const std::uint16_t G, const std::uint16_t B);

	RGBData operator*(const std::uint16_t val);

	friend RGBData& operator-(const std::uint16_t val, RGBData& rgb);
	friend std::istream& operator>>(std::istream& in, RGBData& RGBData);
	friend std::ostream& operator<<(std::ostream& out, const RGBData& RGBData);

private:
	static double GRAY_MULTIPLIERS[3];
};
