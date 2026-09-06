/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_2716
*/

#ifndef C_2716_HPP_
#define C_2716_HPP_

#include "AComponent.hpp"

class C_2716 : public AComponent
{
    public:
        C_2716(std::string const &name);
        ~C_2716() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !C_2716_HPP_ */
