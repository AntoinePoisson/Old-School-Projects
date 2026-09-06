/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4514
*/

#ifndef C_4514_HPP_
#define C_4514_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class C_4514 : public AComponent
{
    public:
        C_4514(std::string const &name);
        virtual ~C_4514() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !C_4514_HPP_ */
