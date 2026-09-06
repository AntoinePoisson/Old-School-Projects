/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4030
*/

#ifndef C_4030_HPP_
#define C_4030_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class C_4030 : public AComponent
{
    public:
        C_4030(std::string const &name);
        virtual ~C_4030() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !C_4030_HPP_ */
