/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Error
*/

#include "MeshError.hpp"

indie::error::Mesh::Mesh(const std::string &filepath)
{
    _message = "[indie] Error, can't find Mesh: " + filepath;
}
const char *indie::error::Mesh::what() const throw()
{
    return _message.c_str();
}