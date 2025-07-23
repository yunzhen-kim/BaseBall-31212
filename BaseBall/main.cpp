#include <gmock/gmock.h>
#include "baseball.cpp"

class BaseballFixture : public ::testing::Test {
public:
	Baseball game{ "123" };
	void assertIllegalArgumane(string input) {
		try {
			game.guess(input);
			FAIL();
		}
		catch (exception& e) {
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgumane("12");
	assertIllegalArgumane("12s");
	assertIllegalArgumane("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(result.strike, 3);
	EXPECT_EQ(result.ball, 0);
}

int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}