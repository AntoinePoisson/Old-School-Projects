/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** Server
*/

#include "Server.hpp"

    //* Public
babel::Server::Server(std::string ip, int port)
: _ip(ip), _port(port), _accept(_io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), port))
{
    std::cout << "[Status]: Server run on " << _ip << "@" << _port << std::endl;
    acceptConnection();
    signal(SIGINT, [](int){ throw babel::HandleCtrlC(); });
}

babel::Server::~Server()
{
    for (auto element : _listClient) {
        if (element->getSocket().is_open() == true) {
            _cmd.logoutUser(babel::Package(""), element, _listClient, _db);
        }
    }
    _listClient.clear();
}



    //* Private
void babel::Server::run(void)
{
    try {
        while (_io_service.stopped() == false) {
            for (auto element = _listClient.begin(); _listClient.size() &&
                element != _listClient.end(); element++) {
                if ((*element)->getSocket().is_open() == true) {
                    _cmd.HandlerCommande((*element)->receivePacket(), (*element), _listClient, _db);
                } else {
                    std::cout << "[Erase]: client of _listClient" << std::endl;
                    _cmd.logoutUser(babel::Package(""), (*element), _listClient, _db);
                    _listClient.erase(element);
                    if (element != _listClient.begin())
                        element--;
                }
            }
            _io_service.run_one();
        }
    } catch(babel::HandleCtrlC &ctrlC) {
        ctrlC.print();
    } catch(babel::QuitServer &quit) {
        quit.print();
    }
    _io_service.stop();
}

void babel::Server::acceptConnection(void)
{
    boost::shared_ptr<babel::Client> newClient = babel::Client::createClient(_io_service);

    _accept.async_accept(newClient->getSocket(), boost::bind(&Server::addClient, this,
        newClient, boost::asio::placeholders::error));
}

void babel::Server::addClient(boost::shared_ptr<babel::Client> newClient, const boost::system::error_code& err)
{
    if (err) {
        std::cerr << "[Error]: While accept new client. (" << err.message() << ")." << std::endl;
        return;
    }
    newClient->connection();
    _listClient.push_back(newClient);
    std::cout << "[User]: New Connection" << std::endl;
    acceptConnection();
}
