#include "doctest.h"
#include "../Factories/ImageFactory.h"

TEST_CASE("Image Factory") {
	SUBCASE("Should create a PBM image") {
		Image* image = ImageFactory::createImage("file.pbm");

		PBMImage* pbm = dynamic_cast<PBMImage*>(image);

		REQUIRE(pbm != nullptr);
	}

	SUBCASE("Should create a PGM image") {
		Image* image = ImageFactory::createImage("file.pgm");

		PGMImage* pgm = dynamic_cast<PGMImage*>(image);

		REQUIRE(pgm != nullptr);
	}

	SUBCASE("Should create a PPM pointer") {
		Image* image = ImageFactory::createImage("file.ppm");

		PPMImage* ppm = dynamic_cast<PPMImage*>(image);

		REQUIRE(ppm != nullptr);
	}

	SUBCASE("Should throw an exception") {
		REQUIRE_THROWS_AS(ImageFactory::createImage("file.txt"), FileException);
	}
}
