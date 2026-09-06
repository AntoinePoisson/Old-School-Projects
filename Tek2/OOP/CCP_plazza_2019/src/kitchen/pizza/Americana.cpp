/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Americana
*/

#include "kitchen/pizza/Americana.hpp"

Plazza::Americana::Americana(uint16_t size) : Pizza(PizzaType::Americana, size)
{
    _recipe.push_back(IngredientType::Doe);
    _recipe.push_back(IngredientType::Tomato);
    _recipe.push_back(IngredientType::Gruyere);
    _recipe.push_back(IngredientType::Steak);
}

Plazza::Americana::Americana(uint16_t size, Plazza::Ingredient &doe, Plazza::Ingredient &tomato, Plazza::Ingredient &gruyere, Plazza::Ingredient &steak) : Pizza(PizzaType::Americana, size)
{
    _recipe.push_back(IngredientType::Doe);
    _recipe.push_back(IngredientType::Tomato);
    _recipe.push_back(IngredientType::Gruyere);
    _recipe.push_back(IngredientType::Steak);
    addIngredient(doe);
    addIngredient(tomato);
    addIngredient(gruyere);
    addIngredient(steak);
}

Plazza::Americana::~Americana()
{
}

bool Plazza::Americana::isRecipe() const
{
    unsigned int doe = 0;
    unsigned int tomato = 0;
    unsigned int gruyere = 0;
    unsigned int steak = 0;
    unsigned int otherIngr = 0;

    for (int i = _ingr.size();i >= 0;i--) {
        if (_ingr[i].type() == IngredientType::Doe)
            doe++;
        else if (_ingr[i].type() == IngredientType::Tomato)
            tomato++;
        else if (_ingr[i].type() == IngredientType::Gruyere)
            gruyere++;
        else if (_ingr[i].type() == IngredientType::Steak)
            steak++;
        else
            otherIngr++;
    }
    if (doe >= 1 && tomato >= 1 && gruyere >= 1 && steak >= 1 && !otherIngr)
        return (true);
    else 
        return (false);
}

uint32_t Plazza::Americana::timeCook() const
{
    return (2 * stockage.getMultiplTimeCook());
}