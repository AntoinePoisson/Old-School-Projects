/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_2716
*/

#include "C_2716.hpp"

C_2716::C_2716(std::string const &_name)
{
    name = _name;
    value = nts::UNDEFINED;
    nbr_pin = 14;
}

nts::Tristate C_2716::compute(std::size_t pin)
{
    if (pin > nbr_pin)
        throw Errors("No pin matches", "C_4017");
    return (nts::TRUE);
}