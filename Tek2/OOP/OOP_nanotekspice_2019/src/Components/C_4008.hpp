/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4008
*/

#ifndef C_4008_HPP_
#define C_4008_HPP_

#include "AComponent.hpp"

class C_4008 : public AComponent
{
    public:
        C_4008(std::string const &name);
        virtual ~C_4008() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !C_4008_HPP_ */
