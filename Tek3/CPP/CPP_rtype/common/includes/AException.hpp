/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Exception
*/

#ifndef COMMONEXCEPTION_HPP_
#define COMMONEXCEPTION_HPP_

#include <iostream>
#include <sstream>

namespace rtype {

    class AException : public std::exception {
        protected:
            unsigned int _value;
            std::string _str_error;
        public:
            AException(const std::string &str_error, const std::string &componentName = "Default Error", unsigned int valueThrow = 0);
            const char *what() const noexcept override;
            int getValue() const noexcept;
    };

    class NetworkException: public AException {
        public:
            NetworkException(const std::string &str_error, const std::string &componentName = "Network Error", unsigned int valueThrow = 0);
    };

    class GameIsFinish: public AException {
        public:
            GameIsFinish(const std::string &str_error, const std::string &componentName = "GameLoop", unsigned int valueThrow = 0);
    };

}


#endif /* !COMMONSYSTEMEXCEPTION_HPP_ */
