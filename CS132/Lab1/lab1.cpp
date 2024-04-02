#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person  {
    string ssn = "";
    string firstName = "";
    string lastName = "";
    string emailAddy = "";
};

/*
Input: The line to be split, and the target vector to split into.
Output: Void, pass by reference.
Purpose: I create an empty string, then loop through the line with a for loop.
         I first check if the current char is a tab, or the final char of the
         line. If it is, I add the current string to the target vector, and
         clear the current string for the next iteration. If it's not one of
         those cases, I add the current char to the current string.
*/
void split(string &line, vector<string> &target) {
    string build = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '\t' || i == line.size() - 1) {
            target.push_back(build);
            build = "";
        } else {
            build += line[i];
        }
    }

    return;
}

/*
Input: An input stream of the data to be parsed.
Output: A vector or Person structs.
Purpose: First I create an empty string to hold each line of the file, and a
         vector of Person objects that will be returned. I then use a while loop
         to loop through the input stream line by line, using the split function
         to parse info from the line into a vector of strings. I then create a 
         new Person object, and assign each field the correct information. I 
         finally add the Person object to the vector of Person objects, and
         return it.
*/
vector<Person> readPerson(ifstream &input) {
    string line;
    vector<Person> peopleList;

    while (getline(input, line)) {
        vector<string> information;
        split(line, information);
        Person currentPerson;
        currentPerson.ssn = information[0];
        currentPerson.firstName = information[1];
        currentPerson.lastName = information[2];
        currentPerson.emailAddy = information[3];
        peopleList.push_back(currentPerson);
    }

    return peopleList;
}

int main() {
    // I open the file as an ifstream object.
    ifstream input;
    input.open("persons.txt");

    // I create a vector of Person objects, and use the readPerson function
    // to fill it with said person objects.
    vector<Person> vectOfPeople = readPerson(input);

    // I output each Person in the vector in the correct format.
    for (Person person : vectOfPeople) {
        cout << person.lastName << ", " << person.firstName << ":" << person.ssn << ":" << person.emailAddy << endl;
    }

    // I close the input and return to end the program.
    input.close();
    return 0;
}