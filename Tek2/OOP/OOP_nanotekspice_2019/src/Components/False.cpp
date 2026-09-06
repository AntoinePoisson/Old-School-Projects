/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#include "False.hpp"

False::False(std::string const &_name)
{
    name = _name;
    value = nts::FALSE;
    nbr_pin = 1;
}

nts::Tristate False::compute(size_t pin)
{
    if (pin != 1)
        throw Errors("No pin matches", "False");
    return (value);
}