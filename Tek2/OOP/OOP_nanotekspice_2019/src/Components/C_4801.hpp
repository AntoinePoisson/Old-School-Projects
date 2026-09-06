/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C_4801
*/

#ifndef C_4801_HPP_
#define C_4801_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class C_4801 : public AComponent
{
    public:
        C_4801(std::string const &name);
        virtual ~C_4801() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !C_4801_HPP_ */
