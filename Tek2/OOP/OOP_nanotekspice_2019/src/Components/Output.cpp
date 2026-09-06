/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(std::string const &_name)
{
    name = _name;
    value = nts::UNDEFINED;
    nbr_pin = 1;
}

nts::Tristate Output::compute(size_t pin)
{
    if (pin != 1)
        throw Errors("No pin matches", "Output");
    value = link[pin].second->compute(link[pin].first);
    return (value);
}