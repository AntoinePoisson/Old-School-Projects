/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Fantasia
*/

#ifndef FANTASIA_HPP
#define FANTASIA_HPP

#include "kitchen/Pizza.hpp"

namespace Plazza {

    class Fantasia : public Pizza{
        public:
            Fantasia(uint16_t size);
            ~Fantasia();
            virtual bool isRecipe() const;
            virtual uint32_t timeCook() const;
        protected:
        private:
    };

};


#endif /* !FANTASIA_HPP */
