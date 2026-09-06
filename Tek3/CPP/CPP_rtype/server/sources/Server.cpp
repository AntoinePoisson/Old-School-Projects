/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Server
*/

#include <iostream>
#include "Server.hpp"
#include "singleton/ECManager.hpp"
#include "components/Physics.hpp"
#include "components/Network.hpp"
#include "Network.hpp"
#include "GameEngine.hpp"

rtype::OOP::Server::Server(const std::string &ip)
: _accept(_ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(ip), 0))
{
    std::cout << "[Start]: Server run on " << _accept.local_endpoint().address().to_string() << " " << _accept.local_endpoint().port() << std::endl;
    acceptConnection();
    getEnpoint(_accept.local_endpoint());
    signal(SIGINT, [](int){ throw rtype::OOP::HandleCtrlC("Quit Server"); });
}

rtype::OOP::Server::Server(const std::string &ip, int port)
: _accept(_ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(ip), port))
{
    std::cout << "[Start]: Server run on " << _accept.local_endpoint().address().to_string() << " " << _accept.local_endpoint().port() << std::endl;
    acceptConnection();
    getEnpoint(_accept.local_endpoint());
    signal(SIGINT, [](int){ throw rtype::OOP::HandleCtrlC("Quit Server"); });
}

rtype::OOP::Server::Server()
: _accept(_ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 0))
{
    std::cout << "[Start]: Server run on " << _accept.local_endpoint().address().to_string() << " " << _accept.local_endpoint().port() << std::endl;
    acceptConnection();
    getEnpoint(_accept.local_endpoint());
    signal(SIGINT, [](int){ throw rtype::OOP::HandleCtrlC("Quit Server"); });
}

rtype::OOP::Server::~Server()
{
    for (auto &element : _listClient) {
        if (element->getSocket().is_open() == true) {
            element->disconnect();
        }
    }
    for (auto &element : getListThread()) {
        pthread_cancel(element->native_handle());
    }
    getListThread().clear();
    _listClient.clear();
    _ioService.stop();
    std::cout << "[Close]: Server Close." << std::endl;
    std::exit(0);
}

void rtype::OOP::Server::run()
{
    try {
        while (_ioService.stopped() == false) {
            for (auto element = _listClient.begin(); _listClient.size() && element != _listClient.end(); element++) {
                if ((*element)->getSocket().is_open() == true) {
                    handleClientCommand((*element)->receivePacket(), (*element));
                    checkCreateParty(SOLO);
                } else {
                    std::cout << "[Erase]: client of _listClient" << std::endl;
                    (*element)->disconnect();
                    _listClient.erase(element);
                    if (element != _listClient.begin())
                        element--;
                }
            }
            _ioService.run_one();
        }
    } catch(rtype::OOP::HandleCtrlC &ctrlC) {
        std::cout << ctrlC.what();
    }
}


void rtype::OOP::Server::acceptConnection()
{
    boost::shared_ptr<rtype::OOP::Client> newClient = rtype::OOP::Client::createClient(_ioService);

    _accept.async_accept(newClient->getSocket(),
        boost::bind(&Server::handlerAddClient,
        this,
        newClient,
        boost::asio::placeholders::error));
}


void rtype::OOP::Server::handlerAddClient(boost::shared_ptr<rtype::OOP::Client> &connect, const boost::system::error_code& err)
{
    if (err) {
        std::cerr << "[Error]: While accept new client. (" << err.message() << ")." << std::endl;
        return;
    }
    connect->connection();
    _listClient.push_back(connect);
    std::cout << "[User]: New Connection" << std::endl;
    acceptConnection();
}

void rtype::OOP::Server::handleClientCommand(std::string message, boost::shared_ptr<rtype::OOP::Client> &client)
{
    if (!message.size() || client->getStatus() == INGAME)
        return;
    rtype::network::CodeActionMssg transfert = {};
    std::memcpy(&transfert, message.data(), sizeof(rtype::network::CodeActionMssg));
    if (transfert.type != rtype::network::MessageTypeClient::CODE_ACTION)
        return;
    std::cout << "[Reveice]: '" << transfert.nb_player << "'" << std::endl;
    if (transfert.action == rtype::network::CodeAction::PLAY) {
        if (transfert.nb_player == 1)
            client->setStatus(SOLO);
        if (transfert.nb_player == 2)
            client->setStatus(DUO);
        if (transfert.nb_player == 3)
            client->setStatus(TRIO);
        if (transfert.nb_player == 4)
            client->setStatus(QUAD);
    }
    if (transfert.action == rtype::network::CodeAction::QUIT) {
        client->setStatus(QUIT);
    }
    if (client->getStatus() == QUIT)
        client->disconnect();
}

void rtype::OOP::Server::checkCreateParty(int nbr)
{
    std::vector<boost::shared_ptr<rtype::OOP::Client>> client_match;

    if (nbr > rtype::OOP::QUAD)
        return;
    for (auto element = _listClient.begin(); _listClient.size() && element != _listClient.end(); element++) {
        if ((*element)->getStatus() == nbr)
            client_match.push_back(*element);
        if (client_match.size() == nbr - 10) {
            for (auto el = client_match.begin(); client_match.size() && el != client_match.end(); el++)
                (*el)->setStatus(rtype::OOP::INGAME);
                if (nbr >= SOLO && nbr <= QUAD) {
                    getListThread().push_back(new boost::thread(&runnerParty, client_match));
                }
            checkCreateParty(nbr);
            break;
        }
    }
    checkCreateParty(nbr + 1);
}

rtype::entity::Entity rtype::OOP::Server::getPlayerByEndpoint(const rtype::component::OpponentNetworkInfo& endpoint)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::entity::Entity returnEntity;

    for (auto &a : handler.getComponent<rtype::component::ListClientNetwork>(handler._cMan.getComponentFromType<rtype::component::ItsServer>().first)._list) {
        if (a.second._endpoint.address().to_string() == endpoint._endpoint.address().to_string() && a.second._endpoint.port() == endpoint._endpoint.port()) {
            returnEntity = a.first;
            return returnEntity;
        }
    }
    return returnEntity;
}

void rtype::OOP::Server::runnerParty(std::vector<boost::shared_ptr<rtype::OOP::Client>> &squad)
{
    std::string msg = (squad.size() == 1 ? "SOLO" : (squad.size() == 2 ? "DUO" : (squad.size() == 3 ? "TRIO" : (squad.size() == 4 ? "QUAD" : ("NONE")))));

    std::cout << "[Game]: Start with Team of " << msg << std::endl;
    // Create Server Entity
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::entity::Entity serverEntity = handler.createEntity(rtype::idServer);
    rtype::component::ItsServer servComp;
    handler.addComponent(serverEntity, servComp);

    std::cout << "Start UDP " << std::endl;
    // Start Server UDP
    rtype::system::StartNetworkServer().update(serverEntity);


    std::cout << "SEND UDP" << std::endl;
    // sendEndpoint() to 4 clients
    std::vector<char> sendEndpoint(sizeof(struct rtype::network::EndpointMssg));
    auto networkInfo = handler.getComponent<rtype::component::MyNetworkInfo>(serverEntity);
    struct rtype::network::EndpointMssg edp = {};
    edp.port = networkInfo._endpoint.port();
    std::string stringaddr = networkInfo._endpoint.address().to_string();

    memcpy(&edp.addr, stringaddr.data(), stringaddr.size());
    memcpy(sendEndpoint.data(), &edp, sizeof(rtype::network::EndpointMssg));
    for (auto el = squad.begin(); squad.size() && el != squad.end(); el++)
        (*el)->sendPacket(std::string(sendEndpoint.begin(), sendEndpoint.end()));

    // std::cerr << "edp.addr = " << edp.addr << std::endl;
    std::cout << "STORE UDP" << std::endl;
    // Store les Endpoint des Clients
    std::string receiveTmp;
    while (handler.getComponent<rtype::component::ListClientNetwork>(serverEntity)._list.size() != squad.size())
        handler.getComponent<rtype::component::ListClientNetwork>(serverEntity)._list.push_back(std::make_pair<std::string, rtype::component::OpponentNetworkInfo>("", boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 0}));
    for (int count = 0; count != squad.size();) {
        for (int i = 0; i != squad.size(); i++) {
            receiveTmp = squad[i]->receivePacket();
            if (receiveTmp.size() == 0 || receiveTmp.size() < sizeof(struct rtype::network::EndpointMssg))
                continue;
            struct rtype::network::EndpointMssg edp;
            struct rtype::component::OpponentNetworkInfo serverInfo(boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 0}); // C'est juste pour init la structure
            memcpy(&edp, receiveTmp.data(), sizeof(rtype::network::EndpointMssg));

            serverInfo._endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(edp.addr), edp.port);
            handler.getComponent<rtype::component::ListClientNetwork>(serverEntity)._list[i].second = serverInfo;
            std::cout << "One More UDP:" << serverInfo._endpoint.address().to_string() << "@" << serverInfo._endpoint.port() << std::endl;
            count++;
        }
    }
    std::cout << "List UDP: " << handler.getComponent<rtype::component::ListClientNetwork>(serverEntity)._list.size() << std::endl;

    usleep(1000);
    boost::thread *boostRun = new boost::thread([&]{ handler.getComponent<rtype::component::IOService>(serverEntity)._ioService.run(); });
    getListThread().push_back(boostRun);

    // loopSystem()
    rtype::GameEngine game(serverEntity, squad);
    try {
        game.run();
    } catch(...) {
    }

    for (auto el = getListThread().begin(); el != getListThread().end(); el++) {
        if ((*el)->get_id() == boostRun->get_id()) {
            getListThread().erase(el);
            break;
        }
    }
    rtype::system::CloseNetworkServer().update(serverEntity);
    pthread_cancel(boostRun->native_handle());
    handler._eMan._tempEntities.clear();
    handler._eMan._entities.clear();
    handler._eMan._idEntities.clear();
    handler._cMan._components.clear();
    handler._cMan._tempComponent.clear();
    //! Est ce grave si ComponentManager est en commun dans tout les threads ? ou il en crée pour chaque ?
    //      ? check if (squad->getStatus() == QUIT) ?
}
