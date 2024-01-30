#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* Input: The users guess, and the correct answer, as ints.
 Output: A string explaining the direction the user should look.
 Purpose: It compares the guess to the answer. If the guess is higher than
 the answer, it prompts to look lower. Else, it prompts higher. */
string giveHint(int guess, int ans) {
	if (guess > ans) {
 		return "Sorry! That's not it :( You should look lower!\n";
 	} else {
 		return "Sorry! That's not it :( You should look higher!\n";
 	}
}

/* Input: The limit of guesses, and how many guesses they've used, as ints.
 Output: A string saying how many guesses they have remaining.
 Purpose: It calculates the difference between the limit of guesses and how
 many the user has used. It returns this as a string. */
string guessesCalc(int limit, int guesses) {
 	return "You have " + to_string(limit - guesses) + " tries remaining.\n";
}

int main() {
 	// Initializes variables. I added timesGuessed to keep track of how many
 	// attempts the user has used.
 	int numberToGuess, numberGuessed, numberOfGuesses=3, timesGuessed = 0;
 	
	// Initialize random number
 	srand(time(NULL));
 	numberToGuess = rand() % 10 + 1;
 
	// This is the main while loop of the program, it will run as long as the
 	// amount of times the user has guessed is less than their limit.
 	while (timesGuessed < numberOfGuesses) {
		// This block prompts for the guess, stores that in the numberGuessed
 		// int, and then incrememnts the timesGuessed by 1.
 		cout << "Enter your guess: ";
		cin >> numberGuessed;
 		timesGuessed++;
 
		// The first if statement checks to see if they guessed correctly. If
 		// the user guessed correctly, it will display the number of attempts
 		// it took, then break out of the loop and end. 
 		// Else, they guessed incorrectly, and it will display their hint and
 		// how many attempts they have and continue to the next iteration. 
 		// Additionally, if it was their last guess and unsuccessful, it will tell
 		// them the correct number and better luck next time.
 		if (numberGuessed == numberToGuess) {
 			cout << "Congratulations! You guessed the number in " << timesGuessed << " tries!\n";
 			break;
 		} else {
 			cout << giveHint(numberGuessed, numberToGuess);
 			cout << guessesCalc(numberOfGuesses, timesGuessed);

 			if (numberOfGuesses - timesGuessed == 0) {
 				cout << "The number was " << numberToGuess << ". Better luck next time!\n";
 			}
 			continue;
 		}
 	}
	return 0;
}
