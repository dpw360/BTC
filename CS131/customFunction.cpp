#include <iostream>
#include <string>
using namespace std;

/* Input: An integer representing the score the user got, possibly curved.
Output: A string representing the final grade the user got.
Purpose: Compare the score with the grade ranges to assign a letter grade.
We call this after the score has been adjusted to curve. */
string gradeCalculator(int grade) {
	if (grade >= 90) {
		return "A";
	} else if (grade >= 80 && grade < 90) {
		return "B";
	} else if (grade >= 70 && grade < 80) {
		return "C";
	} else if (grade >= 60 && grade < 70) {
		return "D";
	} else {
		return "F";
	}
}

/* Input: A string representing the user's choice of whether to curve or not.
Output: An int representing the curve amount, initialized to 0.
Purpose: If the user enters an affirmative, they will be prompted to
enter the curve amount. It will then overwrite the curveAmt int
with that value, and return it.
If they entered anything else, it will return the initialized
curveAmt, which should be zero.
If we wanted to validate the user's entry, we could do function
overloading and handle all possible incoming types, or use exceptions,
but I figured this is enough for this assignment :) */
	int curve(string option) {
	int curveAmt = 0;

	if (option == "y" || option == "Y" || option == "yes" || option == "Yes" || option == "YES") {
		cout << "Enter the curve amount as an integer: ";
		cin >> curveAmt;
		return curveAmt;
	} else {
		return curveAmt;
	}
}

int main() {
	// These are all the vaiables we need. Ints for the user's score and the
	// curve amount, and strings for their curve option and final grade. Score
	// represents their raw score, curveAmt represents the curve correction.
	// curveOption represents the user's selection to curve or not, and
	// finalGrade represents the final letter grade post-curving.
	int score, curveAmt;
	string curveOption, finalGrade;

	// This block prompts the user to enter their raw score, storing in score.
	cout << "Enter your score: ";
	cin >> score;

	// This block asks the user if the scoring is curved, storing in curveOption.
	cout << "Is the scoring curved (y/n): ";
	cin >> curveOption;

	// This block calculates the curve amount using the curve function, and
	// uses that curve amount in conjunction with their raw score to calculate a
	// final grade, using the gradeCalculator function.
	curveAmt = curve(curveOption);
	finalGrade = gradeCalculator(score + curveAmt);

	// This line outputs the final grade to the user.
	cout << "You score is: " << finalGrade << "\n";
	
	return 0;
}
