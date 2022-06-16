#include "../ImageFactory.h"

Image* ImageFactory::createImage(std::string_view fileName) {
    std::string type = extractTypeFromName(fileName);

    if (type == "pbm")
        return new PBMImage(fileName);
    // TODO: Add others

    return nullptr;
}

std::string ImageFactory::extractTypeFromName(std::string_view fileName) {
    std::string type = "";

    type.push_back(fileName[fileName.size() - 3]);
    type.push_back(fileName[fileName.size() - 2]);
    type.push_back(fileName[fileName.size() - 1]);
    
    return type;
}
