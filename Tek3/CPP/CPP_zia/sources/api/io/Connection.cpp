/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Connection
*/

#include <iostream>
#include <boost/bind.hpp>

#include "Connection.hpp"
#include "../../Zia.hpp"

//! Public:
Zia::Connection::Connection(boost::asio::io_context &_ioContext, std::shared_ptr<Zia::ILogger> log, bool secure)
: _status(Zia::ConnectionState_e::Not_Connection), _socket(_ioContext), _requestType(Zia::TypeRequest_e::Http)
{
    if (secure == true) {
        _requestType = Zia::TypeRequest_e::Https;
    }
    if (log) {
        _logger = log;
    } else {
        _logger = std::make_shared<Zia::Logger>("./resources/log/Client_" + std::to_string(std::time(nullptr)) + ".log");
    }
    _ipClient = "0.0.0.0";
    _nativeSocket = static_cast<int>(_socket.native_handle());
}

Zia::Connection::~Connection()
{
    if (_socket.is_open() == true) {
        _socket.close();
        _logger->log("[Client]: Disconnected.");
        std::cout << " -> Disconnected Client" << std::endl;
    }
}

std::shared_ptr<Zia::Connection> Zia::Connection::createConnection(boost::asio::io_context &_ioContext, std::shared_ptr<Zia::ILogger> log, bool secure) noexcept
{
    return std::make_shared<Connection>(_ioContext, log, secure);
}

boost::asio::ip::tcp::socket &Zia::Connection::getSocket() noexcept
{
    return _socket;
}

const boost::asio::ip::tcp::socket &Zia::Connection::getSocket() const noexcept
{
    return _socket;
}

const Zia::TypeRequest_e &Zia::Connection::getHttpType() const
{
    return _requestType;
}


const std::shared_ptr<Zia::ILogger> &Zia::Connection::getLogger() const noexcept
{
    return _logger;
}

int Zia::Connection::getStatus() const noexcept
{
    return _status;
}

void Zia::Connection::connecting()
{
    if (_status == Zia::ConnectionState_e::Not_Connection) {
        _socket.non_blocking(true);
        _status = Zia::ConnectionState_e::Connect;
        try {
            _ipClient = std::string(_socket.remote_endpoint().address().to_string());
        } catch(...) {}
    }
}

void Zia::Connection::disconnecting()
{
    if (_socket.is_open() == true && _status == Zia::ConnectionState_e::Connect) {
        _socket.close();
        _status = Zia::ConnectionState_e::Disconnected;
        _logger->log("[Client]: Disconnected.");
        std::cout << " -> Disconnected Client" << std::endl;
    }
}

void Zia::Connection::log(const std::string &str)
{
    _logger->log(str);
}

size_t Zia::Connection::read(size_t buf_size, char *buf)
{
    if (_socket.is_open() == false) {
        _logger->log("[Warning]: Can't Read because of Socket Close.");
        buf = nullptr;
        return 0;
    }
    boost::system::error_code error;
    buf_size = boost::asio::read(_socket, boost::asio::buffer(buf, buf_size), error);
    // if (error == boost::asio::error::eof) {
    //     disconnecting();
    //     return 0;
    // }
    return buf_size;
}

size_t Zia::Connection::write(size_t buf_size, const char *buf)
{
    if (_socket.is_open() == false || buf == nullptr) {
        return 0;
    }
    std::vector<char> buffer;
    buffer.resize(buf_size);
    for (size_t i = 0; i < buf_size; i++) {
        buffer[i] = buf[i];
    }
	size_t res = boost::asio::write(_socket, boost::asio::buffer(buffer, buf_size));
    if (buf_size == res) {
        _logger->log("[Info]: Package successfully send.");
    } else {
        _logger->log("[Info]: Drop of Package (" + std::to_string(buf_size - res) + ").");
    }
    std::cout << "Send Response" << std::endl;
    return res;
}

const std::string &Zia::Connection::getRemoteIP(void) const
{
    return _ipClient;
}

int Zia::Connection::getNativeSocket(void) const
{
    return _nativeSocket;
}

    //! Private:
void Zia::Connection::handlerWrite(const boost::system::error_code& error, std::size_t size)
{
    if (error) {
        _logger->log("[Error]: Can't Write Package (" + error.message() + ").");
        return;
    } else if (size == 0) {
        _logger->log("[Warning]: Nothing Send (size = 0).");
        return;
    }
    _logger->log("[Info]: Packetage successfully send.");
}
