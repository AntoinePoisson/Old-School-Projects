/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** ConnectionSSL
*/

#include <fcntl.h>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <openssl/err.h>
#include <openssl/ssl3.h>
#include <openssl/ssl.h>
#include <openssl/tls1.h>
#include "api/io/Connection.hpp"
#include "ConnectionSSL.hpp"

ConnectionSSL::ConnectionSSL(Zia::Connection &connection): _connection(connection)
{
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    const SSL_METHOD *method;
    method = TLS_server_method();
    _context = SSL_CTX_new(method);
    if (!_context) {
        throw(Zia::AException("OpenSSL", std::strerror(errno)));
    }

    // Set the key and cert
    if (SSL_CTX_use_certificate_file(_context, "cert.pem", SSL_FILETYPE_PEM) <= 0) {
        THROW_SSL_ERROR("cert.pem:");
    }
    if (SSL_CTX_use_PrivateKey_file(_context, "key.pem", SSL_FILETYPE_PEM) <= 0 ) {
        THROW_SSL_ERROR("key.pem:");
    }
    if (!SSL_CTX_check_private_key(_context)) {
        throw(Zia::AException("OpenSSL", "Private key does not match the public certificate"));
    }
    int err_code;
    int fd = connection.getNativeSocket();
    _ssl = SSL_new(_context);
    if (!_ssl) {
        THROW_SSL_ERROR("SSL_new");
    }
    SSL_set_fd(_ssl, fd);

    int saved_flags = fcntl(fd, F_GETFL);
    fcntl(fd, F_SETFL, saved_flags & ~O_NONBLOCK);

    ERR_print_errors_fp(stderr);
    err_code = SSL_accept(_ssl);
    if (err_code < 0) {
        std::cout << "[SSL]: Error (err_code < 0)" << std::endl;
        throw(Zia::AException("OpenSSL", "failed to ssl accept error code " + std::to_string(SSL_get_error(_ssl, err_code))));
    }
}

ConnectionSSL::~ConnectionSSL()
{
    std::cout << "[SSL]: Close socket" << std::endl;
    SSL_shutdown(_ssl);
    SSL_free(_ssl);
    SSL_CTX_free(_context);
    EVP_cleanup();
}

size_t ConnectionSSL::read(size_t buf_size, char *buf)
{
    return (SSL_read(_ssl, buf, buf_size));
}

size_t ConnectionSSL::write(size_t buf_size, const char *buf)
{
    return (SSL_write(_ssl, buf, buf_size));
}

void ConnectionSSL::log(const std::string &str)
{
    (void)str;
}

const std::string &ConnectionSSL::getRemoteIP(void) const
{
    return (_connection.getRemoteIP());
}

int ConnectionSSL::getNativeSocket(void) const
{
    return (_connection.getSocket().native_handle());
}
