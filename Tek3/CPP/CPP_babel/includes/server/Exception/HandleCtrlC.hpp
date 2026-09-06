/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** HandleCtrlC
*/

#ifndef HANDLECTRLC_HPP_
#define HANDLECTRLC_HPP_

#include "Babel.hpp"
#include "AException.hpp"

namespace babel {

    class HandleCtrlC : public AException {
        public:
            HandleCtrlC(std::string component = "\n[Ctrl C]", std::string message = "The server will Shutdown", int returnValue = Ok);
            virtual ~HandleCtrlC() = default;
    };

}

#endif /* !HANDLECTRLC_HPP_ */
