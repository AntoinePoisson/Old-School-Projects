/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include "IBase.hpp"

namespace indie
{
    namespace error
    {
        class Error : public indie::error::IBase
        {
            public:
                Error(std::string const &component = "Unknown", std::string const &message = "", int returnValue = 84);
                virtual ~Error() = default;

                const char *what() const throw();
                std::string const &getComponent() const;
                int getValue() const;
            private:
                std::string message;
                std::string component;
                int returnValue;
                bool messageVoid;
        };
    }
}

#endif