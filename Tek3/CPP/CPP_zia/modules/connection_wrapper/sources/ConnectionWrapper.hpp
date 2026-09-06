/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** ConnectionWrapper
*/

#ifndef CONNECTIONWRAPPER_HPP_
#define CONNECTIONWRAPPER_HPP_

#include <string>
#include "IConnectionWrapper.hpp"

class ConnectionWrapper: public Zia::Module::IConnectionWrapper
{
    public:
        ConnectionWrapper();
        ~ConnectionWrapper();

        std::unique_ptr<Zia::IConnection> create(Zia::IConnection &connection);
};

#endif /* !CONNECTIONWRAPPER_HPP_ */
