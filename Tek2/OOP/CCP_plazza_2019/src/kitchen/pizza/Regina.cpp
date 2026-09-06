/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Regina
*/

#include "kitchen/pizza/Regina.hpp"

Plazza::Regina::Regina(uint16_t size) : Pizza(PizzaType::Regina, size)
{
    _recipe.push_back(IngredientType::Doe);
    _recipe.push_back(IngredientType::Tomato);
    _recipe.push_back(IngredientType::Gruyere);
    _recipe.push_back(IngredientType::Ham);
    _recipe.push_back(IngredientType::Mushrooms);
}

Plazza::Regina::~Regina()
{
}

bool Plazza::Regina::isRecipe() const
{
    unsigned int doe = 0;
    unsigned int tomato = 0;
    unsigned int gruyere = 0;
    unsigned int ham = 0;
    unsigned int mushrooms = 0;
    unsigned int otherIngr = 0;

    for (int i = _ingr.size();i >= 0;i--) {
        if (_ingr[i].type() == IngredientType::Doe)
            doe++;
        else if (_ingr[i].type() == IngredientType::Tomato)
            tomato++;
        else if (_ingr[i].type() == IngredientType::Gruyere)
            gruyere++;
        else if (_ingr[i].type() == IngredientType::Ham)
            ham++;
        else if (_ingr[i].type() == IngredientType::Mushrooms)
            mushrooms++;
        else
            otherIngr++;
    }
    if (doe >= 1 && tomato >= 1 && gruyere >= 1 && ham >= 1 && mushrooms >= 1 && !otherIngr)
        return (true);
    else 
        return (false);
}

uint32_t Plazza::Regina::timeCook() const
{
    return (2 * stockage.getMultiplTimeCook());
}