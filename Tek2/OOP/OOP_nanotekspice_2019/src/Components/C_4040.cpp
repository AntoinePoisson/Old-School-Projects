/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4040
*/

#include "C_4040.hpp"

C_4040::C_4040(std::string const &_name)
{
    name = _name;
    value = nts::UNDEFINED;
    nbr_pin = 14;
}

nts::Tristate C_4040::compute(std::size_t pin)
{
    if (pin > nbr_pin)
        throw Errors("No pin matches", "C_4040");
    return (nts::TRUE);
}