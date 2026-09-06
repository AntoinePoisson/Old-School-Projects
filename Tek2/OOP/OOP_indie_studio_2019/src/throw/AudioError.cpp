/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Error
*/

#include "AudioError.hpp"

indie::error::Audio::Audio(const std::string &filepath)
{
    _message = "[indie] Error, can't find Audio: " + filepath;
}

const char *indie::error::Audio::what() const throw()
{
    return _message.c_str();
}