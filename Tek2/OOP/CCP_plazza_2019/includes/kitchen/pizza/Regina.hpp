/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Regina
*/

#ifndef REGINA_HPP
#define REGINA_HPP

#include "kitchen/Pizza.hpp"

namespace Plazza {

    class Regina : public Pizza{
        public:
            Regina(uint16_t size);
            ~Regina();
            virtual bool isRecipe() const;
            virtual uint32_t timeCook() const;
        protected:
        private:
    };

};

#endif /* !REGINA_HPP */
