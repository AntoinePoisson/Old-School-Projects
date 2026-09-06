/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** HandleBoostNetwork
*/

#include "HandleBoostNetwork.hpp"


    //* Public
babel::HandleBoostNetwork::HandleBoostNetwork(boost::asio::io_service &io_service)
: _sock(io_service), _turnOn(false)
{}

babel::HandleBoostNetwork::~HandleBoostNetwork()
{
    if (_sock.is_open() == true)
        _sock.close();
}

void babel::HandleBoostNetwork::start(void)
{
    if (!_turnOn) {
        openAsyncRead();
        openAsyncWrite();
        _turnOn = !_turnOn;
    }
}

void babel::HandleBoostNetwork::sendMsg(babel::Package pack)
{
    _sendQueue.push(pack);
    openAsyncWrite();
}

babel::Package babel::HandleBoostNetwork::receiveMsg(void)
{
    if (_sock.is_open() == false)
        return (babel::Package(""));
    return (_receiveQueue.pop());
}

void babel::HandleBoostNetwork::disconnect(void)
{
    if (_sock.is_open() == true) {
        _sock.close();
        std::cout << "[Client]: Disconnected." << std::endl;
    }
}

boost::asio::ip::tcp::socket &babel::HandleBoostNetwork::getSocket(void)
{
    return (_sock);
}



    //* Private
void babel::HandleBoostNetwork::openAsyncRead(void)
{
    if (_sock.is_open() == false) {
        std::cout << "[Warning]: Can't Read because of Socket Close." << std::endl;
        return;
    }
    _buffRead.clear();
    _buffRead.resize(sizeof(transfertData_t));
    boost::asio::async_read(_sock,
            boost::asio::buffer(_buffRead),
            boost::bind(&HandleBoostNetwork::handlerRead,
            this, boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void babel::HandleBoostNetwork::openAsyncWrite(void)
{
    if (_sock.is_open() == false || _sendQueue.size() <= 0) {
        return;
    }
    babel::Package pack = _sendQueue.pop();
    transfertData_t result = _transfer.transcriptData(pack.getOp(), pack.getParameter());
    _buffWrite.clear();
    _buffWrite.resize(sizeof(transfertData_t));
    memcpy(_buffWrite.data(), &result, sizeof(transfertData_t));
	boost::asio::async_write(_sock,
            boost::asio::buffer(_buffWrite, sizeof(transfertData_t)),
            boost::bind(&HandleBoostNetwork::handlerWrite,
            this, boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void babel::HandleBoostNetwork::handlerRead(const boost::system::error_code& err, std::size_t size)
{
    if (err) {
        if (err.value() == 2) //? End of file
            disconnect();
        else
            std::cerr << "[Error]: Can't Read Package (" << err.message() << ")." << std::endl;
        return;
    }
    transfertData_t transfert = {};

    memcpy(&transfert, _buffRead.data(), sizeof(transfertData_t));
    babel::Package packet(&transfert);
    _receiveQueue.push(packet);
    std::cout << "\n/======== Package =========\\" << std::endl;
    std::cout << "size: '" << size << "'." << std::endl;
    std::cout << "data("<< _buffRead.size() << "): '" << _buffRead.data() << "'." << std::endl;
    std::cout << "Stru: "<< transfert.opcode << " | " << transfert.username << std::endl;
    std::cout << "\\===========================/\n" << std::endl;
    openAsyncRead();
}

void babel::HandleBoostNetwork::handlerWrite(const boost::system::error_code& err, std::size_t size)
{
    if (err) {
        std::cerr << "[Error]: Can't Write Package (" << err.message() << ")." << std::endl;
        return;
    } else if (size == 0) {
        std::cerr << "[Warning]: Nothing Send." << std::endl;
        return;
    }
    std::cout << "[Info]: Packetage successfully send." << std::endl;
    openAsyncWrite();
}
