/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Ingredient
*/

#include "kitchen/Ingredient.hpp"

Plazza::Ingredient::Ingredient(Plazza::IngredientType type) : _type(type)
{
}

Plazza::Ingredient::~Ingredient()
{
}

Plazza::IngredientType Plazza::Ingredient::type() const
{
    return (_type);
}