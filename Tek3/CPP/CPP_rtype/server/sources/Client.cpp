/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Client
*/

#include "Server.hpp"

rtype::OOP::Client::Client(boost::asio::io_service &io_service)
: _turnOn(false), _sock(io_service), _status(WAIT)
{}

rtype::OOP::Client::~Client()
{
    if (_sock.is_open() == true) {
        _sock.close();
    }
}

void rtype::OOP::Client::connection(void)
{
    if (!_turnOn) {
        openAsyncRead();
        openAsyncWrite();
        _turnOn = !_turnOn;
    }
}

void rtype::OOP::Client::disconnect(void)
{
    if (_sock.is_open() == true) {
        _sock.close();
        _buffRead.clear();
        _buffWrite.clear();
        _status = rtype::OOP::stateClient_e::QUIT;
        std::cout << "[Client]: Disconnected." << std::endl;
    }
}

std::string rtype::OOP::Client::receivePacket(void)
{
    std::string rep;

    if (_sock.is_open() == false || _receiveQ.size() == 0) {
        return (rep);
    }
    rep = _receiveQ.front();
    _receiveQ.pop();
    return (rep);
}

void rtype::OOP::Client::sendPacket(std::string packet)
{
    _sendQ.push(packet);
    openAsyncWrite();
}

int rtype::OOP::Client::getStatus(void) const
{
    return (_status);
}

void rtype::OOP::Client::setStatus(stateClient_e status)
{
    _status = status;
}



void rtype::OOP::Client::openAsyncRead(void)
{
    if (_sock.is_open() == false) {
        std::cout << "[Warning]: Can't Read because of Socket Close." << std::endl;
        return;
    }
    std::shared_ptr<std::string> _buff(new std::string());
    _buff->resize(50000);
    _buffRead.clear();
    _buffRead.resize(1024);
    _sock.async_receive(boost::asio::buffer(*_buff),
        boost::bind(&Client::handlerRead,
        this, boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred, _buff));
}

void rtype::OOP::Client::handlerRead(const boost::system::error_code& err, std::size_t size, std::shared_ptr<std::string> _buff)
{
    if (err) {
        if (err.value() == 2) //? End of file
            disconnect();
        else
            std::cerr << "[Error]: Can't Read Package (" << err.message() << ")." << std::endl;
        return;
    }
    (*_buff).resize(size);
    int sizee = _receiveQ.size();
    while (_receiveQ.size() == sizee) {
        _receiveQ.push(*_buff);
    }
    std::cout << "\n/======== TCP =========\\" << std::endl;
    std::cout << "size: '" << size << "'." << std::endl;
    std::cout << "data("<< (*_buff).size() << "): '" << (*_buff).data() << "'." << std::endl;
    std::cout << "\\=======================/\n" << std::endl;
    _buffRead.clear();
    openAsyncRead();
}

void rtype::OOP::Client::openAsyncWrite(void)
{
    if (_sock.is_open() == false || _sendQ.size() <= 0) {
        return;
    }
    _buffWrite.clear();
    _buffWrite = _sendQ.front();
    _sendQ.pop();

    // rtype::system::codeAction_t transfert = {};
    // transfert.action = 2;
    // transfert.nb_player

	boost::asio::async_write(_sock,
            boost::asio::buffer(_buffWrite),
            boost::bind(&Client::handlerWrite,
            this, boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void rtype::OOP::Client::handlerWrite(const boost::system::error_code& error, std::size_t size)
{
    if (error) {
        std::cerr << "[Error]: Can't Write Package (" << error.message() << ")." << std::endl;
        return;
    } else if (size == 0) {
        std::cerr << "[Warning]: Nothing Send." << std::endl;
        return;
    }
    std::cout << "[Info]: Packetage successfully send." << std::endl;
    openAsyncWrite();
}
