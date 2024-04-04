#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Food {
    public:
        // Constructor
        Food(string nameNew, int caloriesNew, vector<string> flavorsNew) {
            name = nameNew;
            calories = caloriesNew;
            flavors = flavorsNew;
        }
        
        // Returns the calories variable for the given object.
        int getCalorieCount() {
            return calories;
        }

        // Loops through the vector of flavors for the given object and returns
        // true if the given flavor is present. If it finishes the loop without
        // finding the flavor, it returns false.
        bool hasFlavor(string flavorSearch) {
            for (string flavor : flavors) {
                if (flavor == flavorSearch) {
                    return true;
                }
            }

            return false;
        }

        // Public attribute for name
        string name;

    private:
        // Private attributes for calories and the flavors of food.
        int calories;
        vector<string> flavors;
};

int main() {
    // Create four food items.
    vector<string> pizzaFlavors {"sweet", "cheesy", "spicy"};
    Food f1("Pizza", 600, pizzaFlavors);
    vector<string> teriyakiFlavors {"sweet", "savory", "smoky"};
    Food f2("Teriyaki", 350, teriyakiFlavors);
    vector<string> ramenFlavors {"umami", "savory", "salty"};
    Food f3("Ramen", 200, ramenFlavors);
    vector<string> burgerFlavors {"meaty", "cheesy", "greasy"};
    Food f4("Burger", 400, burgerFlavors);

    // Add the four food items to a vector.
    vector<Food> foodVect {f1, f2, f3, f4};
    
    // Prompt for and store a flavor to be searched for.
    string searchFlavor;
    cout << "Please enter a flavor that you would like to search for: ";
    cin >> searchFlavor;

    // I loop through the food objects in the vector, and use the Food object's
    // public hasFlavor method to determine if that object has the given flavor.
    // If it does, I display the info.
    for (Food x : foodVect) {
        if (x.hasFlavor(searchFlavor)) {
            cout << x.name << " is " << x.getCalorieCount() << " calories and has the " << searchFlavor << " flavor!\n";
        }
    }

    return 0;
}