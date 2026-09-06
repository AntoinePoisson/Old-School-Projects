/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <string>
#include <map>
#include <iostream>
#include "IComponent.hpp"
#include "../Error/Errors.hpp"


class AComponent : public nts::IComponent
{
    public:
        AComponent() = default;
        virtual ~AComponent() = default;

        virtual nts::Tristate compute(std::size_t pin = 1) = 0;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        nts::Tristate getValue(void) const;
        std::string getName(void) const;

        void setValue(nts::Tristate _value);
        bool isLink(void) const;
    private:
};

#endif /* !ACOMPONENT_HPP_ */
