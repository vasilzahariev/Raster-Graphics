#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Raster Graphics/String/String.h"

TEST_CASE("String") {
	SUBCASE("Should create an empty String") {
		String str;

		CHECK(str.size() == 0);
		CHECK(str.capacity() == 2);
	}
}
