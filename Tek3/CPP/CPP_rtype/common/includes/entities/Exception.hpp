/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Exception
*/

#ifndef COMMONENTITYEXCEPTION_HPP_
#define COMMONENTITYEXCEPTION_HPP_

#include "AException.hpp"

namespace rtype {
    namespace entity {

        class Exception : public rtype::AException
        {
            public:
                Exception(const std::string &str_error, const std::string &componentName = "Entity Error", unsigned int valueThrow = 0)
                    : rtype::AException(str_error, componentName, valueThrow) {};
        };

    }
}


#endif /* !COMMONENTITYEXCEPTION_HPP_ */
