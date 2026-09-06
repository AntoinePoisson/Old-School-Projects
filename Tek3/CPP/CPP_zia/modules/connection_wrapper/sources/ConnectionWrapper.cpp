/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** ConnectionWrapper
*/

#include "ConnectionWrapper.hpp"
#include "ConnectionSSL.hpp"
#include "ConnectionHttp.hpp"

ConnectionWrapper::ConnectionWrapper()
{
}

ConnectionWrapper::~ConnectionWrapper()
{
}

std::unique_ptr<Zia::IConnection> ConnectionWrapper::create(Zia::IConnection &connection)
{
    Zia::Connection &connect = reinterpret_cast<Zia::Connection&>(connection);
    try {
        if (connect.getHttpType() == Zia::TypeRequest_e::Https) {
            connection.log("[ConnectionWrapper] https request");
            return (std::make_unique<ConnectionSSL>(connect));
        } else {
            connection.log("[ConnectionWrapper] http request");
            return (std::make_unique<ConnectionHttp>(connect));
        }
    } catch (const std::exception &err) {
        connect.log("[ConnectionWrapper] error: " + std::string(err.what()));
        return (nullptr);
    }
}