#pragma once

#include <string_view>

#include "Image.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"

class ImageFactory {
public:
	ImageFactory() = delete;
	ImageFactory(const ImageFactory&) = delete;
	ImageFactory& operator=(const ImageFactory&) = delete;

	static Image* createImage(std::string_view fileName);

private:
	static std::string extractTypeFromName(std::string_view fileName);
};
