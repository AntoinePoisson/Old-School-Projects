/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4013
*/

#ifndef C_4013_HPP_
#define C_4013_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class C_4013 : public AComponent
{
    public:
        C_4013(std::string const &name);
        virtual ~C_4013() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !C_4013_HPP_ */
