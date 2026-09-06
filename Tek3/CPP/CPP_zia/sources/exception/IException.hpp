/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IException
*/

#ifndef IEXCEPTION_HPP_
#define IEXCEPTION_HPP_

#include <exception>

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    /**
    * @interface IException
    * Interface of Exception
    */
    class IException : public std::exception
    {
        public:
            virtual ~IException() = default;

            /**
             * @fn what
             * @return const char* message of error
             * @note Return Error message
             */
            virtual const char *what() const noexcept = 0;
            /**
             * @fn getValue
             * @return int value throw
             * @note Return Value of Throw
             */
            virtual int getValue() const noexcept = 0;
    };
} // namespace zia

#endif /* !IEXCEPTION_HPP_ */
