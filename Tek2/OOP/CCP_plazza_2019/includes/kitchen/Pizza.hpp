/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Pizza
*/

#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <vector>
#include <chrono>
#include "Plazza.hpp"
#include "kitchen/Ingredient.hpp"

namespace Plazza {

    class Pizza {
        public:
            Pizza(uint16_t type, uint16_t size);
            virtual ~Pizza();
            virtual void addIngredient(Plazza::Ingredient &ingr);
            virtual std::vector<Plazza::Ingredient> const &getIngredients();
            virtual std::vector<Plazza::IngredientType> const &getRecipe();
            virtual bool isRecipe() const = 0;
            virtual uint32_t timeCook() const = 0;
        protected:
            uint16_t _type;
            uint16_t _size;
            std::vector<Plazza::Ingredient> _ingr;
            std::vector<Plazza::IngredientType> _recipe;
        private:
    };

};

#endif /* !PIZZA_HPP */
