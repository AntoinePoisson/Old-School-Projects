/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4081
*/

#ifndef C_4081_HPP_
#define C_4081_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class C_4081 : public AComponent
{
    public:
        C_4081(std::string const &name);
        virtual ~C_4081() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !C_4081_HPP_ */
