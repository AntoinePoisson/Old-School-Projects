/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(std::string const &_name)
{
    name = _name;
    value = nts::UNDEFINED;
    nbr_pin = 1;
}

nts::Tristate Clock::compute(size_t pin)
{
    nts::Tristate ret = value;

    if (pin != 1)
        throw Errors("No pin matches", "Clock");
    if (value == nts::TRUE)
        value = nts::FALSE;
    else if (value == nts::FALSE)
        value = nts::TRUE;
    else
        value = nts::UNDEFINED;
    return (ret);
}