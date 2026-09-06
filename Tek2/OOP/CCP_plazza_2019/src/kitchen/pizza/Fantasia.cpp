/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Fantasia
*/

#include "kitchen/pizza/Fantasia.hpp"

Plazza::Fantasia::Fantasia(uint16_t size) : Pizza(PizzaType::Fantasia, size)
{
    _recipe.push_back(IngredientType::Doe);
    _recipe.push_back(IngredientType::Tomato);
    _recipe.push_back(IngredientType::Eggplant);
    _recipe.push_back(IngredientType::GoatCheese);
    _recipe.push_back(IngredientType::ChiefLove);
}

Plazza::Fantasia::~Fantasia()
{
}

bool Plazza::Fantasia::isRecipe() const
{
    unsigned int doe = 0;
    unsigned int tomato = 0;
    unsigned int eggplant = 0;
    unsigned int goatCheese = 0;
    unsigned int chiefLove = 0;
    unsigned int otherIngr = 0;

    for (int i = _ingr.size();i >= 0;i--) {
        if (_ingr[i].type() == IngredientType::Doe)
            doe++;
        else if (_ingr[i].type() == IngredientType::Tomato)
            tomato++;
        else if (_ingr[i].type() == IngredientType::Eggplant)
            eggplant++;
        else if (_ingr[i].type() == IngredientType::GoatCheese)
            goatCheese++;
        else if (_ingr[i].type() == IngredientType::ChiefLove)
            chiefLove++;
        else
            otherIngr++;
    }
    if (doe >= 1 && tomato >= 1 && eggplant >= 1 && goatCheese >= 1 && chiefLove >= 1 && !otherIngr)
        return (true);
    else 
        return (false);
}

uint32_t Plazza::Fantasia::timeCook() const
{
    return (4 * stockage.getMultiplTimeCook());
}