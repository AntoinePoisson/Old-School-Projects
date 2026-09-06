/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4069
*/

#include "C_4069.hpp"

C_4069::C_4069(std::string const &_name)
{
    name = _name;
    value = nts::UNDEFINED;
    nbr_pin = 14;
}

nts::Tristate C_4069::compute(std::size_t pin)
{
    nts::Tristate a;
    nts::Tristate b;

    if (pin == 2) {
        a = link[1].second->compute(link[1].first);
    } else if (pin == 4) {
        a = link[3].second->compute(link[3].first);
    } else if (pin == 6) {
        a = link[5].second->compute(link[5].first);
    } else if (pin == 8) {
        a = link[9].second->compute(link[9].first);
    } else if (pin == 10) {
        a = link[11].second->compute(link[11].first);
    } else if (pin == 12) {
        a = link[13].second->compute(link[13].first);
    } else
        throw Errors("No pin matches", "C_4069");
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    return (static_cast<nts::Tristate>(!a));
}