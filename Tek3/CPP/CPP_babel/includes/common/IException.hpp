/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** IException
*/

#ifndef IEXCEPTION_HPP_
#define IEXCEPTION_HPP_

#include <exception>
#include <string>
#include <iostream>

namespace babel {

    class IException : public std::exception {
        public:
            virtual ~IException() = default;

            virtual const char *what(void) const throw() = 0;
            virtual std::string const &getComponent(void) const = 0;
            virtual std::string const &getMessage(void) const = 0;
            virtual int getValue(void) const = 0;
            virtual void print(void) const = 0;
    };

}

#endif /* !IEXCEPTION_HPP_ */
