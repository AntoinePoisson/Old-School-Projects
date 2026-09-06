/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#include <iostream>
#include "Factory.hpp"

std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string &type, const std::string &value)
{
    std::unique_ptr<nts::IComponent> base;

    if (type.compare("input") == 0) {
        base = std::make_unique<Input>(value);
        return (base);
    }
    if (type.compare("clock") == 0){
        base = std::make_unique<Clock>(value);
        return (base);
    }
    if (type.compare("true") == 0) {
        base = std::make_unique<True>(value);
        return (base);
    }
    if (type.compare("false") == 0) {
        base = std::make_unique<False>(value);
        return (base);
    }
    if (type.compare("output") == 0) {
        base = std::make_unique<Output>(value);
        return (base);
    }
    if (type.compare("4001") == 0) {
        base = std::make_unique<C_4001>(value);
        return (base);
    }
    if (type.compare("4008") == 0) {
        base = std::make_unique<C_4008>(value);
        return (base);
    }
    if (type.compare("4013") == 0) {
        base = std::make_unique<C_4013>(value);
        return (base);
    }
    if (type.compare("4017") == 0) {
        base = std::make_unique<C_4017>(value);
        return (base);
    }
    if (type.compare("4030") == 0) {
        base = std::make_unique<C_4030>(value);
        return (base);
    }
    if (type.compare("4040") == 0) {
        base = std::make_unique<C_4040>(value);
        return (base);
    }
    if (type.compare("4069") == 0) {
        base = std::make_unique<C_4069>(value);
        return (base);
    }
    if (type.compare("4071") == 0) {
        base = std::make_unique<C_4071>(value);
        return (base);
    }
    if (type.compare("4081") == 0) {
        base = std::make_unique<C_4081>(value);
        return (base);
    }
    if (type.compare("4094") == 0) {
        base = std::make_unique<C_4094>(value);
        return (base);
    }
    if (type.compare("4514") == 0) {
        base = std::make_unique<C_4514>(value);
        return (base);
    }
    if (type.compare("4801") == 0) {
        base = std::make_unique<C_4801>(value);
        return (base);
    }
    if (type.compare("2716") == 0) {
        base = std::make_unique<C_2716>(value);
        return (base);
    }
    else {
        std::cout << type << std::endl;
        throw Errors("Component unknown", "Factory");
    }
}