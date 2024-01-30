#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Input: A single char.
Output: A bool that's true if the char is a vowel, otherwise false.
Purpose: We check the char against upper and lower case chars of vowels. If any
are a match, we return true. Otherwise, it's false.
*/
bool isVowel(char letter) {
	if (letter == 'a' || letter == 'A') {
		return true;
	} else if (letter == 'e' || letter == 'E') {
		return true;
	} else if (letter == 'i' || letter == 'I') {
		return true;
	} else if (letter == 'o' || letter == 'O') {
		return true;
	} else if (letter == 'u' || letter == 'u') {
		return true;
	} else {
		return false;
	}
}

/*
Input: A string of either the word or line that the user enters.
Output: An int of how many vowels are in that input
Purpose: We initialize an int that keeps tracks the vowel count, initialized at
zero. We then loop through the input char by char, using the isVowel
function to determine if it's a vowel. If it is, we increment the sum.
*/
int countVowels(string input) {
	int sumOfVowels = 0;

	for (int i = 0; i < input.size(); i++) {
		if (isVowel(input[i])) {
			sumOfVowels++;
		}
	}
	return sumOfVowels;
}

/*
Input: A string of either the word or line that the user enters
Output: An int of how many y's are in that input
Purpose: If the input doesn't contain any vowels, and there's one or more y's in
it, this function is called. It initializes the sum of y's to 0, and
iterates through the input char by char, checking against upper and
lowercase y's. If it matches, we increment the sum.
*/
int howManyYs(string input) {
	int sumOfYs = 0;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'y' || input[i] == 'Y') {
			sumOfYs++;
		}
	}
	return sumOfYs;
}

int main() {
	//////////////////////////////
	//       WORD SECTION       //
	//////////////////////////////

	// We initialize the string variable the word will be stored in, and put
	// the user's input into it.
	string word;
	cout << "Please enter a word: ";
	cin >> word;

	// We check how many vowels are in the word, and y's, and store them into
	// their respective variables. I just pre-count the y's here so we don't
	// have to do any checks within the if block up ahead.
	int vowelsInWord = countVowels(word);
	int ysInWord = howManyYs(word);

	// This if block controls the output format that we have, first broken up
	// into if the word has no vowels and 1 y, then no vowels and more than 1 y.
	// Then it's if the word has 1 vowel, and then more than 1 vowel. If the
	// word has no vowels or y's, the final output is reached.
	if (vowelsInWord == 0 && ysInWord == 1) {
		cout << "Whoah! That word doesn't have any vowels :( But it does have " << ysInWord << " y, which is pretty cool if you ask me!\n";
	} else if (vowelsInWord == 0 && ysInWord > 1) {
		cout << "Whoah! That word doesn't have any vowels :( But it does have " << ysInWord << " y\'s, which is pretty cool if you ask me!\n";
	} else if (vowelsInWord == 1) {
		cout << "There is " << vowelsInWord << " vowel in " << word << ".\n";
	} else if (vowelsInWord > 1) {
		cout << "There are " << vowelsInWord << " vowels in " << word << ".\n";
	} else {
		cout << "That word has no vowels, and no y\'s in it! That's impressive, you get a gold star ----> *\n";
	}

	// This block asks if the user would like the program to highlight the
	// vowels, storing this decision in the string var.
	string highlightDecision = "n";
	cout << "Would you like me to highlight the vowels in that word? (y/n) ";
	cin >> highlightDecision;

	// This block does the highlighting if they opt for it. It checks the
	// decision var, if it's no, it skips this and goes to the sentence. If yes,
	// we create a vector of chars. We iterate through the chars of the word,
	// and check if the current char is a vowel. If it is, add pound symbols
	// on either side of the char when it's added to the vector. Otherwise,
	// just add the char to the vector. We don't check for y's, this only
	// highlights true vowels.
	if (highlightDecision == "y" || highlightDecision == "Y" || highlightDecision == "yes") {
		vector<char> vectorOfWord;
		for (int i = 0; i < word.size(); i++) {
			if (isVowel(word[i])) {
				vectorOfWord.push_back('|');
				vectorOfWord.push_back(word[i]);
				vectorOfWord.push_back('|');
			} else {
				vectorOfWord.push_back(word[i]);
			}
		}

		// Because the vector is just a copy of the word essentially, with some
		// pound symbols thrown in, we can iterate through it and print it out
		// just like normal.
		cout << "Here ya go!\n";
		for (int i = 0; i < vectorOfWord.size(); i++) {
			cout << vectorOfWord[i];
		}
	}

	//////////////////////////////
	//     SENTENCE SECTION     //
	//////////////////////////////

	// After the word section, we move on to the user entering a whole line
	// of text, rather than a word. The only things that change are the names
	// of the variables (from word to line usually), the way we get the line,
	// and I also decided to do a different method of highlighting. I'll comment
	// on those changes.
	// To get the line, we first wipe out the previous \n character from the
	// input, and then use the getline() function to store a whole line of input
	// into the line variable.
	string line;
	cout << "\n\nGood job! Now enter a whole line, I can handle it:\n";
	cin.ignore();
	getline(cin, line);

	int vowelsInLine = countVowels(line);
	int ysInLine = howManyYs(line);

	if (vowelsInLine == 0 && ysInLine == 1) {
		cout << "Whoah! That line doesn't have any vowels :( But it does have " << ysInLine << " y, which is pretty cool if you ask me!\n";
	} else if (vowelsInLine == 0 && ysInLine > 1) {
		cout << "Whoah! That line doesn't have any vowels :( But it does have " << ysInLine << " y\'s, which is pretty cool if you ask me!\n";
	} else if (vowelsInLine == 1) {
		cout << "There is " << vowelsInLine << " vowel in that line.\n";
	} else if (vowelsInLine > 1) {
		cout << "There are " << vowelsInLine << " vowels in that line.\n";
	} else {
		cout << "That line has no vowels, and no y\'s in it! That's impressive, you get a gold star ----> *\n";
	}

	string highlightDecisionLine = "n";
	cout << "Would you like me to highlight the vowels in that line? (y/n) ";
	cin >> highlightDecisionLine;

	// I decided to try a different method of highlighting here. If it's an
	// affirmative, I create an empty string. I then iterate through the line,
	// checing if each char is a vowel. If it is, I add a pound symbol to the
	// highlighter variable, otherwise I add a space. This also doesn't check
	// for y's, it only highlights true vowels.
	if (highlightDecisionLine == "y" || highlightDecisionLine == "Y" || highlightDecisionLine == "yes") {
		string highlighter = "";
		for (int i = 0; i < line.size(); i++) {
			if (isVowel(line[i])) {
				highlighter += "#";
			} else {
				highlighter += " ";
			}
		}

	// By displaying this highlighter variable directly above and below the
	// line, it acts as a highlighter for the vowels! As long as it's a
	// monospace font, I suppose...
	cout << "Here ya go!\n";
	cout << highlighter << endl << line << endl << highlighter << endl;
	}

	return 0;
}
