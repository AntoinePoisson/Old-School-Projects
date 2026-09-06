/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4801
*/

#include "C_4801.hpp"

C_4801::C_4801(std::string const &_name)
{
    name = _name;
    value = nts::UNDEFINED;
    nbr_pin = 24;
}

nts::Tristate C_4801::compute(std::size_t pin)
{
    if (pin > nbr_pin)
        throw Errors("No pin matches", "C_4801");
    return (nts::TRUE);
}