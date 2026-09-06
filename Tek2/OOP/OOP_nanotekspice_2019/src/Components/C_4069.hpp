/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4069
*/

#ifndef C_4069_HPP_
#define C_4069_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class C_4069 : public AComponent
{
    public:
        C_4069(std::string const &name);
        virtual ~C_4069() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !C_4069_HPP_ */