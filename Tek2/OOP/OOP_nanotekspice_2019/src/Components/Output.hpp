/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class Output : public AComponent
{
    public:
        Output(std::string const &_name);
        virtual ~Output() = default;

        nts::Tristate compute(std::size_t pin = 1);
};

#endif /* !OUTPUT_HPP_ */
