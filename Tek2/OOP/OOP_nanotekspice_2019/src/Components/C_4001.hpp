/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4001
*/

#ifndef C_4001_HPP_
#define C_4001_HPP_

#include "AComponent.hpp"

class C_4001 : public AComponent
{
    public:
        C_4001(std::string const &name);
        virtual ~C_4001() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !C_4001_HPP_ */
