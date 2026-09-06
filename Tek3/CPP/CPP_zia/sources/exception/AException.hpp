/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** AException
*/

#ifndef AEXCEPTION_HPP_
#define AEXCEPTION_HPP_

#include <string>

#include "IException.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    /**
     * @class AException
     * Class abstract of IException
     */
    class AException : public IException
    {
        protected:
            unsigned int _returnValue;
            std::string _messageError;
        public:
            /**
             * @fn AException
             * Abstraction of IException
             * @param component Localisation of throw (this class)
             * @param messageError Message of Error
             * @param value Give a value of Throw (by default 0)
             * @note Construct a new AException object
             */
            AException(const std::string &component, const std::string &messageError = "Default Error", unsigned int value = 0);
            const char *what() const noexcept override final;
            int getValue() const noexcept final;
    };
} // namespace zia

#endif /* !AException */
