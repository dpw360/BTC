#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person  {
    string ssn = 0;
    string firstName = "";
    string lastName = "";
    string emailAddy = "";
};

vector<Person> readPerson(ifstream &input) {
    string social, first, last, email;
    while (input >> social >> first >> last >> email) {
        cout << "SSN: " << social << endl;
        cout << "First Name: " << first << endl;
        cout << "Last Name: " << last << endl;
        cout << "Email Addy: " << email << endl << endl;
    }

    vector<Person> yeet;

    return yeet;
}

int main() {
    ifstream input;
    input.open("persons.txt");

    vector<Person> vectOfPeople = readPerson(input);

    input.close();
    return 0;
}