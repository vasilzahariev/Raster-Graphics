//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../ImageData/RGBData.h"

#include <cstdint>
#include <string>

TEST_CASE("RGBData") {
	SUBCASE("Should construct a RGBData and all it's values should equal 0") {
		RGBData rgb;

		REQUIRE_EQ(rgb.red, 0);
		REQUIRE_EQ(rgb.green, 0);
		REQUIRE_EQ(rgb.blue, 0);
	}

	SUBCASE("Should construct a RGBData with the same value for red, green, blue") {
		RGBData rgb1 = 1;
		RGBData rgb2(2);

		REQUIRE_EQ(rgb1.red, 1);
		REQUIRE_EQ(rgb2.red, 2);
		REQUIRE_EQ(rgb1.green, 1);
		REQUIRE_EQ(rgb2.green, 2);
		REQUIRE_EQ(rgb1.blue, 1);
		REQUIRE_EQ(rgb2.blue, 2);
	}

	SUBCASE("Should construct a RGBData with given values for red, green, blue") {
		RGBData rgb(1, 2, 3);

		REQUIRE_EQ(rgb.red, 1);
		REQUIRE_EQ(rgb.green, 2);
		REQUIRE_EQ(rgb.blue, 3);
	}

	SUBCASE("Should copy RGBData") {
		RGBData rgb1 = 1;
		RGBData rgb2 = rgb1;
		RGBData rgb3 = 3;

		rgb2.red = 2;

		REQUIRE_FALSE(rgb2.red == 1);
		REQUIRE_EQ(rgb2.green, 1);
		REQUIRE_EQ(rgb2.blue, 1);

		rgb2 = rgb3;

		REQUIRE_EQ(rgb2.red, rgb3.red);
		REQUIRE_EQ(rgb2.green, rgb3.green);
		REQUIRE_EQ(rgb2.blue, rgb3.blue);
	}

	SUBCASE("Should check if two RGBDatas are equal") {
		RGBData rgb1(1, 2, 3);
		RGBData rgb2(2, 3, 4);
		RGBData rgb3(1, 3, 4);
		RGBData rgb4(1, 2, 4);
		RGBData rgb5(1, 2, 3);

		REQUIRE_FALSE(rgb1 == rgb2);
		REQUIRE_FALSE(rgb1 == rgb3);
		REQUIRE_FALSE(rgb1 == rgb4);
		REQUIRE(rgb1 == rgb5);
	}

	SUBCASE("Should transform the RGBData to grayscale") {
		RGBData rgb(25, 123, 12);

		rgb.transformToGrayscale();

		REQUIRE_EQ(rgb.red, 81);
		REQUIRE_EQ(rgb.green, 81);
		REQUIRE_EQ(rgb.blue, 81);
	}

	SUBCASE("Should normalize by value") {
		RGBData rgb(25, 123, 200);

		rgb.normalizeByValue(255);

		REQUIRE_EQ(rgb.red, 0);
		REQUIRE_EQ(rgb.green, 0);
		REQUIRE_EQ(rgb.blue, 1);
	}

	SUBCASE("Should get the negative of the RGBData by some value") {
		RGBData rgb(25, 123, 200);

		rgb.transformToNegative(255);

		REQUIRE_EQ(rgb.red, 230);
		REQUIRE_EQ(rgb.green, 132);
		REQUIRE_EQ(rgb.blue, 55);
	}
}
