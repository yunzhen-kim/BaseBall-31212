#include <stdexcept>
#include <string>

using namespace std;

struct GuessResult {
	bool solved;
	int strike;
	int ball;
	GuessResult(bool solved, int strike, int ball) : solved{ solved }, strike{ strike }, ball{ ball } {}
};

class Baseball {
public:
	Baseball() = default;
	explicit Baseball(const string& question) : question{ question } {}

	GuessResult guess(const string& guessNumber) {
		return checkGuessNumberValidAndIfMatchedToQuestion(guessNumber);
	}
private:
	GuessResult checkGuessNumberValidAndIfMatchedToQuestion(const string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters");
		}
		for (char c : guessNumber) {
			if (c < '0' || c > '9') {
				throw invalid_argument("Input must be digits");
			}
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have duplicated number");
		}

		return checkGuessWithQueston(guessNumber);
	}

	bool isDuplicatedNumber(const string& guessNumber) {
		return (guessNumber[0] == guessNumber[1] || guessNumber[0] == guessNumber[2] || guessNumber[1] == guessNumber[2]);
	}

	GuessResult checkGuessWithQueston(const string& guessNumber) {
		GuessResult result{ false, 0, 0 };
		if (guessNumber == question) {
			result.solved = true;
			result.strike = 3;
		}
		else {
			for (int i = 0; i < 3; ++i) {
				if (guessNumber[i] == question[i]) ++result.strike;
				else ++result.ball;
			}
		}
		return result;
	}

	string question;
};