#include <iostream>
#include <string>
using namespace std;

/*
Classes are more for representing things, where inheritance and encapsulation
are important tools to have access to. Structs don't really have that; they are
more useful for grouping data together. Classes in C++ by default have their
access levels set to private, whereas structs are by default set to public.
*/
class BankAcct {
  /* Anything directly accessible by the program goes under "public".*/
  public:
    /* Overloaded Constructors to initialize BankAcct objects. */
    BankAcct(string name, double balance);
    BankAcct(string name);
    BankAcct();
    /* Member function to display an account. */
    void display();
    /* Member function to add to the account. */
    void deposit(double amt);
    /* Member function to withdraw from the account. */
    void withdraw(double amt);
    /* Member function to transfer from this account. */
    void transfer(double amt, BankAcct &toAcct);

  private:
    string name;
    double balance;
};

int main() {
  /* Some code to make doubles have two decimal points */
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  /* Create some accounts using overloaded constructors. */
  BankAcct wecu("WECU", 1000);
  BankAcct icu("ICU");
  BankAcct NorthCoast;

  /* Use the display "accessor" member function. */
  wecu.display();
  icu.display();
  NorthCoast.display();

  /* Use the deposit "mutator" member function. */
  wecu.deposit(100);
  cout << "After deposit 100 to wecu:\n";
  wecu.display();

  /* Use the withdrawal function to reverse the deposit to wecu. */
  wecu.withdraw(100);
  cout << "After withdraw 100 from wecu:\n";
  wecu.display();
  
  wecu.transfer(100, icu);
  cout << "After transfer 100 from wecu to icu:\n";
  wecu.display();
  icu.display();
  return 0;
}

/* Overloaded Constructor definitions for varying initial value calls. */
BankAcct::BankAcct(string n, double bal) {
  name = n;
  balance = bal;
}

BankAcct::BankAcct(string n) {
  name = n;
  balance = 0;
}

BankAcct::BankAcct() {
  name = "---";
  balance = 0;
}

void BankAcct::display() {
  cout << "Name: " << name << "\tBalance: " << balance << endl;
}

void BankAcct::deposit(double amt) {
  balance += amt;
}

/*
Input: An amt which the user would like to withraw.
Output: Void.
Purpose: We first check if the account has the funds to cover the withdraw,
no overdraft fees on my watch! If they do, we can subtract the amt
from the acct balance. Because this method modifies only the object
that it's called from's attribute values, it doesn't matter that the
balance attribute is private.
*/
void BankAcct::withdraw(double amt) {
  if (amt <= balance) {
    balance -= amt;
  } else {
    cout << "Sorry! There is an insufficient balance for that withdrawal.";
  }
}

/*
Input: An amt the user would like to transfer, and a reference to the BankAcct
object that we're tranfering into.
Output: Void.
Purpose: This function will transfer from the object that it's called with, to
the object in the paramters slot. We first check if the balance is
sufficient, as with the withdrawal. If it is, we can use the withdrawal
function to take the money out of that account. We could also just
assign a new value to this object, ie. balance -= amt, but withdraw is
more readable in my opinion). We could also skip the .deposit method on
the toAcct object and just do toAcct.balance += amt, but again, I find
it more readable to use the method.
*/
void BankAcct::transfer(double amt, BankAcct &toAcct) {
  if (amt <= balance) {
    withdraw(amt);
    // It took me way too long to realize that this only works when I
    // pass toAcct as a reference, not by value!
    toAcct.deposit(amt);
  } else {
    cout << "Sorry! There is an insufficient balance for that transfer.";
  }
}
