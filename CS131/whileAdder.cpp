#include <iostream>
using namespace std;

int main() {
	// I use the stop boolean to control the while loop. As long as stop is
	// false, it will keep running. The int sum keeps track of the total,
	// starting at 0.
	bool stop = false;
	int sum = 0;

	// This is the main while loop. As long as stop == false, it will run.
	while (!stop) {
		// I use a new temporary int every iteration to store the user input.
		int tempInput;

		// This block asks for a number, stores that number in tempInput, and
		// then adds that number to the sum int.
		cout << "Enter a number to add, or enter 0 to stop: ";
		cin >> tempInput;
		sum += tempInput;

		// If the temp input is 0, the user wants to end the program. I print
		// out the final sum, and set stop to true, so the loop will end. Else,
		// the loop will run again, displaying the new total each time.
		if (tempInput == 0) {
			cout << "Final Total: " << sum << "\nProgram Stopped\n";
			stop = true;
		} else {
			cout << "New Total: " << sum << "\n\n";
		}
	}
	return 0;
}
