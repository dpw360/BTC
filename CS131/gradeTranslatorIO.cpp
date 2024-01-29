#include <iostream>
#include <istream>
#include <fstream>
#include <string>
using namespace std;

// JUSTIN: If you'd like me to stop only commenting these and start doing a
// screen capture to narrate through, just let me know :) thanks again for
// your flexibility, it feels nice to get back into coding.

/*
Same gradeFromScore function from previous assignment. Int score goes in,
the grade is returned as a string.
*/
string gradeFromScore(int score) {
	if (score >= 90) {
		return "A";
	} else if (score >= 80) {
		return "B";
	} else if (score >= 70) {
		return "C";
	} else if (score >= 60) {
		return "D";
	} else {
		return "F";
	}
}

/*
Input: A string containing a line from the input file
Output: An int containing the score that the student from that line scored
Conditions: The line has to consist of a single name and an integer score,
separated by a space.
*/

int scoreFromLine(string line) {
	// The score string will contain the text of the score, and the secondWord
	// bool indicates if we've reached the second word of the line, the score.
	string score;
	bool secondWord = false;

	// This for loop iterates through the string char by char.
	for(int i = 0; i < line.size(); i++) {
		// This if statement checks if we have reached the second word of the
		// line, and if we have, append the curent char of line onto score.
		if (secondWord) {
		score += line[i];
		}

		// This if statement checks if the current char is a space, and if it
		// is, we know the next char will be the start of the second word. We
		// then set the secondWord bool to true, so the next loop iteration
		// will begin to store the second word.
		if (line[i] == ' ') {
			secondWord = true;
		}
	}

	// We translate the string score to an int and return it.
	return stoi(score);
}

int main() {
	// This opens an output stream object as output, and open it as a .txt file
	ofstream output;
	output.open("gradeTranslatorO.txt");

	// This opens an intput stream object as input, and open it as a .txt file
	ifstream input;
	input.open("gradeTranslatorI.txt");

	// This initializes the string that will contain each line of the input.
	string line = "";

	// This while loop is true so long as there is a line to read from the input
	// file. In checking that, it stores that line in the string 'line'. Using
	// scoreFromLine, we pull the score as an int from that line, translate that
	// into a grade using gradeFromScore, and use that. We output both to the
	// terminal and to the output file.
	while(getline(input, line)) {
		cout << line << " " << gradeFromScore(scoreFromLine(line)) << endl;
		output << line << " " << gradeFromScore(scoreFromLine(line)) << endl;
	}

	// Closing the files for good practice :)
	output.close();
	input.close();
	return 0;
}
