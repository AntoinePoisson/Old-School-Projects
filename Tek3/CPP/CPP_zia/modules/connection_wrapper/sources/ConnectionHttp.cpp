/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** ConnectionHttp
*/

#include "ConnectionHttp.hpp"

ConnectionHttp::ConnectionHttp(Zia::Connection &connection): _connection(connection)
{
}

ConnectionHttp::~ConnectionHttp()
{
    _connection.disconnecting();
}

size_t ConnectionHttp::read(size_t buf_size, char *buf)
{
    return (_connection.read(buf_size, buf));
}

size_t ConnectionHttp::write(size_t buf_size, const char *buf)
{
    return (_connection.write(buf_size, buf));
}

void ConnectionHttp::log(const std::string &str)
{
    _connection.log(str);
}

const std::string &ConnectionHttp::getRemoteIP(void) const
{
    return (_connection.getRemoteIP());
}

int ConnectionHttp::getNativeSocket(void) const
{
    return (_connection.getNativeSocket());
}
