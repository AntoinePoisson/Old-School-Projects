/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(std::string const &_name)
{
    name = _name;
    value = nts::UNDEFINED;
    nbr_pin = 1;
}

nts::Tristate Input::compute(size_t pin)
{
    if (pin != 1)
        throw Errors("No pin matches", "Input");
    return (value);
}