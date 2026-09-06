/*
** EPITECH PROJECT, 2020
** Object
** File description:
** Object
*/

#include "Object.hpp"

Object::Object() : title("")
{
}

Object::Object(std::string str)
{
    title = str;
}

Object::~Object()
{
}

std::string Object::getTitle() const
{
    return (title);
}