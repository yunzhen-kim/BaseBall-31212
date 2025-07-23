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

TEST_F(BaseballFixture, ReturnSolvedResult2Strike1Ball1st) {
	GuessResult result = game.guess("023");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strike, 2);
	EXPECT_EQ(result.ball, 1);
}

TEST_F(BaseballFixture, ReturnSolvedResult2Strike1Ball2nd) {
	GuessResult result = game.guess("129");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strike, 2);
	EXPECT_EQ(result.ball, 1);
}

TEST_F(BaseballFixture, ReturnSolvedResult1Strike2Ball1st) {
	GuessResult result = game.guess("138");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strike, 1);
	EXPECT_EQ(result.ball, 2);
}

TEST_F(BaseballFixture, ReturnSolvedResult1Strike2Ball2nd) {
	GuessResult result = game.guess("027");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strike, 1);
	EXPECT_EQ(result.ball, 2);
}

TEST_F(BaseballFixture, ReturnSolvedResult3Ball) {
	GuessResult result = game.guess("301");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strike, 0);
	EXPECT_EQ(result.ball, 3);
}

int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}