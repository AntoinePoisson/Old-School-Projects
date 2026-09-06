/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4011
*/

#ifndef C_4011_HPP_
#define C_4011_HPP_

#include "AComponent.hpp"

class C_4011 : public AComponent
{
    public:
        C_4011(std::string const &name);
        virtual ~C_4011() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !C_4011_HPP_ */
