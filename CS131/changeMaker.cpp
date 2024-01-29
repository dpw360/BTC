#include <iostream>
#include <string>
using namespace std;

/* Input: A char representing which coin is being queried, and a reference to
an int representing how many cents remain to be paid back.
Output: An int representing how many of the queried coin need to be returned.
Purpose: The function is passed a refernce to how many cents remain to be
paid back, and what type of coin it should be paid in. This is done
by dividing the number of cents to be paid back by the value of the
coin specified and storing that in the numOfCoins int. Using the ref
to
the cents remaining to subtract the value about to be paid back, it
then returns to the user the amount of coins to be given. */
int calcChange(char coin, int &cents) {
	int tempCents = cents;
	int numOfCoins = 0;

	if (coin == 'q') {
		numOfCoins = tempCents / 25;
		cents -= numOfCoins * 25;
		return numOfCoins;
	} else if (coin == 'd') {
		numOfCoins = tempCents / 10;
		cents -= numOfCoins * 10;
		return numOfCoins;
	} else if (coin == 'n') {
		numOfCoins = tempCents / 5;
		cents -= numOfCoins * 5;
		return numOfCoins;
	} else if (coin == 'p') {
		numOfCoins = tempCents / 1;
		cents -= numOfCoins * 1;
		return numOfCoins;
	} else {
		return 0;
	}
}

int main() {
	// Five ints are initialized: centsOwed is how many cents need to be paid
	// back, and the rest are for the amount of coins that need to be given out
	// for each respective denomination.
	int centsOwed;
	int pennies, nickels, dimes, quarters;

	// This block captures how many cents are owed in the centsOwed int.
	cout << "How many cents are you owed? ";
	cin >> centsOwed;

	// This block calculates how many of each coin should be given out to give
	// the correct amount of change. We start with the largest coin, quarters,
	// and work our way down to pennies. With each call, since we are passing
	// a reference to centsOwed, the function takes care of decrementing the
	// centsOwed value.
	quarters = calcChange('q', centsOwed);
	dimes = calcChange('d', centsOwed);
	nickels = calcChange('n', centsOwed);
	pennies = calcChange('p', centsOwed);

	// This block uses the values calculated to output to the user the amount
	// of each coin they should hand back to the customer.
	cout << "You should recieve:\n" << quarters << " Quarters\n"
		<< dimes << " Dimes\n" << nickels << " Nickels\n"
		<< pennies << " Pennies\n";
	return 0;
}
