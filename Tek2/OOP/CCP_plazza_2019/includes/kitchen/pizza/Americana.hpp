/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Americana
*/

#ifndef AMERICANA_HPP
#define AMERICANA_HPP

#include "kitchen/Pizza.hpp"

namespace Plazza {

    class Americana : public Pizza {
        public:
            Americana(uint16_t size);
            Americana(uint16_t size, Plazza::Ingredient &doe, Plazza::Ingredient &tomato, Plazza::Ingredient &gruyere, Plazza::Ingredient &steak);
            ~Americana();
            virtual bool isRecipe() const;
            virtual uint32_t timeCook() const;
        protected:
        private:
    };

};

#endif /* !AMERICANA_HPP */
