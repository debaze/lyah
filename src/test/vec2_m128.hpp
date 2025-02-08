#pragma once

#include "pch.hpp"

namespace vec2_m128 {
	void testDefaultConstructor() {
		const std::float_t expected[2] = {0.0f, 0.0f};

		const lyah::vec<2, std::float_t> result;

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testComponentConstructor() {
		const std::float_t expected[2] = {1.0f, 4.0f};

		const lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testSimdConstructor() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 4.0f};
		const __m128 m = _mm_set_ps(0.0f, 0.0f, 4.0f, 1.0f);

		const lyah::vec<2, std::float_t> result(m);

		test::assert(test::eq(result, expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 4.0f};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};

		const lyah::vec<2, std::float_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> b = {1.0f, 0.0f};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> b = {1.0f, 0.0f};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const lyah::vec<2, std::float_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::vec<2, std::float_t> expected = {-1.0f, -4.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const lyah::vec<2, std::float_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::vec<2, std::float_t> expected = {6.0f, 7.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> b = {5.0f, 3.0f};

		const lyah::vec<2, std::float_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<2, std::float_t> expected = {6.0f, 7.0f};
		const lyah::vec<2, std::float_t> a = {5.0f, 3.0f};
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::vec<2, std::float_t> expected = {-4.0f, 1.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> b = {5.0f, 3.0f};

		const lyah::vec<2, std::float_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<2, std::float_t> expected = {-4.0f, 1.0f};
		const lyah::vec<2, std::float_t> a = {5.0f, 3.0f};
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAB() {
		const lyah::vec<2, std::float_t> expected = {3.0f, 12.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const std::float_t b = 3.0f;

		const lyah::vec<2, std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationBA() {
		const lyah::vec<2, std::float_t> expected = {3.0f, 12.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const std::float_t b = 3.0f;

		const lyah::vec<2, std::float_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAssignment() {
		const lyah::vec<2, std::float_t> expected = {3.0f, 12.0f};
		const std::float_t a = 3.0f;
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testMultiplication() {
		const lyah::vec<2, std::float_t> expected = {5.0f, 12.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> b = {5.0f, 3.0f};

		const lyah::vec<2, std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testMultiplicationAssignment() {
		const lyah::vec<2, std::float_t> expected = {5.0f, 12.0f};
		const lyah::vec<2, std::float_t> a = {5.0f, 3.0f};
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarDivisionAB() {
		const lyah::vec<2, std::float_t> expected = {0.333f, 1.333f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const std::float_t b = 3.0f;

		const lyah::vec<2, std::float_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testScalarDivisionBA() {
		const lyah::vec<2, std::float_t> expected = {lyah::infinity<std::float_t>(), 0.75f};
		const lyah::vec<2, std::float_t> a = {0.0f, 4.0f};
		const std::float_t b = 3.0f;

		const lyah::vec<2, std::float_t> result = b / a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testScalarDivisionAssignment() {
		const lyah::vec<2, std::float_t> expected = {0.333f, 1.333f};
		const std::float_t a = 3.0f;
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testDivision() {
		const lyah::vec<2, std::float_t> expected = {lyah::infinity<std::float_t>(), 1.333f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> b = {0.0f, 3.0f};

		const lyah::vec<2, std::float_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testDivisionAssignment() {
		const lyah::vec<2, std::float_t> expected = {lyah::infinity<std::float_t>(), 1.333f};
		const lyah::vec<2, std::float_t> a = {0.0f, 3.0f};
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	/* void testFloor() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> a = {1.999f, 4.0f};

		const lyah::vec<2, std::float_t> result = lyah::floor(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testCeil() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> a = {0.999f, 4.0f};

		const lyah::vec<2, std::float_t> result = lyah::ceil(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testRound() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> a = {1.3279f, 4.007f};

		const lyah::vec<2, std::float_t> result = lyah::round(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testAbs() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, -4.0f};

		const lyah::vec<2, std::float_t> result = lyah::abs(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testSign() {
		const lyah::vec<2, std::float_t> expected = {1.0f, -1.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, -4.0f};

		const lyah::vec<2, std::float_t> result = lyah::sign(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testHorizontalMax() {
		const std::float_t expected = 4.0f;
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const std::float_t result = lyah::max(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testHorizontalMin() {
		const std::float_t expected = 1.0f;
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const std::float_t result = lyah::min(a);

		test::assert(test::eq(result, expected));
	} */

	void testVerticalMax() {
		const lyah::vec<2, std::float_t> expected = {5.0f, 4.0f};
		const lyah::vec<2, std::float_t> a = {5.0f, 3.0f};
		const lyah::vec<2, std::float_t> b = {1.0f, 4.0f};

		const lyah::vec<2, std::float_t> result = lyah::max(a, b);

		test::assert(test::eq(result, expected));
	}

	void testVerticalMin() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 3.0f};
		const lyah::vec<2, std::float_t> a = {5.0f, 3.0f};
		const lyah::vec<2, std::float_t> b = {1.0f, 4.0f};

		const lyah::vec<2, std::float_t> result = lyah::min(a, b);

		test::assert(test::eq(result, expected));
	}

	void testLerp() {
		const lyah::vec<2, std::float_t> expected = {2.2f, 3.7f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> b = {5.0f, 3.0f};
		const std::float_t t = 0.3f;

		const lyah::vec<2, std::float_t> result = lyah::lerp(a, b, t);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testSum() {
		const std::float_t expected = 5.0f;
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const std::float_t result = lyah::sum(a);

		test::assert(test::eq(result, expected));
	}

	void testPow() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 64.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> b = {5.0f, 3.0f};

		const lyah::vec<2, std::float_t> result = lyah::pow(a, b);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testRcp() {
		const lyah::vec<2, std::float_t> expected = {lyah::infinity<std::float_t>(), 0.25f};
		const lyah::vec<2, std::float_t> a = {0.0, 4.0};

		const lyah::vec<2, std::float_t> result = lyah::rcp(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testSqrt() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 2.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const lyah::vec<2, std::float_t> result = lyah::sqrt(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testRsqrt() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 0.5f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const lyah::vec<2, std::float_t> result = lyah::rsqrt(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testDotProduct() {
		const std::float_t expected = 17.0f;
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> b = {5.0f, 3.0f};

		const std::float_t result = lyah::dot(a, b);

		test::assert(test::eq(result, expected));
	}

	void testLength() {
		const std::float_t expected = 4.123f;
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const std::float_t result = lyah::length(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testDistance() {
		const std::float_t expected = 4.123f;
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> b = {5.0f, 3.0f};

		const std::float_t result = lyah::distance(a, b);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testNormalization() {
		const lyah::vec<2, std::float_t> expected = {0.243f, 0.970f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const lyah::vec<2, std::float_t> result = lyah::normalized(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void runAll() {
		test::printTestCategory("lyah::vec<2, std::float_t> - 2-component single floating-point vector");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testSimdConstructor, "SIMD constructor");
		test::runTest(&testConvertingConstructor, "Converting constructor");

		test::runTest(&testEquality, "Equality (==)");
		test::runTest(&testInequality, "Inequality (!=)");

		test::runTest(&testUnaryPlus, "Unary plus (+)");
		test::runTest(&testUnaryMinus, "Unary minus (-)");

		test::runTest(&testAddition, "Addition (+)");
		test::runTest(&testAdditionAssignment, "Addition assignment (+=)");

		test::runTest(&testSubtraction, "Subtraction (-)");
		test::runTest(&testSubtractionAssignment, "Subtraction assignment (-=)");

		test::runTest(&testScalarMultiplicationAB, "Scalar multiplication (*) - AB");
		test::runTest(&testScalarMultiplicationBA, "Scalar multiplication (*) - BA");
		test::runTest(&testScalarMultiplicationAssignment, "Scalar multiplication assignment (*=)");
		test::runTest(&testMultiplication, "Multiplication (*)");
		test::runTest(&testMultiplicationAssignment, "Multiplication assignment (*=)");

		test::runTest(&testScalarDivisionAB, "Scalar division (/) - AB");
		test::runTest(&testScalarDivisionBA, "Scalar division (/) - BA");
		test::runTest(&testScalarDivisionAssignment, "Scalar division assignment (/=)");
		test::runTest(&testDivision, "Division (/)");
		test::runTest(&testDivisionAssignment, "Division assignment (/=)");

		// test::runTest(&testFloor, "Floor");
		// test::runTest(&testCeil, "Ceil");
		// test::runTest(&testRound, "Round");
		// test::runTest(&testAbs, "Abs");
		// test::runTest(&testSign, "Sign");
		// test::runTest(&testHorizontalMax, "Horizontal max");
		// test::runTest(&testHorizontalMin, "Horizontal min");
		test::runTest(&testVerticalMax, "Vertical max");
		test::runTest(&testVerticalMin, "Vertical min");
		test::runTest(&testLerp, "Linear interpolation");
		test::runTest(&testSum, "Sum");

		test::runTest(&testPow, "Power");
		test::runTest(&testRcp, "Reciprocal");
		test::runTest(&testSqrt, "Square root");
		test::runTest(&testRsqrt, "Inverse square root");

		test::runTest(&testDotProduct, "Dot product");
		test::runTest(&testLength, "Length");
		test::runTest(&testDistance, "Distance");
		test::runTest(&testNormalization, "Normalization");
	}
}