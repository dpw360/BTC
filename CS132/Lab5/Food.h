#pragma once
#include <vector>
#include <string>
using namespace std;

namespace food {
    class Food {
        public:
            // Constructor
            Food(string name, int calories, vector<string> flavors);
            //Methods
            int getCalorieCount();
            bool hasFlavor(string flavorSearch);
            // Overloaded + operator
            Food operator+(Food f);
            // Public attribute for name.
            string name;

        private:
            // Private attributes for calories and the flavors of food.
            int calories;
            vector<string> flavors;
    };
}