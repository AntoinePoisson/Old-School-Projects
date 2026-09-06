/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AComponent.hpp"
#include "../Error/Errors.hpp"

class Input : public AComponent
{
    public:
        Input(std::string const &name);
        virtual ~Input() = default;

        nts::Tristate compute(std::size_t pin = 1);

};

#endif /* !INPUT_HPP_ */
