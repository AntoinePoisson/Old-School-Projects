/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4081
*/

#include "C_4081.hpp"

C_4081::C_4081(std::string const &_name)
{
    name = _name;
    value = nts::UNDEFINED;
    nbr_pin = 14;
}

nts::Tristate C_4081::compute(std::size_t pin)
{
    nts::Tristate a;
    nts::Tristate b;

    if (pin == 3) {
        a = link[1].second->compute(link[1].first);
        b = link[2].second->compute(link[2].first);
    } else if (pin == 4) {
        a = link[5].second->compute(link[5].first);
        b = link[6].second->compute(link[6].first);
    } else if (pin == 10) {
        a = link[8].second->compute(link[8].first);
        b = link[9].second->compute(link[9].first);
    } else if (pin == 11) {
        a = link[12].second->compute(link[12].first);
        b = link[13].second->compute(link[13].first);
    } else
        throw Errors("No pin matches", "C_4081");
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    return (static_cast<nts::Tristate>(a && b));
}