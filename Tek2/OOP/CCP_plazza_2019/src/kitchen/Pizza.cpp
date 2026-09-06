/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Pizza
*/

#include "kitchen/Pizza.hpp"

Plazza::Pizza::Pizza(uint16_t type, uint16_t size) : _type(type), _size(size)
{
}

Plazza::Pizza::~Pizza()
{
}

void Plazza::Pizza::addIngredient(Plazza::Ingredient &ingr)
{
    _ingr.push_back(ingr);
}

std::vector<Plazza::Ingredient> const &Plazza::Pizza::getIngredients()
{
    return (_ingr);
}

std::vector<Plazza::IngredientType> const &Plazza::Pizza::getRecipe()
{
    return (_recipe);
}