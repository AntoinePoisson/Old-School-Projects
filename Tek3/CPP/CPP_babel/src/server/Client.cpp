/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** Client
*/

#include "Client.hpp"

babel::Client::Client(boost::asio::io_service &io_service)
: _network(io_service), _turnOn(false)
{
    _table.clear();
}

babel::Client::~Client()
{
    _network.disconnect();
}

boost::shared_ptr<babel::Client> babel::Client::createClient(boost::asio::io_service &io_service)
{
    return (boost::shared_ptr<Client> (new Client(io_service)));
}

void babel::Client::connection(void)
{
    if (!_turnOn) {
        _network.start();
        _turnOn = !_turnOn;
    }
}

babel::Package babel::Client::receivePacket(void)
{
    babel::Package pack = _network.receiveMsg();

    return (pack);
}

void babel::Client::sendPacket(babel::Package packet)
{
    _network.sendMsg(packet);
}

void babel::Client::setTable(babel::TableUser table)
{
    _table = table;
}

babel::TableUser babel::Client::getTable(void) const
{
    return (_table);
}

void babel::Client::disconnect(void)
{
    _network.disconnect();
}

boost::asio::ip::tcp::socket &babel::Client::getSocket(void)
{
    return (_network.getSocket());
}
