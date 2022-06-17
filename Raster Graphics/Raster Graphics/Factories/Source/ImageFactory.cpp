#include "../ImageFactory.h"

Image* ImageFactory::createImage(std::string_view fileName) {
    std::string type = extractTypeFromName(fileName);

    RasterGraphicsUtility::toLowerString(type);

    if (type == "pbm")
        return new PBMImage(fileName);
    else if (type == "pgm")
        return new PGMImage(fileName);
    else if (type == "ppm")
        return new PPMImage(fileName);

    throw FileException("Invalid image type");
}

std::string ImageFactory::extractTypeFromName(std::string_view fileName) {
    std::string type = "";

    type.push_back(fileName[fileName.size() - 3]);
    type.push_back(fileName[fileName.size() - 2]);
    type.push_back(fileName[fileName.size() - 1]);
    
    return type;
}
