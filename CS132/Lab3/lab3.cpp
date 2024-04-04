#include <iostream>
#include <string>
#include <vector>
using namespace std;

// A class for food items.
class Food {
    public:
        // Constructor.
        Food(string name, int calories, vector<string> flavors);
        
        // Returns the calories variable for the given object.
        int getCalorieCount();

        // Returns if the Food object has the specified flavor.
        bool hasFlavor(string flavorSearch);

        // Public attribute for name.
        string name;

    private:
        // Private attributes for calories and the flavors of food.
        int calories;
        vector<string> flavors;
};

// A struct containing a Food item and how many of that item are needed.
struct recipeIngredient {
    Food f;
    int amtNeeded;
};

// A class for recipes.
class Recipe {
    public:
        // Constructor.
        Recipe(string name, int servings, vector<recipeIngredient> ingredients);

        // Returns how many calories per serving.
        int getCaloriesPerServing();

        // Prints out the recipe.
        void printRecipe();

        // Public attribute for name.
        string name;

    private:
        // Private attributes for the total number of servings, and a vetor
        // of recipe ingredient structs (Food item + how many needed).
        int servings;
        vector<recipeIngredient> ingredients;
};

int main() {
    // We create food objects, then create recipeIngredient structs with that
    // food object and how many are needed.
    Food noodles("Spaghetti Noodles", 360, {"starchy"});
    recipeIngredient noodlesStruct = {noodles, 1};
    Food tomatoes("Tomatoes", 80, {"sweet"});
    recipeIngredient tomatoesStruct = {tomatoes, 3};
    Food herb("Basil", 10, {"herbaceous"});
    recipeIngredient herbStruct = {herb, 2};
    Food onion("Yello Onion", 120, {"aromatic"});
    recipeIngredient onionStruct = {onion, 1};
    Food garlic("Garlic", 20, {"pungent"});
    recipeIngredient garlicStruct = {garlic, 1};

    // Use those recipeIngredient structs to create a recipe.
    Recipe spaghettiRecipe("Mom's Spaghetti", 6, {noodlesStruct, tomatoesStruct, herbStruct, onionStruct, garlicStruct});
    
    // Print the recipe and how many calories per serving.
    spaghettiRecipe.printRecipe();
    cout << "Calories per serving: " << spaghettiRecipe.getCaloriesPerServing() << endl;
    return 0;
}

// ### FOOD CLASS DEFINITIONS ### //

// Constructor
Food::Food(string name, int calories, vector<string> flavors) {
    this->name = name;
    this->calories = calories;
    this->flavors = flavors;
}

// Returns the calories variable for the given object.
int Food::getCalorieCount() {
    return calories;
}

// Loops through the vector of flavors for the given object and returns
// true if the given flavor is present. If it finishes the loop without
// finding the flavor, it returns false.
bool Food::hasFlavor(string flavorSearch) {
    for (string flavor : flavors) {
        if (flavor == flavorSearch) {
            return true;
        }
    }

    return false;
}

// ### RECIPE CLASS DEFINITIONS ### //

// Constructor
Recipe::Recipe(string name, int servings, vector<recipeIngredient> ingredients) {
    this->name = name;
    this->servings = servings;
    this->ingredients = ingredients;
}

// Loops through the recipe ingredients, adding the calorie per ingredient
// multiplied by how many of that ingredient are needed. I then divide
// the total calories of the recipe by how many servings, getting the
// calories per serving.
int Recipe::getCaloriesPerServing() {
    int totalCalories = 0;
    for (recipeIngredient ingredient : ingredients) {
        totalCalories += (ingredient.f.getCalorieCount() * ingredient.amtNeeded);
    }

    return totalCalories / servings;
}

// Prints out the recipe.
void Recipe::printRecipe() {
    cout << "\"" << name << "\"\n";
    cout << "Serves " << servings << endl;

    for (recipeIngredient ingredient : ingredients) {
        cout << ingredient.amtNeeded << " unit(s) of " << ingredient.f.name << " (" << ingredient.f.getCalorieCount() << ")\n"; 
    } 
}