/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4017
*/

#include "C_4017.hpp"
#include "../Error/Errors.hpp"

C_4017::C_4017(std::string const &_name)
{
    name = _name;
    value = nts::UNDEFINED;
    nbr_pin = 14;
}

nts::Tristate C_4017::compute(std::size_t pin)
{
    if (pin > nbr_pin)
        throw Errors("No pin matches", "C_4017");
    return (nts::TRUE);
}