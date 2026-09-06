/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Acomponent
*/

#include "AComponent.hpp"

void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > nbr_pin)
        throw Errors("setLink does not allow this number of pin", "AComponent");
    link[pin] = std::make_pair(otherPin, &other);
}

void AComponent::dump() const
{
    std::cout << "COMPONENT: " << name << " is linked to:" << std::endl;
    for (auto it = link.begin(); it != link.end(); it++)
        std::cout << "PIN " << it->first <<" to component " << it->second.second->getName() << "and his pin" << it->second.first << std::endl;
}

nts::Tristate AComponent::getValue(void) const
{
    return (value);
}

std::string AComponent::getName(void) const
{
    return (name);
}

void AComponent::setValue(nts::Tristate _value)
{
    value = _value;
}

bool AComponent::isLink(void) const
{
    return (link.size() ? true : false);
}