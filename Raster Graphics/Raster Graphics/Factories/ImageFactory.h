#pragma once

#include <string_view>

#include "../Image/Image.h"
#include "../Image/PBMImage.h"
#include "../Image/PGMImage.h"
#include "../Image/PPMImage.h"
#include "../Exceptions/FileException.h"
#include "../Utilities/RasterGraphicsUtility.h"

class ImageFactory {
public:
	ImageFactory() = delete;
	ImageFactory(const ImageFactory&) = delete;
	ImageFactory& operator=(const ImageFactory&) = delete;

	static Image* createImage(std::string_view fileName);

private:
	static std::string extractTypeFromName(std::string_view fileName);
};
