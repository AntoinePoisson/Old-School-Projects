/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Mesh
*/

#ifndef MESHERROR_HPP_
#define MESHERROR_HPP_

#include "IBase.hpp"

namespace indie
{
    namespace error
    {
        class Mesh : public indie::error::IBase
        {
            public:
                Mesh(const std::string &filepath = "unknown");
                virtual ~Mesh() = default;

                const char *what() const throw();
            private:
                std::string _message;
        };
    }
}

#endif