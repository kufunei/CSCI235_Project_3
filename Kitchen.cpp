/**
 * @file Kitchen.cpp
 * @brief This file contains the implementation of the Kitchen class that is a subclass of ArrayBag that stores Dish objects, which represents a kitchen in a virtual bistro simulation.
 * 
 * The Kitchen class includes methods to manage and present the details of a kitchen, total prep time and a count of elaborate dishes.
 * The implementation ensures that the kitchen is validated and correctly formatted.
 * 
 * @date September 30, 2024
 * @author Kun Feng Wei
 */

#include "Kitchen.hpp"
#include "ArrayBag.hpp"
#include "Dish.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision
#include <cctype>  // For std::isalpha, std::isspace
#include <cmath> //Rounding

/**
  * Default constructor.
  * Default-initializes all private members.
  */
Kitchen::Kitchen() : ArrayBag<Dish>()
{
    this -> total_prep_time_ = 0;
    this -> count_elaborate_ = 0; 
}

/**
  * @param : A reference to a `Dish` being added to the kitchen.
  * @post : If the given `Dish` is not already in the kitchen, adds the
`Dish` to the kitchen and updates the preparation time sum and elaborate
dish count if the dish is elaborate.
  * @return : Returns true if a `Dish` was successfully added to the
kitchen, false otherwise.
           Hint: Use the above definition of equality to help determine if a
`Dish` is already in the kitchen.
*/        
bool Kitchen::newOrder(const Dish& name_)
{
    if (contains(name_))
    {
        return false;
    }

    if (add(name_))
    {
        total_prep_time_ = total_prep_time_ + name_.getPrepTime();
        if (name_.getIngredients().size() >= 5 && name_.getPrepTime() >= 60) 
        {
            count_elaborate_++;
        }
        return true;
    }
    return false;
}

/**
  * @param : A reference to a `Dish` leaving the kitchen.
  * @return : Returns true if a dish was successfully removed from the kitchen (i.e., items_), false otherwise.
  * @post : Removes the dish from the kitchen and updates the preparation time sum. If the `Dish` is elaborate, it also updates the elaborate count.
*/
bool Kitchen::serveDish(const Dish& name_)
{
    if (contains(name_))
    {
        if (remove(name_))
        {
            total_prep_time_ = total_prep_time_ - name_.getPrepTime();
            if (name_.getIngredients().size() >= 5 && name_.getPrepTime() >= 60)
            {
                count_elaborate_--;
            }
            return true;
        }
    }
    return false;
}

/**
  * @return : The integer sum of preparation times for all the dishes
currently in the kitchen.
*/

int Kitchen::getPrepTimeSum() const
{
    return total_prep_time_;
}

/**
  * @return : The average preparation time (int) of all the dishes in the
kitchen. The lowest possible average prep time should be 0.
  * @post : Computes the average preparation time (double) of the kitchen
rounded to the NEAREST integer.
*/
int Kitchen::calculateAvgPrepTime() const
{
    if (isEmpty())
    {
        return 0.0;
    }
    return ((double)getPrepTimeSum() / getCurrentSize()) + 0.5;
}

/**
  * @return : The integer count of the elaborate dishes in the kitchen.
*/
int Kitchen::elaborateDishCount() const
{
    return count_elaborate_;
}

/**
  * @return : The percentage (double) of all the elaborate dishes in the
kitchen. The lowest possible percentage should be 0%.
  * @post : Computes the percentage of elaborate dishes in the kitchen
rounded up to 2 decimal places.
*/
double Kitchen::calculateElaboratePercentage() const //WRONG
{
    if (elaborateDishCount() > 0.0)
    {
        return (round((double)elaborateDishCount() / getCurrentSize() * 10000)) / 100;
    }
    else
    {
        return 0.0;
    }
}

/**
  * @param : A reference to a string representing a cuisine type with a
value in
             ["ITALIAN", "MEXICAN", "CHINESE", "INDIAN", "AMERICAN",
"FRENCH", "OTHER"].
  * @return : An integer tally of the number of dishes in the kitchen of the
given cuisine type.
             If the argument string does not match one of the expected
cuisine types, the tally is zero.
                 NOTE: No pre-processing of the input string necessary, only
uppercase input will match.
*/
int Kitchen::tallyCuisineTypes(const std::string& cuisine_type) const
{
    int tally = 0;
    for (int i = 0; i < getCurrentSize(); i++)
    {
        if (items_[i].getCuisineType() == cuisine_type)
        {
            tally++;
        }
    }
    return tally;
}

/**
  * @param : A reference to an integer representing the preparation time
threshold of the dishes to be removed from the kitchen.
  * @post : Removes all dishes from the kitchen whose preparation time is
less than the given time.
  * @return : The number of dishes removed from the kitchen.
*/
int Kitchen::releaseDishesBelowPrepTime(int threshold)
{
    int released_prep = 0;

    if (threshold < 0) //Do nothing is threshold less than 0
    {
        return false;
    }
    
    else if (threshold > 0)
    {
        for (int i = 0; i < getCurrentSize(); i++)
        {
            if (items_[i].getPrepTime() < threshold)
            {
                if (remove(items_[i]))
                {
                    total_prep_time_ = total_prep_time_ - items_[i].getPrepTime();      
                    if (items_[i].getIngredients().size() >= 5 && items_[i].getPrepTime() >= 60)
                    {
                        count_elaborate_--;
                    }
                    released_prep++;                          
                }
            }        
        }
    }

    else
    {
        while (getCurrentSize() > 0)
        {
            for (int i = 0; i < getCurrentSize(); i++)
            {
                if (remove(items_[i]))
                {
                    total_prep_time_ = total_prep_time_ - items_[i].getPrepTime();      
                    if (items_[i].getIngredients().size() >= 5 && items_[i].getPrepTime() >= 60)
                    {
                        count_elaborate_--;
                    }
                    released_prep++;
                }                          
            }
        }   
    }
    return released_prep;
}

/**
  * @param : A reference to a string representing a cuisine type with a
value in
             ["ITALIAN", "MEXICAN", "CHINESE", "INDIAN", "AMERICAN",
"FRENCH", "OTHER"].
  * @post : Removes all dishes from the kitchen whose cuisine type matches
the given type.
  * @return : The number of dishes removed from the kitchen.
           NOTE: No pre-processing of the input string necessary, only
uppercase input will match.
           If the input string does not match one of the expected cuisine
types, do not remove any dishes.
*/
int Kitchen::releaseDishesOfCuisineType(const std::string& cuisine_type)
{
    int released_cuisinetype = 0;
    if (cuisine_type == "ALL")
    {
        released_cuisinetype = getCurrentSize();
        clear();
        total_prep_time_ = 0;
        count_elaborate_ = 0;
        return released_cuisinetype;
    }

    else
    {
        for (int i = 0; i < getCurrentSize(); i++)
        {
            if (items_[i].getCuisineType() == cuisine_type)
            {
                if (remove(items_[i]))
                {
                    total_prep_time_ = total_prep_time_ - items_[i].getPrepTime();      
                    if (items_[i].getIngredients().size() >= 5 && items_[i].getPrepTime() >= 60)
                    {
                        count_elaborate_--;
                    }
                    released_cuisinetype++;
                }
            }
        }
    }
    return released_cuisinetype;
}

/**
  * @post : Outputs a report of the dishes currently in the kitchen in the
form: "ITALIAN: {x}\nMEXICAN: {x}\nCHINESE: {x}\nINDIAN: {x}\nAMERICAN: {x}\nFRENCH: {x}\nOTHER: {x}\n\n AVERAGE PREP TIME: {x}\ELABORATE: {x}%\n"
Note that the average preparation time should be rounded to the
NEAREST integer, and the percentage of elaborate dishes in the kitchen should be rounded
to 2 decimal places.
Example output:
ITALIAN: 2
MEXICAN: 3
CHINESE: 2
INDIAN: 1
AMERICAN: 1
FRENCH: 2
OTHER: 2
AVERAGE PREP TIME: 62
ELABORATE DISHES: 53.85%
*/
void Kitchen::kitchenReport() const
{
    std::cout << "ITALIAN: " << tallyCuisineTypes("ITALIAN") << std::endl;
    std::cout << "MEXICAN: " << tallyCuisineTypes("MEXICAN") << std::endl;
    std::cout << "CHINESE: " << tallyCuisineTypes("CHINESE") << std::endl;
    std::cout << "INDIAN: " << tallyCuisineTypes("INDIAN") << std::endl;
    std::cout << "AMERICAN: " << tallyCuisineTypes("AMERICAN") << std::endl;
    std::cout << "FRENCH: " << tallyCuisineTypes("FRENCH") << std::endl;
    std::cout << "OTHER: " << tallyCuisineTypes("OTHER") << std::endl;
    std::cout << std::endl;

    std::cout << "AVERAGE PREP TIME: " << calculateAvgPrepTime() << std::endl;
    std::cout << "ELABORATE: " << std::fixed << std::setprecision(2) << calculateElaboratePercentage() << "%" << std::endl;
}
