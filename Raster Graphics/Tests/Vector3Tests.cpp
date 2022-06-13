#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Raster Graphics/Image/Vector3.h"

#include <cstdint>
#include <string>
#include <sstream>

TEST_CASE("Vector3") {
	SUBCASE("Should construct a 3D vector and all it's values should equal 0") {
		Vector3<std::uint16_t> vec;

		REQUIRE_EQ(vec.x, 0);
		REQUIRE_EQ(vec.y, 0);
		REQUIRE_EQ(vec.z, 0);
	}

	SUBCASE("Should construct a 3D vector with the same value for X, Y, Z") {
		Vector3<std::uint16_t> vec1 = 1;
		Vector3<std::uint16_t> vec2(2);

		REQUIRE_EQ(vec1.x, 1);
		REQUIRE_EQ(vec2.x, 2);
		REQUIRE_EQ(vec1.y, 1);
		REQUIRE_EQ(vec2.y, 2);
		REQUIRE_EQ(vec1.z, 1);
		REQUIRE_EQ(vec2.z, 2);
	}

	SUBCASE("Should construct a 3D vector with given values for X, Y, Z") {
		Vector3<std::uint16_t> vec(1, 2, 3);

		REQUIRE_EQ(vec.x, 1);
		REQUIRE_EQ(vec.y, 2);
		REQUIRE_EQ(vec.z, 3);
	}

	SUBCASE("Should copy vectors") {
		Vector3<std::uint16_t> vec1 = 1;
		Vector3<std::uint16_t> vec2 = vec1;
		Vector3<std::uint16_t> vec3 = 3;

		vec2.x = 2;
		
		REQUIRE_FALSE(vec2.x == 1);
		REQUIRE_EQ(vec2.y, 1);
		REQUIRE_EQ(vec2.z, 1);

		vec2 = vec3;

		REQUIRE_EQ(vec2.x, vec3.x);
		REQUIRE_EQ(vec2.y, vec3.y);
		REQUIRE_EQ(vec2.z, vec3.z);
	}

	SUBCASE("Should check if two vectors are equal") {
		Vector3<std::uint16_t> vec1(1, 2, 3);
		Vector3<std::uint16_t> vec2(2, 3, 4);
		Vector3<std::uint16_t> vec3(1, 3, 4);
		Vector3<std::uint16_t> vec4(1, 2, 4);
		Vector3<std::uint16_t> vec5(1, 2, 3);

		REQUIRE_FALSE(vec1 == vec2);
		REQUIRE_FALSE(vec1 == vec3);
		REQUIRE_FALSE(vec1 == vec4);
		REQUIRE(vec1 == vec5);
	}

	SUBCASE("Should read a vector from a stream") {
		std::string str = "52 23 32";
		std::istringstream input(str);
		Vector3<std::uint16_t> vec;

		vec.readFrom(input);

		REQUIRE_EQ(vec.x, 52);
		REQUIRE_EQ(vec.y, 23);
		REQUIRE_EQ(vec.z, 32);
	}

	SUBCASE("Should write a vector to a stream") {
		std::string str = "";
		std::ostringstream output(str);
		Vector3<std::uint16_t> vec(123, 342, 2);

		vec.writeTo(output);

		REQUIRE_EQ(output.str(), "123 342 2");
	}
}
