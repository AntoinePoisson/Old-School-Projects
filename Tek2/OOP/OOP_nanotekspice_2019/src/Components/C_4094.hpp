/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4094
*/

#ifndef C_4094_HPP_
#define C_4094_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class C_4094 : public AComponent
{
    public:
        C_4094(std::string const &name);
        virtual ~C_4094() = default;

        nts::Tristate compute(std::size_t pin = 1);

};

#endif /* !C_4094_HPP_ */
