/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Margarita
*/

#include "kitchen/pizza/Margarita.hpp"

Plazza::Margarita::Margarita(uint16_t size) : Pizza(PizzaType::Margarita, size)
{
    _recipe.push_back(IngredientType::Doe);
    _recipe.push_back(IngredientType::Tomato);
    _recipe.push_back(IngredientType::Gruyere);
}

Plazza::Margarita::~Margarita()
{
}

bool Plazza::Margarita::isRecipe() const
{
    unsigned int doe = 0;
    unsigned int tomato = 0;
    unsigned int gruyere = 0;
    unsigned int otherIngr = 0;

    for (int i = _ingr.size();i >= 0;i--) {
        if (_ingr[i].type() == IngredientType::Doe)
            doe++;
        else if (_ingr[i].type() == IngredientType::Tomato)
            tomato++;
        else if (_ingr[i].type() == IngredientType::Eggplant)
            gruyere++;
        else
            otherIngr++;
    }
    if (doe >= 1 && tomato >= 1 && gruyere >= 1 && !otherIngr)
        return (true);
    else 
        return (false);
}

uint32_t Plazza::Margarita::timeCook() const
{
    return (1 * stockage.getMultiplTimeCook());
}