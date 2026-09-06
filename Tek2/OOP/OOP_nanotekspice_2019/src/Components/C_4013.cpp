/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4013
*/

#include "C_4013.hpp"

C_4013::C_4013(std::string const &_name)
{
    name = _name;
    value = nts::UNDEFINED;
    nbr_pin = 14;
}

nts::Tristate C_4013::compute(std::size_t pin)
{
    nts::Tristate clock;
    nts::Tristate data;
    nts::Tristate reset;
    nts::Tristate set;

    if (pin == 1 || pin == 2) {
        clock = link[3].second->compute(link[3].first);
        data = link[4].second->compute(link[4].first);
        reset = link[5].second->compute(link[5].first);
        set = link[6].second->compute(link[6].first);
    } else if (pin == 13 || pin == 12) {
        clock = link[11].second->compute(link[11].first);
        data = link[10].second->compute(link[10].first);
        reset = link[9].second->compute(link[9].first);
        set = link[8].second->compute(link[8].first);
    } else
        throw Errors("No pin matches", "C_4013");
    if (clock == nts::Tristate::UNDEFINED || data == nts::Tristate::UNDEFINED || reset == nts::Tristate::UNDEFINED || set == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    if (reset == 1) {
        if (set == 1) {
            if (pin == 1) {
                link[2].second->setValue(nts::TRUE);
                return (nts::TRUE);
            }
            if (pin == 2) {
                link[1].second->setValue(nts::TRUE);
                return (nts::TRUE);
            }
            if (pin == 13) {
                link[12].second->setValue(nts::TRUE);
                return (nts::TRUE);
            }
            if (pin == 12) {
                link[13].second->setValue(nts::TRUE);
                return (nts::TRUE);
            }
        } else {
            if (pin == 1) {
                link[2].second->setValue(nts::TRUE);
                return (nts::FALSE);
            }
            if (pin == 2) {
                link[1].second->setValue(nts::FALSE);
                return (nts::TRUE);
            }
            if (pin == 13) {
                link[12].second->setValue(nts::TRUE);
                return (nts::FALSE);
            }
            if (pin == 12) {
                link[13].second->setValue(nts::FALSE);
                return (nts::TRUE);
            }
        }
    } else {
        if (set == 1) {
            if (pin == 1) {
                link[2].second->setValue(nts::FALSE);
                return (nts::TRUE);
            }
            if (pin == 2) {
                link[1].second->setValue(nts::TRUE);
                return (nts::FALSE);
            }
            if (pin == 13) {
                link[12].second->setValue(nts::FALSE);
                return (nts::TRUE);
            }
            if (pin == 12) {
                link[13].second->setValue(nts::TRUE);
                return (nts::FALSE);
            }
        } else {
            if (clock == 0) {
                if (data == 0) {
                    if (pin == 1) {
                        link[2].second->setValue(nts::TRUE);
                        return (nts::FALSE);
                    }
                    if (pin == 2) {
                        link[1].second->setValue(nts::FALSE);
                        return (nts::TRUE);
                    }
                    if (pin == 13) {
                        link[12].second->setValue(nts::TRUE);
                        return (nts::FALSE);
                    }
                    if (pin == 12) {
                        link[13].second->setValue(nts::FALSE);
                        return (nts::TRUE);
                    }
                } else {
                    if (pin == 1) {
                        link[2].second->setValue(nts::FALSE);
                        return (nts::TRUE);
                    }
                    if (pin == 2) {
                        link[1].second->setValue(nts::TRUE);
                        return (nts::FALSE);
                    }
                    if (pin == 13) {
                        link[12].second->setValue(nts::FALSE);
                        return (nts::TRUE);
                    }
                    if (pin == 12) {
                        link[13].second->setValue(nts::TRUE);
                        return (nts::FALSE);
                    }
                }
            } else {
                if (pin == 1)
                    return (link[1].second->compute(link[1].first));
                if (pin == 2)
                    return (link[2].second->compute(link[2].first));
                if (pin == 13)
                    return (link[13].second->compute(link[13].first));
                if (pin == 12)
                    return (link[12].second->compute(link[12].first));
            }
        }
    }
    return (nts::Tristate::TRUE);
}