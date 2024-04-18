#include <iostream>
#include <string>
#include <vector>
#include "Food.h"
using namespace std;
using namespace food;

// ### FOOD CLASS DEFINITIONS ### //

// Constructor
Food::Food(string name, int calories, vector<string> flavors) {
    this->name = name;
    this->calories = calories;
    this->flavors = flavors;
}

// Returns the calories variable for the given object.
int Food::getCalorieCount() {
    return this->calories;
}

// Loops through the vector of flavors for the given object and returns
// true if the given flavor is present. If it finishes the loop without
// finding the flavor, it returns false.
bool Food::hasFlavor(string flavorSearch) {
    for (string flavor : this->flavors) {
        if (flavor == flavorSearch) {
            return true;
        }
    }

    return false;
}

// Overloads the + operator to create a new Food object from two Food objects.
// I do this by creating the new information for name, calories, and flavors,
// then creating and returning a new Food object with that information.
Food Food::operator+(Food f) {
    string newName = this->name + " & " + f.name;
    int newCal = this->calories + f.calories;

    vector<string> newFlavors = this->flavors;
    newFlavors.insert(newFlavors.end(), f.flavors.begin(), f.flavors.end());

    Food newFood(newName, newCal, newFlavors);
    return newFood;
}