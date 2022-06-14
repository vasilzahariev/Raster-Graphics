#include "doctest.h"
#include "../Command/CommandParser.h"

TEST_CASE("Command Parser") {
	SUBCASE("Open Command") {
		CommandParser::parseCommandLine("open img1.ppm");

		REQUIRE(true);
	}
}
