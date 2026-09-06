/*
** EPITECH PROJECT, 2020
** Box
** File description:
** Box
*/

#include "Box.hpp"

Box::Box()
{
}

Box::Box(std::string str) : Wrap(str)
{
}

Box::~Box()
{
}

void Box::wrapMeThat(Object *obj)
{
    if (open)
        Wrap::wrapMeThat(obj);
    else 
        std::cerr << "The Box need to be open" << std::endl;
}

void Box::closeMe()
{
    open = false;
}