/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** QuitServer
*/

#ifndef QUITSERVER_HPP_
#define QUITSERVER_HPP_

#include "AException.hpp"
#include "Babel.hpp"

namespace babel {

    class QuitServer : public AException {
        public:
            QuitServer(std::string component = "[Status]", std::string message = "Server Close", int returnValue = Ok);
            virtual ~QuitServer() = default;
    };

}

#endif /* !QUITSERVER_HPP_ */
