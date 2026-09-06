/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Margarita
*/

#ifndef MARGARITA_HPP
#define MARGARITA_HPP

#include "kitchen/Pizza.hpp"

namespace Plazza {

    class Margarita : public Pizza{
        public:
            Margarita(uint16_t size);
            ~Margarita();
            virtual bool isRecipe() const;
            virtual uint32_t timeCook() const;
        protected:
        private:
    };

};


#endif /* !MARGARITA_HPP */
