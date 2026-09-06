/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#include "True.hpp"

True::True(std::string const &_name)
{
    name = _name;
    value = nts::TRUE;
    nbr_pin = 1;
}

nts::Tristate True::compute(size_t pin)
{
    if (pin != 1)
        throw Errors("No pin matches", "True");
    return (value);
}