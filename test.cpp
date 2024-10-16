#include <iostream>
#include "Dish.hpp"
#include "ArrayBag.hpp"
#include "Kitchen.hpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    Kitchen def_parameter;

    std::vector<std::string> italian_ingredients = {"Pasta", "Eggs", "Pancetta", "Parmesan", "Pepper"};
    Dish italian_parameterized("Pasta Carbonara", italian_ingredients, 20, 12.50, Dish::ITALIAN);
    std::vector<std::string> italian_ingredients2 = {"Pasta", "Eggs", "Pancetta", "Parmesan", "Pepper"};
    Dish italian_parameterized2("Pasta Carbonara", italian_ingredients2, 21, 12.50, Dish::ITALIAN);

    std::vector<std::string> mexican_ingredients = {"Beef, Chili, Chicken, Wrap"};
    Dish mexican_parameterized("Taco", mexican_ingredients, 10, 20.00, Dish::CuisineType::MEXICAN);
    std::vector<std::string> mexican_ingredients2 = {"Beef, Chili, Chicken, Wrap"};
    Dish mexican_parameterized2("Taco", mexican_ingredients2, 11, 20.00, Dish::CuisineType::MEXICAN);
    std::vector<std::string> mexican_ingredients3 = {"Beef, Chili, Chicken, Wrap"};
    Dish mexican_parameterized3("Taco", mexican_ingredients3, 12, 20.00, Dish::CuisineType::MEXICAN);

    std::vector<std::string> chinese_ingredients = {"Orange", "Chicken"};
    Dish chinese_parameterized("Orange Chicken", chinese_ingredients, 10, 20.00, Dish::CuisineType::CHINESE);
    std::vector<std::string> chinese_ingredients2 = {"Orange", "Chicken"};
    Dish chinese_parameterized2("Orange Chicken", chinese_ingredients2, 11, 20.00, Dish::CuisineType::CHINESE);

    std::vector<std::string> indian_ingredients = {"Curry"};
    Dish indian_parameterized("Curry", indian_ingredients, 30, 18.99, Dish::CuisineType::INDIAN);

    std::vector<std::string> american_ingredients = {"Chicken", "Olive Oil", "Garlic", "Rosemary"};
    Dish american_parameterized("Grilled Chicken", american_ingredients, 31, 18.99, Dish::CuisineType::AMERICAN);

    std::vector<std::string> french_ingredients = {"Flour", "Sugar", "Cocoa Powder", "Eggs", "Vanilla Extract"};
    Dish french_parameterized("Chocolate Cake", french_ingredients, 61, 7.99, Dish::CuisineType::FRENCH);
    std::vector<std::string> french_ingredients2 = {"Flour", "Sugar", "Cocoa Powder", "Eggs"};
    Dish french_parameterized2("Chocolate Cake", french_ingredients2, 46, 7.99, Dish::CuisineType::FRENCH);

    std::vector<std::string> other_ingredients = {"Lettuce"};
    Dish other_parameterized("Salad", other_ingredients, 10, 20.00, Dish::CuisineType::OTHER);
    std::vector<std::string> other_ingredients2 = {"Lettuce"};
    Dish other_parameterized2("Salad", other_ingredients2, 11, 20.00, Dish::CuisineType::OTHER);
    std::vector<std::string> other_ingredients3 = {"Lettuce"};
    Dish other_parameterized3("Salad", other_ingredients3, 12, 20.00, Dish::CuisineType::OTHER);
        
    def_parameter.newOrder(italian_parameterized);
    def_parameter.newOrder(italian_parameterized2);

    def_parameter.newOrder(mexican_parameterized);
    def_parameter.newOrder(mexican_parameterized2);
    def_parameter.newOrder(mexican_parameterized3);

    def_parameter.newOrder(chinese_parameterized);
    def_parameter.newOrder(chinese_parameterized2);

    def_parameter.newOrder(indian_parameterized);

    def_parameter.newOrder(american_parameterized);

    def_parameter.newOrder(french_parameterized);
    def_parameter.newOrder(french_parameterized2);

    def_parameter.newOrder(other_parameterized);
    def_parameter.newOrder(other_parameterized2);
    def_parameter.newOrder(other_parameterized3);


    def_parameter.serveDish(other_parameterized3);

    def_parameter.getPrepTimeSum();

    def_parameter.calculateAvgPrepTime();

    def_parameter.elaborateDishCount();

    def_parameter.calculateElaboratePercentage();

    def_parameter.tallyCuisineTypes("ITALIAN");
    def_parameter.tallyCuisineTypes("MEXICAN");
    def_parameter.tallyCuisineTypes("CHINESE");
    def_parameter.tallyCuisineTypes("INDIAN");
    def_parameter.tallyCuisineTypes("AMERICAN");
    def_parameter.tallyCuisineTypes("FRENCH");
    def_parameter.tallyCuisineTypes("OTHER");

    def_parameter.releaseDishesBelowPrepTime(1);

    def_parameter.releaseDishesOfCuisineType("test");

    def_parameter.kitchenReport();

    return 0;
}
