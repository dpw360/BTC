#include <iostream>
using namespace std;

int main() {
	// This block initializes the int that will hold the user's test score,
	// prompts the user for input, and stores that input in the variable.
	int testScore;
	cout << "what was your test score? ";
	cin >> testScore;

	// This if/else-if/else block compares the test score entered against set
	// benchmark scores. For instance, if it's 90 and above, it's an A. If it's
	// 80 and above AND below 90, it's a B, and so on. At the end, after we've
	// tested for a D grade, we know it's nothing above a D, so if it's not a D,
	// it's an F, hence the else instead of else-if.
	if (testScore >= 90) {
		cout << "A\n";
	} else if (testScore >= 80 && testScore < 90) {
		cout << "B\n";
	} else if (testScore >= 70 && testScore < 80) {
		cout << "C\n";
	} else if (testScore >= 60 && testScore < 70) {
		cout << "D\n";
	} else {
		cout << "F\n";
	}
	return 0;
}
