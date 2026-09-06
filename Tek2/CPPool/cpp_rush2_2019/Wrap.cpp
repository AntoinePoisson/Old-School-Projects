/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap() 
{
    object = nullptr;
    open = false;
}

Wrap::Wrap(std::string str) : Object(str)
{
    object = nullptr;
    open = false;
}

Wrap::~Wrap()
{
}

void Wrap::wrapMeThat(Object *obj)
{
    if (!object) {
        object = obj;
        open = false;
        std::cout << "tuuuut tuuut tuut" << std::endl;
    } else 
        std::cerr << "Wrap already contain an object" << std::endl;
}

void Wrap::openMe()
{
    open = true;
}

Object *Wrap::getObject()
{
    Object *temp = object;

    if (open && temp) {
        temp->isTaken();
        object = nullptr;
        return (temp);
    } else {
        return (nullptr);
    }
}

void Wrap::isTaken() const
{
    std::cout << "whistles while working" << std::endl;
}