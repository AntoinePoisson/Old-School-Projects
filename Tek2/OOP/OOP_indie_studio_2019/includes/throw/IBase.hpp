/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Error
*/

#ifndef IBASE_HPP_
#define IBASE_HPP_

#include <string>
#include <exception>

namespace indie
{
    namespace error
    {
        class IBase : public std::exception
        {
            public:
                virtual ~IBase() = default;
                const char *what() const throw() = 0;
        };
    }
}

#endif