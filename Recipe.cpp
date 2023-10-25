#include <iostream>
#include <string>
using namespace std;

class Dish
{
public:
    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Ingredients: " << ingredients << endl;
        cout << "Instructions: " << instructions << endl;
    }

    virtual string getIngredients()
    {
        return ingredients;
    }

protected:
    string name;
    string ingredients;
    string instructions;
};

class MainCourse : public Dish
{
public:
    MainCourse(string name, string ingredients, string instructions)
    {
        this->name = name;
        this->ingredients = ingredients;
        this->instructions = instructions;
    }
};

class Dessert : public Dish
{
public:
    Dessert(string name, string ingredients, string instructions)
    {
        this->name = name;
        this->ingredients = ingredients;
        this->instructions = instructions;
    }
};

class RecipeOrganizer
{
public:
    void addDish(Dish *dish)
    {
        dishes[dishCount++] = dish;
    }

    Dish *searchDishes(string ingredients)
    {
        for (int i = 0; i < dishCount; i++)
        {
            if (isSubset(ingredients, dishes[i]->getIngredients()))
            {
                return dishes[i];
            }
        }
        return nullptr;
    }

private:
    Dish *dishes[100];
    int dishCount = 0;

    bool isSubset(const string &str1, const string &str2)
    {
        return str2.find(str1) != string::npos;
    }
};

int main()
{
    RecipeOrganizer recipeOrganizer;

    MainCourse mainCourse1("Spaghetti with Marinara Sauce", "spaghetti noodles, marinara sauce, parmesan cheese, ground beef",
                           "Cook the spaghetti noodles according to package directions. While the noodles are cooking, brown "
                           "the ground beef in a large skillet over medium heat. Drain off any excess grease. Add the marinara "
                           "sauce to the skillet and bring to a simmer. Reduce heat to low and simmer for 15 minutes. Serve the "
                           "spaghetti noodles with the marinara sauce and sprinkle with Parmesan cheese.");

    Dessert dessert1("Chocolate Chip Cookies", "flour, sugar, butter, eggs, chocolate chips",
                     "Preheat oven to 350 degrees F (175 degrees C). Mix together the flour, sugar, and butter. "
                     "Beat in the eggs one at a time, then stir in the chocolate chips. Drop by rounded tablespoons "
                     "onto ungreased baking sheets. Bake for 10-12 minutes, or until golden brown. Let cool on "
                     "baking sheets for a few minutes before transferring to a wire rack to cool completely.");

    MainCourse mainCourse2("Fried Rice", "rice, eggs, vegetables, soy sauce",
                           "Cook the rice according to package directions. Scramble the eggs in a large skillet over medium heat. Add the "
                           "vegetables to the skillet and cook until tender. Add the rice and soy sauce to the skillet and stir to combine. Serve immediately.");

    Dessert dessert2("Apple Pie", "pie crust, apples, sugar, cinnamon, butter",
                     "Preheat oven to 425 degrees F (220 degrees C). Place the bottom crust in your pan. Fill with apples, mounded slightly. "
                     "Combine sugar, cinnamon, and butter in a small bowl, then sprinkle mixture over apples. Cover with a lattice work crust. "
                     "Gently pour the water over the pie. Bake 15 minutes in the preheated oven. Reduce the temperature to 350 degrees F (175 degrees C). "
                     "Continue baking for 35 to 45 minutes, until apples are soft.");

    recipeOrganizer.addDish(&mainCourse1);
    recipeOrganizer.addDish(&dessert1);
    recipeOrganizer.addDish(&mainCourse2);
    recipeOrganizer.addDish(&dessert2);

    string ingredients;
    cout << "What ingredients do you have at home? ";
    cin >> ingredients;

    Dish *matchingDish = recipeOrganizer.searchDishes(ingredients);

    if (matchingDish != nullptr)
    {
        cout << "Here is a dish that you can make with that:" << endl;
        matchingDish->displayInfo();
    }
    else
    {
        cout << "Sorry, I couldn't find any dishes that match your ingredients." << endl;
    }

    return 0;
}
