#include <iostream>
using namespace std;

/*
Input: An array of ints of the scores, and how many scores there are.
Output: An int of the average score.
Purpose: A simple averaging function, summing the scores then dividing by how
many scores there were.
*/
int averageScore(int scores[], int numOfTests) {
	int sum = 0;
	for (int i = 0; i < numOfTests; i++) {
		sum += scores[i];
	}
	return sum / numOfTests;
}

/*
Input: An array of ints of the scores, and how many scores there are.
Output: The minimum score in the array.
Purpose: Create an int that keeps track of the lowest score currently seen. If
it's the first element we check, it will always take that as the min.
It will test every iteration if the score being checked is lower than
the current min. If it is, it updates, and continues iterating, until
we've checked all the scores. We then return the min score.
*/
int minScore(int scores[], int numOfTests) {
	int currentMinScore;
	for (int i = 0; i < numOfTests; i++) {
		// The '|| i == 0' is to ensure that at least one score is set as min
		if (scores[i] < currentMinScore || i == 0) {
			currentMinScore = scores[i];
		}
	}
	return currentMinScore;
}

/*
Input: An array of ints of the scores, and how many scores there are.
Output: The maximum score in the array.
Purpose: Create an int that keeps track of the highest score currently seen. If
it's the first element we check, it will always take that as the max.
It will test every iteration if the score being checked is higher than
the current max. If it is, it updates, and continues iterating, until
we've checked all the scores. We then return the max score.
*/
int maxScore(int scores[], int numOfTests) {
	int currentMaxScore;
	for (int i = 0; i < numOfTests; i++) {
		// The '|| i == 0' is to ensure that at least one score is set as max
		if (scores[i] > currentMaxScore || i == 0) {
			currentMaxScore = scores[i];
		}
	}
	return currentMaxScore;
}

/*
Input: An array of ints of the scores, an array of strings of the students'
names, and ints of the minimum score and the number of test scores.
Output: The name of the student(s) who scored the lowest.
Purpose: Create an empty string that will hold the name(s) of the lowest test
taker(s). For each score in the scores array, we check if that score is
equal to the minimum score. If it is, we add the name that is
associated with that score to the minName string, and return it after
the last iteration.
*/
string whoGotMin(int scores[], string names[], int minScore, int numOfTests) {
	string minName = "";
	for (int i = 0; i < numOfTests; i++) {
		if (scores[i] == minScore) {
			minName += names[i] + " ";
		}
	}
	return minName;
}

/*
Input: An array of ints of the scores, an array of strings of the students'
names, and ints of the maximum score and the number of test scores.
Output: The name of the student(s) who scored the highest.
Purpose: Create an empty string that will hold the name(s) of the highest test
taker(s). For each score in the scores array, we check if that score is
equal to the maximum score. If it is, we add the name that is
associated with that score to the maxName string, and return it after
the last iteration.
*/
string whoGotMax(int scores[], string names[], int maxScore, int numOfTests) {
	string maxName = "";
	for (int i = 0; i < numOfTests; i++) {
		if (scores[i] == maxScore) {
			maxName += names[i] + " ";
		}
	}
return maxName;
}

/*
Input: An array of ints of the scores, an array of strings of the names, and
ints of the average score and the number of scores.
Output: A string of the name who scored the closest to the average.
Purpose: Initialize a string that will hold the name. Initialize an int of the
closest difference between the scores and the average. We calculate
the difference from the average score for each score, and check if it's
the new closest score, or the first score to be checked. If it is, we
set that score as the new closest score, and set the name associated
with that score as the student who is closest.
*/
string whoGotAverage(int scores[], string names[], int average, int numOfTests) {
	string closestToAverageName = "";
	int currentDif;

	for (int i = 0; i < numOfTests; i++) {
		int dif = average - scores[i];

		// This will always keep the integer difference positive.
		if (dif < 0) {
			dif *= -1;
		}

		if (dif < currentDif || i == 0) {
			currentDif = dif;
			closestToAverageName = names[i];
		}
	}
	return closestToAverageName;
}

int main() {
	// This will ask how big to make the array, essentially, as arrays are not
	// dynamically allocated. I read that it's not to difficult to create a
	// pseudo-dynamic array using pointers or vectors, but that's not required
	// here, so I figured this works.
	int arrSize = 0;
	cout << "How many test scores do you have to enter? ";
	cin >> arrSize;

	// We initialize the two arrays we'll be using, one for the test scores, and
	// one for the names of the students. They will be updated at the same time,
	// so testScores[i] will be the test score of the student in studentNames[i].
	int testScores[arrSize];
	string studentNames[arrSize];

	// This for loop asks the user for each name and associated score, which are
	// allocated into their respective arrays as the loop continues.
	for (int i = 0; i < arrSize; i++) {
		cout << "Enter the student name #" << i + 1 << ": ";
		cin >> studentNames[i];
		cout << "Enter test score #" << i + 1 << ": ";
		cin >> testScores[i];
	}

	// We initialize all the variables we will need. The ints all hold their
	// respective scores, and the strings all hold their respective names.
	int average, min, max;
	string averageStudent, minStudent, maxStudent;

	// This block calculates the average, min, and max test scores.
	average = averageScore(testScores, arrSize);
	min = minScore(testScores, arrSize);
	max = maxScore(testScores, arrSize);

	// This block calculates the student(s) who scored the average, min, and
	// max scores. We do this by using the values we just calculated.
	averageStudent = whoGotAverage(testScores, studentNames, average, arrSize);
	minStudent = whoGotMin(testScores, studentNames, min, arrSize);
	maxStudent = whoGotMax(testScores, studentNames, max, arrSize);

	// This block outputs the results.
	cout << "\nThe average score is a " << average << endl;
	cout << "The minimum score is a " << min << endl;
	cout << "The maximum score is a " << max << endl;
	cout << "\nThe student(s) who scored the lowest: " << minStudent << endl;
	cout << "The student(s) who scored the highest: " << maxStudent << endl;
	cout << "The student who score the closest to the average: " << averageStudent << endl;
	return 0;
}
