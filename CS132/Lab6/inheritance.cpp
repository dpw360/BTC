#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Character {
    protected:
        // These are virtual functions which must be implemented in all child
        // classes derived from the Character class.
        virtual void print() = 0;
        virtual string getSecretIdentity() = 0;
};

class Person {
    protected:
        // Strings for a person's real name and their job title. They are
        // protected so that they stay private and are usable by child classes.
        string realName;
        string jobTitle;
};

class Hero : public Character, public Person {
    public:
        // A string for their hero name, and a vector of strings of powers.
        string name;
        vector<string> superPowers;

        // Constructor.
        Hero (string name, vector<string> superPowers, string weakness, string realName, string jobTitle) {
            this->name = name;
            this->superPowers = superPowers;
            this->weakness = weakness;
            this->realName = realName;
            this->jobTitle = jobTitle;
        }

        // Prints out all relevant information on a hero.
        void print() {
            printf("Real Name: %s \nJob: %s \nHero Name: %s \n", this->getSecretIdentity().c_str(), this->jobTitle.c_str(), this->name.c_str());
            cout << "They have these super powers:\n";
            for (string power : superPowers) {
                cout << "    " << power << endl;
            }
            printf("They are weak to %s\n\n", this->weakness.c_str());
        }

        // A getter function for a hero's secret identity.
        string getSecretIdentity() {
            return this->realName;
        }

    private:
        // A private string of their weakness. Shhhhh!
        string weakness;
};

// All comments and functionality are identical to the Hero class.
class Villain : public Character, public Person {
    public:
        string name;
        vector<string> superPowers;

        Villain (string name, vector<string> superPowers, string weakness, string realName, string jobTitle) {
            this->name = name;
            this->superPowers = superPowers;
            this->weakness = weakness;
            this->realName = realName;
            this->jobTitle = jobTitle;
        }

        void print() {
            printf("Real Name: %s \nJob: %s \nVillain Name: %s \n", this->getSecretIdentity().c_str(), this->jobTitle.c_str(), this->name.c_str());
            cout << "They have these super powers:\n";
            for (string power : superPowers) {
                cout << "    " << power << endl;
            }
            printf("They are weak to %s\n\n", this->weakness.c_str());
        }

        string getSecretIdentity() {
            return this->realName;
        }

    private:
        string weakness;
};

int main() {
    // I create a hero and display it.
    cout << "Lets see what's on Mr. Rogers' file...\n\n";
    Hero h1("Captain America", {"Super Strength", "Resilience", "Immortal"}, "Ice", "Steve Rogers", "Avenger");
    h1.print();

    // I create a villain and display it.
    cout << "How about who he's up against?\n\n";
    Villain v1("The Snow Queen", {"Ice Creation", "Perfect Pitch"}, "Stubborness", "Elsa", "Queen of Arendelle");
    v1.print();

    cout << "Uh oh... Looks like Mr. Rogers might become a popsicle again :/\n";
    return 0;
}