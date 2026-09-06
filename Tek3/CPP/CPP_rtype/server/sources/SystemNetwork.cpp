/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemNetwork
*/

#include "systems/Network.hpp"
#include "systems/Exception.hpp"
#include "singleton/ECManager.hpp"
#include "components/TempComponents.hpp"
#include "Mediator.hpp"
#include "systems/NetworkServer.hpp"


void rtype::system::NetworkRead::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    std::queue<std::pair<std::string, rtype::component::OpponentNetworkInfo>> &tmp = handler.getComponent<rtype::component::QueueMessageReceive>(id)._queue;
    std::pair<std::string, rtype::component::OpponentNetworkInfo> res = std::make_pair("", boost::asio::ip::udp::endpoint{boost::asio::ip::address::from_string("1.2.3.4"), 0000});
    rtype::Mediator med = rtype::Mediator::get();

    if (tmp.size() <= 0) {
        return;
    }
    rtype::system::InterpretNetworkServer().update(id);
    // rtype::component::TempInterpret a(res);
    // handler.addTempComponent(id, a);
    // handler._eMan._tempEntities[id] = TempSignature(idInterpret);
    // med.mediate(id);
}

void rtype::system::NetworkRead::openAsyncRead(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    if (handler.getComponent<rtype::component::Socket>(id)._socket.is_open() == false) {
        std::cout << "[Warning]: Can't Read because of Socket Close." << std::endl;
        throw rtype::system::Exception("Can't Read because of Socket Close.");
    }
    std::shared_ptr<std::string> _buff(new std::string());
    _buff->resize(50000);
    std::shared_ptr<boost::asio::ip::udp::endpoint> _endpoint(new boost::asio::ip::udp::endpoint);
    handler.getComponent<rtype::component::Socket>(id)._socket.async_receive_from(
        boost::asio::buffer(*_buff),
        *_endpoint,
        boost::bind(&NetworkRead::handlerRead,
        this, boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred, id, _endpoint, _buff));
}

void rtype::system::NetworkRead::handlerRead(const boost::system::error_code& err, std::size_t size, Entity _idEntity, std::shared_ptr<boost::asio::ip::udp::endpoint> _endpoint, std::shared_ptr<std::string> _buff)
{
    if (err) {
        std::cerr << "[Error]: Can't Read Package (" << err.message() << ")." << std::endl;
        return;
    }
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    std::cout << "\n/======== Package =========\\" << std::endl;
    std::cout << " - Size transfere byte: '" << size << "'." << std::endl;
    std::cout << " - Entity id: " << _idEntity << std::endl;
    std::cout << " - Data("<< _buff->size() << "): '" << handler.getComponent<rtype::component::QueueMessageReceive>(_idEntity)._queue.size() << "'." << std::endl;
    std::cout << "\\===========================/\n" << std::endl;
    if (size == 0) {
        return openAsyncRead(_idEntity);
    }
    _buff->resize(size);
    handler.getComponent<rtype::component::QueueMessageReceive>(_idEntity)._queue.push(std::make_pair(std::string(*_buff), *_endpoint));
    openAsyncRead(_idEntity);
}

void rtype::system::NetworkWrite::useless(const boost::system::error_code& err, std::size_t size)
{}

void rtype::system::NetworkWrite::send(const Entity &id, std::pair<std::string, rtype::component::OpponentNetworkInfo> msg)
{
    rtype::singleton::ECManager::get().getComponent<rtype::component::Socket>(id)._socket.async_send_to(
        boost::asio::buffer(msg.first),
        msg.second._endpoint,
        boost::bind(&NetworkWrite::useless,
        this, boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}


void rtype::system::NetworkWrite::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    std::queue<std::pair<std::string, rtype::component::OpponentNetworkInfo>> &tmp = handler.getComponent<rtype::component::QueueMessageSend>(id)._queue;
    std::pair<std::string, rtype::component::OpponentNetworkInfo> res = std::make_pair("", boost::asio::ip::udp::endpoint{boost::asio::ip::address::from_string("1.2.3.4"), 0000});

    if (handler.getComponent<rtype::component::Socket>(id)._socket.is_open() == false ||
        tmp.size() <= 0) {
        return;
    }
    res = tmp.front();
    tmp.pop();
    handler.getComponent<rtype::component::Socket>(id)._socket.async_send_to(
        boost::asio::buffer(res.first),
        res.second._endpoint,
        boost::bind(&NetworkWrite::handlerWrite,
        this, boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred, id));
}

void rtype::system::NetworkWrite::handlerWrite(const boost::system::error_code& err, std::size_t size, Entity _idEntity)
{
    if (err) {
        std::cerr << "[Error]: Can't Write Package (" << err.message() << ")." << std::endl;
        return;
    } else if (size == 0) {
        std::cerr << "[Warning]: Nothing Send." << std::endl;
        return;
    }
    std::cout << "[Info]: Packetage successfully send." << std::endl;
    update(_idEntity);
}

void rtype::system::NetworkAddSomeWrite::add(const Entity &id, std::string &message, rtype::component::OpponentNetworkInfo &dest)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    handler.getComponent<rtype::component::QueueMessageSend>(id)._queue.push(std::make_pair(message, dest));
}
