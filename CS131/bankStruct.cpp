#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// This creates the stuct of BankAcct, with two members, a string for the acct
// name and a double for the balance.
struct BankAcct {
	string name = "";
	double balance = 0.0;
};

// Throughout these comments, I'm going to refer to the vector of BankAcct
// structs as the 'database'.

/*
Input: A vector of BankAcct structures.
Output: The sum of all the balances of the accounts in the vector.
Purpose: We create a double to keep track of the total. We then iterate through
the vector, adding the balance to the total, and return total.
*/
double getTotal (vector<BankAcct> database) {
	double total = 0.0;
	for (int i = 0; i < database.size(); i++) {
		total += database[i].balance;
	}
	return total;
}

/*
Input: A vector of BankAcct structures.
Output: Void.
Purpose: We loop through the database, and as long as the name of the BankAcct
isn't empty, we display the information of that BankAcct. We also
display a number to the left of it that the user can use to interact
with the accounts. Because vectors maintain their item order, we can
consistently use this to reference the account that the user sees. We
call this number the Account ID, and it will always be the position of
the struct in the vector + 1. Thus when we use it when the user enters
an Account ID, we will always subtract 1 to reference.
*/
void displayAccounts(vector<BankAcct> database) {
	cout << "ID | ACCOUNT | BALANCE\n";
	for (int i = 0; i < database.size(); i++) {
		// The string(14 - database[i].name.size(), ' ') line basically ensures
		// even spacing in the display between the account name and balance.
		if (database[i].name != "") {
			cout << i + 1 << " " << database[i].name <<
				string(14 - database[i].name.size(), ' ') <<
				database[i].balance << endl;
		}
	}
	return;
}

/*
Input: A vector of BankAcct structures, passed by reference. This allows us to
modify the values of the objects within the vector without returning any
values.
Output: Void.
Purpose: We ask which account they would like to deposit into, and store that in
the int depositID. We then check that the depositID is valid, checking
that it's above zero, and under or equal to the amount of accounts. If
it is, we ask how much they want to deposit, store it in the depositAmt
double, modify the balance of that account accordingly, and display the
new balance. If the depositID is invalid, we say so.
*/
void deposit(vector<BankAcct> &database) {
	int depositID = 0;
	cout << "Which Account ID would you like to make a deposit into? ";
	cin >> depositID;
	if (depositID > 0 && depositID <= database.size()) {
		double depositAmt = 0;
		cout << "How much are you depositing? $";
		cin >> depositAmt;
		database[depositID - 1].balance += depositAmt;
		cout << "Your new balance in " << database[depositID - 1].name << " is $" << database[depositID - 1].balance << endl << endl;
		return;
	} else {
		cout << "Sorry, it looks like that Account ID is invalid :( Please try again!\n\n";
		return;
	}
}

/*
Input: A vector of BankAcct structures, passed by reference. This allows us to
modify the values of the objects within the vector without returning any
values.
Output: Void.
Purpose: We ask which account they would like to withdraw from, how much they
would like to withdraw, and store those in their respective variables.
We then check that the withdrawID is valid, checking that it's above zero,
and under or equal to the amount of accounts. We then check that there's
enough money in the account to withdraw. If it is, we modify the balance
of that account accordingly, and display the new balance. If either of
those checks fail, we say so and return.
*/
void withdraw(vector<BankAcct> &database) {
	int withdrawID = 0;
	cout << "Which Account ID would you like to withdraw from? ";
	cin >> withdrawID;

	double withdrawAmt = 0;
	cout << "How much are you withdrawing? $";
	cin >> withdrawAmt;

	// Check selection validity, then funds availability.
	if (withdrawID > 0 && withdrawID <= database.size()) {
		if (database[withdrawID - 1].balance >= withdrawAmt) {
			database[withdrawID - 1].balance -= withdrawAmt;
			cout << "Your new balance is $" << database[withdrawID - 1].balance << endl << endl;
			return;
		} else {
			cout << "\nSorry, it looks like that account doesn't have enough funds to withdraw :( Please try again!\n\n";
		}
	} else {
		cout << "Sorry, it looks like that Account ID is invalid :( Please try again!\n\n";
		return;
	}
}

/*
Input: A vector of BankAcct structures, passed by reference. This allows us to
modify the values of the objects within the vector without returning any
values.
Output: Void.
Purpose: We ask which account they would like to transfer to and from, as well as
how much they would like to transfer, and store them in their respective
variables. We then check that the deposit and withdraw ID's are valid.
If they're not, we say so and return. If they are, we then check if the
account we're pulling from has the funds to cover it. If they don't we
say so and return. If they do, we adjust the funds in each account.
*/
void transfer(vector<BankAcct> &database) {
	int transferWithdrawID = 0;
	cout << "Which Account ID would you like to transfer from? ";
	cin >> transferWithdrawID;

	int transferDepositID = 0;
	cout << "Which Account ID would you like to transfer to? ";
	cin >> transferDepositID;

	double transferAmt = 0;
	cout << "How much would you like to transfer? $";
	cin >> transferAmt;

	// Check selection validity, then funds availability.
	if (0 < transferWithdrawID && transferWithdrawID <= database.size() && 0 <
		transferDepositID && transferDepositID <= database.size()) {
		if (database[transferWithdrawID - 1].balance > transferAmt) {
			// Subtract from withdraw account
			database[transferWithdrawID - 1].balance -= transferAmt;
			// Deposit to deposit account
			database[transferDepositID - 1].balance += transferAmt;
			cout << endl;
			return;
		} else {
			cout << "\nSorry, it looks like that account doesn't have enough fund to transfer :( Please try again!\n\n";
			return;
		}
	} else {
		cout << "Sorry, it looks like one of those Account ID's is invalid :( Please try again!\n\n";
		return;
	}
}

/*
Input: A vector of BankAcct structures, passed by reference. This allows us to
modify the values of the objects within the vector without returning any
values.
Output: Void.
Purpose: We ask what they would like to name the account, and store that in the
newAcctName string (by using getline the name can have spaces). We then
ask how much money the account starts with, and store that in the
newAcctBalance double. We then create a new instance of the BankAcct
struct and set those members using the previous values. We then push
the struct to the database, and return.
*/
void addAccount(vector<BankAcct> &database) {
	string newAcctName = "#";
	cout << "What would you like to name this account? ";
	cin.ignore();
	getline(cin, newAcctName);

	double newAcctBalance;
	cout << "How much money is in this account? $";
	cin >> newAcctBalance;

	BankAcct newAcct;
	newAcct.name = newAcctName;
	newAcct.balance = newAcctBalance;
	database.push_back(newAcct);
	cout << endl;
	return;
}

/*
Input: A vector of BankAcct structures, passed by reference. This allows us to
modify the values of the objects within the vector without returning any
values.
Output: Void.
Purpose: We prompt which account they would like to remove, and store that value
in removeAccountID. We then validate if that ID is valid. If it's not,
we say so, and return. If it is, we erase that BankAcct struct from the
database.
*/
void removeAccount(vector<BankAcct> &database) {
	int removeAccountID = 0;
	cout << "Which Account ID would you like to remove? ";
	cin >> removeAccountID;
	if (0 < removeAccountID && removeAccountID <= database.size()) {
		database.erase(database.begin() + (removeAccountID - 1));
		cout << endl;
		return;
	} else {
		cout << "Whoops! Look like that Account ID doesn't work :( Please try again!\n\n";
	}
}

/*
Input: A vector of BankAcct structures, passed by reference. This allows us to
modify the values of the objects within the vector without returning any
values.
Output: Void.
Purpose: This is the main function that runs the program. We first create a quit
bool, initialized to false. We then run a loop that will run as long as
quit is false. We display the options the user can enter, and store
their selection in the option char. We then check that char against the
options, and use that to call the appropriate function. All of the
functions that modify information are passed a reference of the database,
so no return values are needed from the functions. If it's an option
other than quit, it will continue to the next iteration of the loop. If
it's quit, it will break the loop, and end the program.
*/
void displayMenu(vector<BankAcct> &database) {
	// This helps to display the double values correctly, otherwise it often
	// truncates/rounds
	cout << setprecision(15);
	
	bool quit = false;
	while (!quit) {
		char option;
		displayAccounts(database);
		cout << "\n(A)dd (S)um (D)eposit (W)ithdraw (T)ransfer (R)emove (Q)uit\n";
		cin >> option;

		if (option == 'A' || option == 'a') {
			addAccount(database);
			continue;
		} else if (option == 'S' || option == 's') {
			cout << "The sum of all accounts is $" << getTotal(database) << endl << endl;
			continue;
		} else if (option == 'D' || option == 'd') {
			deposit(database);
			continue;
		} else if (option == 'W' || option == 'w') {
			withdraw(database);
			continue;
		} else if (option == 'T' || option == 't') {
			transfer(database);
			continue;
		}else if (option == 'R' || option == 'r') {
			removeAccount(database);
			continue;
		} else if (option == 'Q' || option == 'q') {
			break;
		} else {
			cout << "Sorry, I didn't quite catch that. Please use one of the options listed.\n\n";
		}
	}
}

int main() {
	// We initialize the array of bank accounts, initialize five BankAcct
	// structs, and set their member information
	vector <BankAcct> bankDatabase;
	BankAcct a1, a2, a3, a4, a5;
	a1.name = "WECU";
	a1.balance = 1000.00;
	a2.name = "BECU";
	a2.balance = 567.34;
	a3.name = "ICU";
	a3.balance = 6893.73;
	a4.name = "Key";
	a4.balance = 3.50;
	a5.name = "People's";
	a5.balance = 250000.00;

	// This pushes the BankAcct structs to the vector.
	bankDatabase.push_back(a1);
	bankDatabase.push_back(a2);
	bankDatabase.push_back(a3);
	bankDatabase.push_back(a4);
	bankDatabase.push_back(a5);

	// This starts the display menu function, which will run until the user
	// quits out of it.
	displayMenu(bankDatabase);
	return 0;
}
