/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4008
*/

#include "C_4008.hpp"

C_4008::C_4008(std::string const &_name)
{
    name = _name;
    value = nts::UNDEFINED;
    nbr_pin = 16;
}

nts::Tristate C_4008::compute(std::size_t pin)
{
    nts::Tristate a;
    nts::Tristate b;
    nts::Tristate c;

    if (pin == 10) {
        a = link[6].second->compute(link[6].first);
        b = link[7].second->compute(link[7].first);
        c = link[9].second->compute(link[9].first);
    } else if (pin == 11) {
        a = link[4].second->compute(link[4].first);
        b = link[5].second->compute(link[5].first);
        c = link[14].second->compute(link[14].first);        
    } else if (pin == 12) {
        a = link[2].second->compute(link[2].first);
        b = link[3].second->compute(link[3].first);
        c = link[14].second->compute(link[14].first);
    } else if (pin == 13) {
        a = link[15].second->compute(link[15].first);
        b = link[1].second->compute(link[1].first);
        c = link[14].second->compute(link[14].first);
    } else
        throw Errors("No pin matches", "C_4008");
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED || c == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    if (a + b + c == 0) {
        link[14].second->setValue(nts::Tristate::FALSE);
        return (nts::Tristate::FALSE);
    } else if (a + b + c == 1) {
        link[14].second->setValue(nts::Tristate::FALSE);
        return (nts::Tristate::TRUE);
    } else if (a + b + c == 2) {
        link[14].second->setValue(nts::Tristate::TRUE);
        return (nts::Tristate::TRUE);
    } else
        link[14].second->setValue(nts::Tristate::UNDEFINED);
        return (nts::Tristate::UNDEFINED);
}