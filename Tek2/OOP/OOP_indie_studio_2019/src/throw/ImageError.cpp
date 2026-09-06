/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Error
*/

#include "ImageError.hpp"

indie::error::Image::Image(const std::string &filepath)
{
    _message = "[indie] Error, can't find image: " + filepath;
}
const char *indie::error::Image::what() const throw()
{
    return _message.c_str();
}