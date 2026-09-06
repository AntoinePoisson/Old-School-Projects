/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** ConnectionHttp
*/

#ifndef CONNECTIONHTTP_HPP_
#define CONNECTIONHTTP_HPP_

#include "api/io/IConnection.hpp"
#include "api/io/Connection.hpp"

class ConnectionHttp: public Zia::IConnection
{
    public:
        ConnectionHttp(Zia::Connection &connection);
        ~ConnectionHttp();

        size_t read(size_t buf_size, char *buf);
        size_t write(size_t buf_size, const char *buf);
        void log(const std::string &str);
        const std::string &getRemoteIP(void) const;
        int getNativeSocket(void) const;
    private:
        Zia::Connection &_connection;
};

#endif /* !CONNECTIONHTTP_HPP_ */
