/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Ingredient
*/

#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP

#include "Plazza.hpp"

namespace Plazza {

    enum IngredientType {
        Doe = 1,
        Tomato = 2,
        Gruyere = 4,
        Ham = 8,
        Mushrooms = 16,
        Steak = 32,
        Eggplant = 64,
        GoatCheese = 128,
        ChiefLove = 256
    };

    class Ingredient {
        public:
            Ingredient(Plazza::IngredientType type);
            ~Ingredient();
            Plazza::IngredientType type() const;
        protected:
            Plazza::IngredientType _type;
        private:
    };

};

#endif /* !INGREDIENT_HPP */