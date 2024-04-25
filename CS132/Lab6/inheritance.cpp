#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Character {
    protected:
        virtual void print() {};
        virtual string getSecretIdentity() {return "";};
};

class Person {
    protected:
        string realName;
        string jobTitle;
};

class Hero : public Character, public Person {
    public:
        string name;
        vector<string> superPowers;

        Hero (string name, vector<string> superPowers, string weakness, string realName, string jobTitle) {
            this->name = name;
            this->superPowers = superPowers;
            this->weakness = weakness;
            this->realName = realName;
            this->jobTitle = jobTitle;
        }

        void print() {
            printf("Real Name: %s \nJob: %s \nHero Name: %s \n", this->getSecretIdentity(), this->jobTitle, this->name);
            cout << "They have these super powers:\n";
            for (string power : superPowers) {
                cout << power << endl;
            }
            printf("They are weak to %s", this->weakness);
        }

        string getSecretIdentity() {
            return this->realName;
        }

    private:
        string weakness;
};

int main() {
    Hero h1("Captain America", {"Super Strength", "Resilience", "Immortal"}, "Ice", "Steve Rogers", "Avenger");
    h1.print();
}