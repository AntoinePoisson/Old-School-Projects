/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class True : public AComponent
{
    public:
        True(std::string const &_name);
        virtual ~True() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !TRUE_HPP_ */
