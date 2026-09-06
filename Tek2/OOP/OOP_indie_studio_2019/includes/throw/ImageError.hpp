/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image
*/

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "IBase.hpp"

namespace indie
{
    namespace error
    {
        class Image : public indie::error::IBase
        {
            public:
                Image(const std::string &filepath = "unknown");
                virtual ~Image() = default;

                const char *what() const throw();
            private:
                std::string _message;
        };
    }
}

#endif