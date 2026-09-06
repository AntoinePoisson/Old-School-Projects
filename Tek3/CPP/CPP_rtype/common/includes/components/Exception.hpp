/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Exception
*/

#ifndef COMMONCOMPONENTEXCEPTION_HPP_
#define COMMONCOMPONENTEXCEPTION_HPP_

#include "AException.hpp"

namespace rtype {
    namespace component {

        class Exception : public rtype::AException
        {
            public:
                Exception(const std::string &str_error, const std::string &componentName = "Component Error", unsigned int valueThrow = 0)
                    : rtype::AException(str_error, componentName, valueThrow) {};
        };
    }
}


#endif /* !COMMONCOMPONENTEXCEPTION_HPP_ */
