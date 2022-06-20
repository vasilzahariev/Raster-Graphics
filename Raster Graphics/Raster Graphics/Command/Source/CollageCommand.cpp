#include "../CollageCommand.h"

#define PBMCast(img) dynamic_cast<PBMImage*>(img)
#define PGMCast(img) dynamic_cast<PGMImage*>(img)
#define PPMCast(img) dynamic_cast<PPMImage*>(img)

CollageCommand::CollageCommand(Session* const session, const std::vector<std::string>& args)
	: m_session(session), m_args(args) {
}

std::string CollageCommand::execute() {
	Image* img1 = getImage(m_args[2]);
	Image* img2 = getImage(m_args[3]);
	Image* out = collage(img1, img2, m_args[1], m_args[4]);

	m_session->addImage(out);

	std::ofstream file(out->getFileName());

	out->writeToFile(file);

	return "Collage was created";
}

size_t CollageCommand::getNumberOfArgs() {
	return nArgs;
}

Image* CollageCommand::getImage(const std::string& fileName) {
	Image* img = ImageFactory::createImage(fileName);

	std::ifstream file(img->getFileName());

	if (!file.is_open())
		throw FileException("Problem with the opening of the image");

	img->readFromFile(file);

	return img;
}

Image* CollageCommand::collage(Image* image1, Image* image2, std::string direction, std::string outImageLocation) {
	if (direction != "horizontal" && direction != "vertical")
		throw CommandException("Invalid <direction> argument");
	else if (typeid(*image1) != typeid(*image2))
		throw ImageException("Cannot create a collage of two different types");

	Image* out = ImageFactory::createImage(outImageLocation);

	if (typeid(*image1) != typeid(*out))
		throw ImageException("Cannot create a collage of two images for a different types");

	out->setMagicNumber(image1->getMagicNumber());
	out->setMaxColorValue(std::max(image1->getMaxColorValue(), image2->getMaxColorValue()));

	std::uint16_t maxes[3]{ image1->getMaxColorValue(), image2->getMaxColorValue(), out->getMaxColorValue() };

	if (typeid(*out) == typeid(PBMImage)) {
		using Pixels = Matrix<std::uint16_t>;

		Pixels pixels1 = PBMCast(image1)->getPixels();
		Pixels pixels2 = PBMCast(image2)->getPixels();
		Pixels outPixels = (direction == "horizontal" ? Pixels::combineHorizontally(pixels1, pixels2, maxes) : Pixels::combineVertically(pixels1, pixels2, maxes));

		PBMCast(out)->setPixels(outPixels);
	}
	else if (typeid(*out) == typeid(PGMImage)) {
		using Pixels = Matrix<std::uint16_t>;

		Pixels pixels1 = PGMCast(image1)->getPixels();
		Pixels pixels2 = PGMCast(image2)->getPixels();
		Pixels outPixels = (direction == "horizontal" ? Pixels::combineHorizontally(pixels1, pixels2, maxes) : Pixels::combineVertically(pixels1, pixels2, maxes));

		PGMCast(out)->setPixels(outPixels);
	}
	else if (typeid(*out) == typeid(PPMImage)) {
		using Pixels = Matrix<RGBData>;

		Pixels pixels1 = PPMCast(image1)->getPixels();
		Pixels pixels2 = PPMCast(image2)->getPixels();
		Pixels outPixels = (direction == "horizontal" ? Pixels::combineHorizontally(pixels1, pixels2, maxes) : Pixels::combineVertically(pixels1, pixels2, maxes));

		PPMCast(out)->setPixels(outPixels);
	}
	
	return out;
}
