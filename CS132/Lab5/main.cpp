#include <iostream>
#include <string>
#include "Food.h"
using namespace std;
using namespace food;

int main() {
    cout << "Let's combine some foods!\n";
    Food rice("Rice", 100, vector<string> {"plain"});
    Food beans("Beans", 300, vector<string>{"savory"});

    cout << "We made " << rice.name << ", which has " << rice.getCalorieCount() << " calories.\n";
    cout << "We made " << beans.name << ", which has " << beans.getCalorieCount() << " calories.\n\n";

    cout << "Now, lets see what happens when we add them...\n";
    Food riceAndBeans = rice + beans;

    cout << "By combining the two, we made " << riceAndBeans.name << "!\n";
    cout << "It has " << riceAndBeans.getCalorieCount() << " calories.\n\n";

    cout << "Let's see if it has all the right flavors...\n";
    if (riceAndBeans.hasFlavor("savory") && riceAndBeans.hasFlavor("plain")) {
        cout << "It's got all the right flavors!\n";
    } else {
        cout << "Hmmmm, looks like I don't know how to cook, or code! :/\n";
    }

    return 0;
}