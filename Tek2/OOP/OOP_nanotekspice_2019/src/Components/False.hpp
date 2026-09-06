/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class False : public AComponent
{
    public:
        False(std::string const &_name);
        virtual ~False() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !FALSE_HPP_ */
