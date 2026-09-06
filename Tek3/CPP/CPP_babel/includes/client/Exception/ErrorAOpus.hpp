/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** ErrorAOpus
*/

#ifndef ERRORAOPUS_HPP_
#define ERRORAOPUS_HPP_

#include "AException.hpp"

namespace babel {

    class ErrorAOpus : public AException {
        public:
            ErrorAOpus(std::string component = "[OPUS]", std::string message = "Error Opus", int returnValue = 84);
            virtual ~ErrorAOpus() = default;
    };

}

#endif /* !ERRORAOPUS_HPP_ */
