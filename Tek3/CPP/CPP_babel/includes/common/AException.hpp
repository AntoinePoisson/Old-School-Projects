/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** AException
*/

#ifndef AEXCEPTION_HPP_
#define AEXCEPTION_HPP_

#include "IException.hpp"

namespace babel {

    class AException : public IException {
        public:
            virtual ~AException() = default;

            const char *what() const throw() final;
            std::string const &getComponent(void) const final;
            std::string const &getMessage(void) const final;
            int getValue(void) const final;
            void print(void) const final;
        protected:
            std::string _message;
            std::string _component;
            int _returnValue;
            bool _messageVoid;
    };

}

#endif /* !AEXCEPTION_HPP_ */
