/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Audio
*/

#ifndef AUDIOERRO_HPP_
#define AUDIOERRO_HPP_

#include "IBase.hpp"

namespace indie
{
    namespace error
    {
        class Audio : public indie::error::IBase
        {
            public:
                Audio(const std::string &filepath = "unknown");
                virtual ~Audio() = default;

                const char *what() const throw();
            private:
                std::string _message;
        };
    }
}

#endif