/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <cstddef>
#include <memory>
#include <map>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;

        public:
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;

            virtual nts::Tristate getValue(void) const = 0;
            virtual std::string getName(void) const = 0;

            virtual void setValue(nts::Tristate _value) = 0;
            virtual bool isLink(void) const = 0;

        protected:
            std::string name;
            nts::Tristate value;
            std::size_t nbr_pin;
            std::map<std::size_t, std::pair<std::size_t, IComponent *>> link;
    };
} // namespace nts

#endif /* !ICOMPONENT_HPP_ */
