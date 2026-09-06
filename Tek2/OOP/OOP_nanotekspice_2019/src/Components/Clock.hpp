/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class Clock : public AComponent
{
    public:
        Clock(std::string const &name);
        virtual ~Clock() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !CLOCK_HPP_ */
