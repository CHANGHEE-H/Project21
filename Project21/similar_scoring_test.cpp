#include "similar_scoring.cpp"
#include "gmock/gmock.h"
#include <string>

using std::string;

class SimilarityFixture : public ::testing::Test {
public:
	SimilarityMeasurement app;
	void assertLengthCmp(const string& str1, const string& str2, int expected) {
		EXPECT_EQ(expected, app.cmpLength(str1, str2));
	}

	void assertAlphaCmp(const string& str1, const string& str2, int expected) {
		EXPECT_EQ(expected, app.cmpAlpha(str1, str2));
	}
};

TEST_F(SimilarityFixture, CompareSameLength) {
	assertLengthCmp("ASD", "DSA", 60);
}

TEST_F(SimilarityFixture, CompareALongLength) {
	assertLengthCmp("AAABB", "BAA", 20);
}

TEST_F(SimilarityFixture, CompareBLongLength) {
	assertLengthCmp("AA", "AAE", 30);
}

TEST_F(SimilarityFixture, Compare0Length) {
	assertLengthCmp("A", "BB", 0);
}

TEST_F(SimilarityFixture, CompareSameAlpha) {
	assertAlphaCmp("ASD", "DSA", 40);
}

TEST_F(SimilarityFixture, Compare0Alpha) {
	assertAlphaCmp("A", "BB", 0);
}

TEST_F(SimilarityFixture, CompareHalfAlpha) {
	assertAlphaCmp("AA", "AEEA", 20);
}
