#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../ImageData/Matrix.h"

#include <cstdint>

typedef Matrix<std::uint16_t> BasicMatrix;
typedef Matrix<RGBData> VectorMatrix;

TEST_CASE("Basic Matrix") {
	SUBCASE("Should create an empty matrix") {
		BasicMatrix matrix;

		REQUIRE_EQ(matrix.getRows(), 0);
		REQUIRE_EQ(matrix.getCols(), 0);

		REQUIRE_THROWS_AS(matrix.getElementAt(0, 0), OutOfBoundsException);
	}

	SUBCASE("Should create a matrix filled with zeros") {		
		BasicMatrix matrix(2, 2);

		REQUIRE_EQ(matrix.getRows(), 2);
		REQUIRE_EQ(matrix.getCols(), 2);

		for (size_t row = 0; row < matrix.getRows(); ++row)
			for (size_t col = 0; col < matrix.getCols(); ++col)
				REQUIRE_EQ(matrix.getElementAt(row, col), 0);

		REQUIRE_THROWS_AS(matrix.getElementAt(2, 2), OutOfBoundsException);
	}

	SUBCASE("Should change the value of a matrix element") {
		BasicMatrix matrix(2, 3);

		unsigned counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
			}
		}

		counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				REQUIRE(matrix.getElementAt(row, col) == ++counter);
			}
		}
	}

	SUBCASE("Should resize the matrix") {
		BasicMatrix matrix(2, 3);

		unsigned counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
			}
		}

		counter = 0;

		matrix.resize(3, 5);

		REQUIRE_EQ(matrix.getRows(), 3);
		REQUIRE_EQ(matrix.getCols(), 5);
		REQUIRE_EQ(matrix.getElementAt(0, 0), 1);
		REQUIRE_EQ(matrix.getElementAt(0, 2), 3);
		REQUIRE_EQ(matrix.getElementAt(0, 4), 0);
		REQUIRE_EQ(matrix.getElementAt(1, 0), 4);
		REQUIRE_EQ(matrix.getElementAt(2, 0), 0);
		REQUIRE_THROWS(matrix.getElementAt(3, 0), 0);
	}

	SUBCASE("Rotate matrix right") {
		BasicMatrix matrix(2, 3);

		unsigned counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
			}
		}

		matrix.rotateRight();

		/*
		1 2 3
		4 5 6

		4 1
		5 2
		6 3
		*/

		REQUIRE_EQ(matrix.getRows(), 3);
		REQUIRE_EQ(matrix.getCols(), 2);
		REQUIRE_EQ(matrix.getElementAt(0, 0), 4);
		REQUIRE_EQ(matrix.getElementAt(0, 1), 1);
		REQUIRE_EQ(matrix.getElementAt(2, 0), 6);
		REQUIRE_EQ(matrix.getElementAt(2, 1), 3);
	}

	SUBCASE("Rotate matrix left") {
		BasicMatrix matrix(2, 3);

		unsigned counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
			}
		}

		matrix.rotateLeft();

		/*
		1 2 3
		4 5 6

		3 6
		2 5
		1 4
		*/

		REQUIRE_EQ(matrix.getRows(), 3);
		REQUIRE_EQ(matrix.getCols(), 2);
		REQUIRE_EQ(matrix.getElementAt(0, 0), 3);
		REQUIRE_EQ(matrix.getElementAt(0, 1), 6);
		REQUIRE_EQ(matrix.getElementAt(2, 0), 1);
		REQUIRE_EQ(matrix.getElementAt(2, 1), 4);
	}

	SUBCASE("Rotate matrix left * 2") {
		BasicMatrix matrix(2, 3);

		unsigned counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
			}
		}

		matrix.rotateLeft();
		matrix.rotateLeft();

		/*
		1 2 3
		4 5 6

		6 5 4
		3 2 1
		*/

		REQUIRE_EQ(matrix.getRows(), 2);
		REQUIRE_EQ(matrix.getCols(), 3);
		REQUIRE_EQ(matrix.getElementAt(0, 0), 6);
		REQUIRE_EQ(matrix.getElementAt(0, 2), 4);
		REQUIRE_EQ(matrix.getElementAt(1, 0), 3);
		REQUIRE_EQ(matrix.getElementAt(1, 2), 1);
	}

	SUBCASE("Should combine two matrixes horizontally") {
		BasicMatrix matrix(3, 3);
		BasicMatrix matrix2(2, 2);

		unsigned counter = 0;

		/*
		* M1:
		* 1 2 3
		* 4 5 6
		* 7 8 9
		* 
		* M2:
		* 2 4
		* 8 10
		*/

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
				if (row < 2 && col < 2)
					matrix2.getElementAt(row, col) = counter * 2;
			}
		}

		BasicMatrix out;

		out.combineHorizontally(matrix, matrix2);

		/*
		* out:
		* 1 2 3 2 4
		* 4 5 6 8 10
		* 7 8 9 0 0
		*/

		REQUIRE_EQ(out.getRows(), 5);
		REQUIRE_EQ(out.getCols(), 3);
		REQUIRE_EQ(out.getElementAt(0, 0), 1);
		REQUIRE_EQ(out.getElementAt(4, 1), 10);
		REQUIRE_EQ(out.getElementAt(4, 2), 0);
	}

	SUBCASE("Should combine two matrixes vertically") {
		BasicMatrix matrix(3, 3);
		BasicMatrix matrix2(2, 2);

		unsigned counter = 0;

		/*
		* M1:
		* 1 2 3
		* 4 5 6
		* 7 8 9
		*
		* M2:
		* 2 4
		* 8 10
		*/

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
				if (row < 2 && col < 2)
					matrix2.getElementAt(row, col) = counter * 2;
			}
		}

		BasicMatrix out;

		out.combineVertically(matrix, matrix2);

		/*
		* out:
		* 1 2 3 2 4
		* 4 5 6 8 10
		* 7 8 9 0 0
		*/

		REQUIRE_EQ(out.getRows(), 3);
		REQUIRE_EQ(out.getCols(), 5);
		REQUIRE_EQ(out.getElementAt(0, 0), 1);
		REQUIRE_EQ(out.getElementAt(1, 4), 10);
		REQUIRE_EQ(out.getElementAt(2, 2), 9);
		REQUIRE_EQ(out.getElementAt(2, 3), 0);
		REQUIRE_EQ(out.getElementAt(2, 4), 0);
	}
}

TEST_CASE("Vector Matrix") {
	SUBCASE("Should create an empty matrix") {
		VectorMatrix matrix;

		REQUIRE_EQ(matrix.getRows(), 0);
		REQUIRE_EQ(matrix.getCols(), 0);

		REQUIRE_THROWS_AS(matrix.getElementAt(0, 0), OutOfBoundsException);
	}

	SUBCASE("Should create a matrix filled with zeros") {
		VectorMatrix matrix(2, 2);

		REQUIRE_EQ(matrix.getRows(), 2);
		REQUIRE_EQ(matrix.getCols(), 2);

		for (size_t row = 0; row < matrix.getRows(); ++row)
			for (size_t col = 0; col < matrix.getCols(); ++col)
				REQUIRE(matrix.getElementAt(row, col) == RGBData(0, 0, 0));

		REQUIRE_THROWS_AS(matrix.getElementAt(2, 2), OutOfBoundsException);
	}

	SUBCASE("Should change the value of a matrix element") {
		VectorMatrix matrix(2, 3);

		unsigned counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
			}
		}

		counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				REQUIRE(matrix.getElementAt(row, col) == ++counter);
			}
		}
	}

	SUBCASE("Should resize the matrix") {
		VectorMatrix matrix(2, 3);

		unsigned counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
			}
		}

		counter = 0;

		matrix.resize(3, 5);

		REQUIRE_EQ(matrix.getRows(), 3);
		REQUIRE_EQ(matrix.getCols(), 5);
		REQUIRE_EQ(matrix.getElementAt(0, 0), 1);
		REQUIRE_EQ(matrix.getElementAt(0, 2), 3);
		REQUIRE_EQ(matrix.getElementAt(0, 4), 0);
		REQUIRE_EQ(matrix.getElementAt(1, 0), 4);
		REQUIRE_EQ(matrix.getElementAt(2, 0), 0);
		REQUIRE_THROWS(matrix.getElementAt(3, 0), 0);
	}

	SUBCASE("Rotate matrix right") {
		VectorMatrix matrix(2, 3);

		unsigned counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
			}
		}

		matrix.rotateRight();

		/*
		1 2 3
		4 5 6

		4 1
		5 2
		6 3
		*/

		REQUIRE_EQ(matrix.getRows(), 3);
		REQUIRE_EQ(matrix.getCols(), 2);
		REQUIRE_EQ(matrix.getElementAt(0, 0), 4);
		REQUIRE_EQ(matrix.getElementAt(0, 1), 1);
		REQUIRE_EQ(matrix.getElementAt(2, 0), 6);
		REQUIRE_EQ(matrix.getElementAt(2, 1), 3);
	}

	SUBCASE("Rotate matrix left") {
		VectorMatrix matrix(2, 3);

		unsigned counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
			}
		}

		matrix.rotateLeft();

		/*
		1 2 3
		4 5 6

		3 6
		2 5
		1 4
		*/

		REQUIRE_EQ(matrix.getRows(), 3);
		REQUIRE_EQ(matrix.getCols(), 2);
		REQUIRE_EQ(matrix.getElementAt(0, 0), 3);
		REQUIRE_EQ(matrix.getElementAt(0, 1), 6);
		REQUIRE_EQ(matrix.getElementAt(2, 0), 1);
		REQUIRE_EQ(matrix.getElementAt(2, 1), 4);
	}

	SUBCASE("Rotate matrix left * 2") {
		VectorMatrix matrix(2, 3);

		unsigned counter = 0;

		for (size_t row = 0; row < matrix.getRows(); ++row) {
			for (size_t col = 0; col < matrix.getCols(); ++col) {
				matrix.getElementAt(row, col) = ++counter;
			}
		}

		matrix.rotateLeft();
		matrix.rotateLeft();

		/*
		1 2 3
		4 5 6

		6 5 4
		3 2 1
		*/

		REQUIRE_EQ(matrix.getRows(), 2);
		REQUIRE_EQ(matrix.getCols(), 3);
		REQUIRE_EQ(matrix.getElementAt(0, 0), 6);
		REQUIRE_EQ(matrix.getElementAt(0, 2), 4);
		REQUIRE_EQ(matrix.getElementAt(1, 0), 3);
		REQUIRE_EQ(matrix.getElementAt(1, 2), 1);
	}
}
