/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Exception
*/

#ifndef COMMONSYSTEMEXCEPTION_HPP_
#define COMMONSYSTEMEXCEPTION_HPP_

#include "AException.hpp"

namespace rtype {
    namespace system {

        class Exception : public rtype::AException
        {
            public:
                Exception(const std::string &str_error, const std::string &componentName = "System Error", unsigned int valueThrow = 0)
                    : rtype::AException(str_error, componentName, valueThrow) {};
        };

    }
}


#endif /* !COMMONSYSTEMEXCEPTION_HPP_ */
