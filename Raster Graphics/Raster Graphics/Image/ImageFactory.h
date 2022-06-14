#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H

#include <string_view>

#include "Image.h"
#include "PBMImage.h"

class ImageFactory {
public:
	static Image* createImage(std::string_view fileName);

private:
	ImageFactory() = delete;
	ImageFactory(const ImageFactory&) = delete;
	ImageFactory& operator=(const ImageFactory&) = delete;

	static std::string extractTypeFromName(std::string_view fileName);
};

#endif // !IMAGEFACTORY_H
