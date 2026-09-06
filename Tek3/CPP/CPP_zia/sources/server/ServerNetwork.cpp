/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** ServerNetwork
*/

#include <iostream>
#include <boost/bind.hpp>

#include "../Zia.hpp"
#include "../core/Core.hpp"
#include "ServerNetwork.hpp"
#include "../api/io/Connection.hpp"

//! Public:
Zia::ServerNetwork::ServerNetwork(const std::string ip, unsigned int port, std::shared_ptr<Zia::ILogger> log, const bool &secure)
: _port(port), _accept(_ioContext, boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(ip), port)), _signals{_ioContext, SIGINT }, _secure(secure)
{
    _signals.async_wait([&](boost::system::error_code const&, int){_ioContext.stop();});
    if (log) {
        _logger = log;
    } else {
        _logger = std::make_shared<Zia::Logger>("./resources/log/Server_" + ip + "_" + std::to_string(port) +  ".log");
    }
}

Zia::ServerNetwork::~ServerNetwork()
{
    _ioContext.stop();
    _accept.close();
    _logger->log("[Close]: Server Close.");
}

std::shared_ptr<boost::asio::io_context::work> Zia::ServerNetwork::run()
{
    _logger->log("[Start]: Server run on " + _accept.local_endpoint().address().to_string() + " " + std::to_string(_accept.local_endpoint().port()));
    acceptConnection();
    boost::thread([&]{_ioContext.run();});
    return std::make_shared<boost::asio::io_context::work>(_ioContext);
}

std::shared_ptr<Zia::IConnection> Zia::ServerNetwork::receiveNewConnection()
{
    if (_listConnected.empty() || Zia::Core::getNbrCurrentClient(-1) + 1 > PROTECTION_DDOS)
        return nullptr;
    std::shared_ptr<Zia::IConnection> result = _listConnected.front();
    _listConnected.erase(_listConnected.begin());
    return result;
}


//! Private:
void Zia::ServerNetwork::acceptConnection()
{
    std::shared_ptr<Zia::Connection> newConnection = Zia::Connection::createConnection(_ioContext, _logger, _secure);

    _accept.async_accept(newConnection->getSocket(),
        boost::bind(&ServerNetwork::handlerAddConnection,
        this,
        std::dynamic_pointer_cast<Zia::IConnection>(newConnection),
        boost::asio::placeholders::error));
}

void Zia::ServerNetwork::handlerAddConnection(const std::shared_ptr<Zia::IConnection> newConnect, const boost::system::error_code& err)
{
    if (err) {
        _logger->log("[Error]: During acception of a new client: " + err.message() + ".");
        return;
    }
    if (!(dynamic_cast<Zia::Connection *> (newConnect.get()))) {
        return acceptConnection();
    }
    dynamic_cast<Zia::Connection *> (newConnect.get())->connecting();
    _mutex.lock();
    _listConnected.push_back(newConnect);
    _mutex.unlock();
    _logger->log("[Client]: New Connection");
    std::cout << " <- New Client" << std::endl;
    acceptConnection();
}