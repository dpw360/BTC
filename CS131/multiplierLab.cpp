#include <iostream>
using namespace std;

/* Input: Nothing
Output: int
Purpose: The function initializes an int variable called num. It then stores
the next user input to that variable, and returns that variable.*/
int getNumber() {
	int num;
	cin >> num;
	return num;
}

/* Input: Three ints, x, y, and z
Output: int
Purpose: The function takes in three ints, multiplies the first two, and
adds the third to that product. It then returns that answer.*/
int calculate(int x, int y, int z) {
	return (x * y) + z;
}

int main() {
	// Iniitalize the three ints we need, as well as the answer int.
	int num1, num2, num3;
	int answer;

	// This block prompts the user for their input, each time calling the
	// getNumber function to store their answer in the three variables.
	cout << "First Number: ";
	num1 = getNumber();
	cout << "Second Number: ";
	num2 = getNumber();
	cout << "Third Number: ";
	num3 = getNumber();

	// We call the calculate function to do the calculation, store that answer
	// in the answer variable, and use that to output the answer to the user.
	answer = calculate(num1, num2, num3);
	cout << "Answer: " << answer << "\n";
	return 0;
}
