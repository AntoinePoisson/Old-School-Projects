/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** CantUsePA
*/

#ifndef CANTUSEPA_HPP_
#define CANTUSEPA_HPP_

#include "AException.hpp"

namespace babel {

    class CantUsePA : public AException {
        public:
            CantUsePA(std::string component = "[PA]", std::string message = "Can't Audio", int returnValue = 84);
            virtual ~CantUsePA() = default;
    };

}

#endif /* !CANTUSEPA_HPP_ */
