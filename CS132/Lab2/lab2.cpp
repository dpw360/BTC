// 1. Implement the constructor and both public methods for the Food class.
//    getCalorieCount is a simple accessor. hasFlavor should search through
//    the vector of flavors and return true if the input flavor is found, false 
//    if it is not.
// 2. In main, construct 4 Food items of your choice.
// 3. Add those Food items to a collection, either array or vector.
// 4. Build a loop that prompts the user for a flavor. Within that loop check 
//    each food item to see if it has that flavor. If it does, print out the Food
//    item's name and calorie count.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Food {
    public:
        Food(string name, int calories, vector<string> flavors) {
            name = name;
            calories = calories;
            flavors = flavors;
        }
        
        int getCalorieCount() {
            return calories;
        }

        bool hasFlavor(string flavorSearch) {
            for (string flavor : flavors) {
                if (flavor == flavorSearch) {
                    return true;
                }
            }

            return false;
        }

        string name;

    private:
        int calories;
        vector<string> flavors;
};

int main() {
    vector<string> pizzaFlavors {"sweet", "cheesy", "spicy"};
    Food f1("Pizza", 200, pizzaFlavors);
    return 0;
}