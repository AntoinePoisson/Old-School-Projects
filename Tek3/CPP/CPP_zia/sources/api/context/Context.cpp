/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Context
*/

#include "Context.hpp"

    //! Public
Zia::Context::~Context()
{
    _data.clear();
}

const std::any *Zia::Context::get(const std::string &key) const
{
    if (_data.find(key) == _data.end())
        return nullptr;
    return &(_data.find(key)->second);
}

void Zia::Context::set(const std::string &key, const std::any &value)
{
    _data[key] = value;
}