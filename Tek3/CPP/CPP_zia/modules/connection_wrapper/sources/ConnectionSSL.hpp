/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** ConnectionSSL
*/

#ifndef CONNECTIONSSL_HPP_
#define CONNECTIONSSL_HPP_

#include <openssl/ssl.h>
#include <openssl/err.h>
#include "api/io/IConnection.hpp"
#include "exception/AException.hpp"
#include "api/io/Connection.hpp"

#define THROW_SSL_ERROR(arg) ; throw(Zia::AException("OpenSSL", arg + std::string(ERR_reason_error_string(ERR_get_error()))));


class ConnectionSSL: public Zia::IConnection
{
    public:
        ConnectionSSL(Zia::Connection &connection);
        ~ConnectionSSL();

        size_t read(size_t buf_size, char *buf);
        size_t write(size_t buf_size, char const *buf);
        void log(const std::string &str);
        const std::string& getRemoteIP(void) const;
        int getNativeSocket(void) const;
    private:
        SSL *_ssl;
        SSL_CTX *_context;
        Zia::Connection &_connection;
};

#endif /* !CONNECTIONSSL_HPP_ */
