/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4017
*/

#ifndef C_4017_HPP_
#define C_4017_HPP_

#include "AComponent.hpp"

class C_4017 : public AComponent
{
    public:
        C_4017(std::string const &name);
        virtual ~C_4017() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !C_4017_HPP_ */
