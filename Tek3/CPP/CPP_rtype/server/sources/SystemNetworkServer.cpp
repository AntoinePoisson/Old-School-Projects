/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemsServer
*/

#include <memory>
#include "singleton/ECManager.hpp"
#include "systems/NetworkServer.hpp"
#include "systems/ShootServer.hpp"
#include "systems/MovementPlayerServer.hpp"
#include "components/Network.hpp"
#include "components/MethodeMob.hpp"
#include "Mediator.hpp"
#include "Network.hpp"

void rtype::system::StartNetworkServer::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    std::shared_ptr<rtype::component::IOService> io(new rtype::component::IOService);
    std::shared_ptr<rtype::component::Socket> sock(new rtype::component::Socket(io->_ioService, boost::asio::ip::udp::endpoint{boost::asio::ip::make_address(rtype::OOP::Server::getEnpoint(boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address("127.0.0.1"), 4242)).address().to_string()), 0}));
    rtype::component::ListClientNetwork list;
    rtype::component::QueueMessageReceive queueReceive;
    rtype::component::NbrMob mob;
    rtype::component::ListMethodeMob listMethode;
    rtype::component::QueueMessageSend queueSend;
    rtype::component::TempRead a;
    rtype::Mediator med = rtype::Mediator::get();
    std::shared_ptr<rtype::component::MyNetworkInfo> myNetworkInfo(new rtype::component::MyNetworkInfo(sock->_socket.local_endpoint()));

    std::cout << "[Start]: Server is running on: " << myNetworkInfo->_endpoint.address().to_string() << "@" << myNetworkInfo->_endpoint.port() << std::endl;
    handler.addComponent(id, io);
    handler.addComponent(id, sock);
    handler.addComponent(id, listMethode);
    handler.addComponent(id, myNetworkInfo);
    handler.addComponent(id, list);
    handler.addComponent(id, queueReceive);
    handler.addComponent(id, queueSend);
    handler.addComponent(id, mob);

    handler.addTempComponent(id, a);
    handler._eMan._tempEntities[id] = TempSignature(idAsync);
    med.mediate(id);
}

void rtype::system::CloseNetworkServer::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    handler.getComponent<rtype::component::IOService>(id)._ioService.stop();
    handler.getComponent<rtype::component::Socket>(id)._socket.close();
    handler.removeComponent<rtype::component::IOService>(id);
    handler.removeComponent<rtype::component::Socket>(id);
    handler.removeComponent<rtype::component::MyNetworkInfo>(id);
    handler.removeComponent<rtype::component::ListClientNetwork>(id);
    handler.removeComponent<rtype::component::QueueMessageReceive>(id);
    handler.removeComponent<rtype::component::QueueMessageSend>(id);
    std::cout << "[Stop]: UDP Server Network Close." << std::endl;

}

void rtype::system::InterpretNetworkServer::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    static time_t timestampLastRequest = std::time(nullptr);
    rtype::entity::Entity serverId = handler._cMan.getComponentFromType<rtype::component::ItsServer>().first;
    rtype::network::CodeActionMssg structMessage = {0};
    for (std::string msg; handler.getComponent<rtype::component::QueueMessageReceive>(id)._queue.size(); msg.clear()) {
        msg = handler.getComponent<rtype::component::QueueMessageReceive>(id)._queue.front().first;
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << handler.getComponent<rtype::component::QueueMessageReceive>(id)._queue.size()  << std::endl;
        std::cout << std::string(msg) << "  ||||  " << handler.getComponent<rtype::component::QueueMessageReceive>(id)._queue.front().second._endpoint.address().to_string() << "@" << handler.getComponent<rtype::component::QueueMessageReceive>(id)._queue.front().second._endpoint.port() << std::endl;
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        if (msg.size() != sizeof(rtype::network::CodeActionMssg)) {
            handler.getComponent<rtype::component::QueueMessageReceive>(id)._queue.pop();
            continue;
        }
        std::memcpy(&structMessage, msg.data(), sizeof(rtype::network::CodeActionMssg));
        if (timestampLastRequest - 10 > structMessage.timestamp) {
            handler.getComponent<rtype::component::QueueMessageReceive>(id)._queue.pop();
            continue;
        }
        timestampLastRequest = structMessage.timestamp;
        rtype::entity::Entity idPlayer = rtype::OOP::Server::getPlayerByEndpoint(handler.getComponent<rtype::component::QueueMessageReceive>(id)._queue.front().second);
        switch (structMessage.action) { //+ Call Mediator
            case rtype::network::RIGHT: rtype::system::MovementPlayerServer().action(idPlayer, rtype::network::RIGHT);
                break;
            case rtype::network::LEFT: rtype::system::MovementPlayerServer().action(idPlayer, rtype::network::LEFT);
                break;
            case rtype::network::UP: rtype::system::MovementPlayerServer().action(idPlayer, rtype::network::UP);
                break;
            case rtype::network::DOWN: rtype::system::MovementPlayerServer().action(idPlayer, rtype::network::DOWN);
                break;
            case rtype::network::SHOOT: rtype::system::ShootBullet().update(idPlayer);
                break;
            case rtype::network::QUIT:
                handler.getComponent<rtype::component::Life>(idPlayer)._life = 0;
                break;
        }
        handler.getComponent<rtype::component::QueueMessageReceive>(id)._queue.pop();
    }
}

void rtype::system::SendEntities::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    struct rtype::network::DisplayRefreshMssg structData = {0};
    struct rtype::network::DeleteComponentMssg del = {0};
    std::vector<char> msg;

        // Player
    for (auto &entity : handler._cMan.getComponentsFromType<rtype::component::ItsPlayer>()) {
        std::strcpy(structData.uuiid, entity.first.data());
        structData.type = rtype::network::MessageTypeServer::DISPLAY_REFRESH;
        structData.timestamp = std::time(nullptr);
        structData.mask_bitset = playerMaskBitset(entity.first, handler);
        std::memcpy(structData.message, playerMessageComponent(entity.first, handler).data(), 2000);
        msg.clear();
        msg.resize(sizeof(struct rtype::network::DisplayRefreshMssg));
        memcpy(msg.data(), &structData, sizeof(struct rtype::network::DisplayRefreshMssg));

        for (auto &client : handler.getComponent<rtype::component::ListClientNetwork>(id)._list) {
            rtype::system::NetworkWrite().send(id, std::make_pair(std::string(msg.begin(), msg.end()), client.second));
        }
        rtype::system::NetworkWrite().update(id);
    }

        // Mob
    for (auto &entity : handler._cMan.getComponentsFromType<rtype::component::ItsMob>()) {
        std::strcpy(structData.uuiid, entity.first.data());
        structData.type = rtype::network::MessageTypeServer::DISPLAY_REFRESH;
        structData.timestamp = std::time(nullptr);
        structData.mask_bitset = mobMaskBitset(entity.first, handler);
        std::memcpy(structData.message, mobMessageComponent(entity.first, handler).data(), 2000);
        msg.clear();
        msg.resize(sizeof(struct rtype::network::DisplayRefreshMssg));
        memcpy(msg.data(), &structData, sizeof(struct rtype::network::DisplayRefreshMssg));
        for (auto &client : handler.getComponent<rtype::component::ListClientNetwork>(id)._list) {
            rtype::system::NetworkWrite().send(id, std::make_pair(std::string(msg.begin(), msg.end()), client.second));
        }
        rtype::system::NetworkWrite().update(id);
    }

    for (auto &entity : handler._cMan.getComponentsFromType<rtype::component::ItsBullet>()) {
        if (handler.getComponent<rtype::component::DeletOrPrint>(entity.first).print == true) {
            std::strcpy(structData.uuiid, entity.first.data());
            structData.type = rtype::network::MessageTypeServer::DISPLAY_REFRESH;
            structData.timestamp = std::time(nullptr);
            structData.mask_bitset = bulletMaskBitset(entity.first, handler);
            std::memcpy(structData.message, bulletMessageComponent(entity.first, handler).data(), 2000);
            msg.clear();
            msg.resize(sizeof(struct rtype::network::DisplayRefreshMssg));
            memcpy(msg.data(), &structData, sizeof(struct rtype::network::DisplayRefreshMssg));
            for (auto &client : handler.getComponent<rtype::component::ListClientNetwork>(id)._list) {
                rtype::system::NetworkWrite().send(id, std::make_pair(std::string(msg.begin(), msg.end()), client.second));
            }
            rtype::system::NetworkWrite().update(id);
            handler.getComponent<rtype::component::DeletOrPrint>(entity.first).print = false;
        }
        if (handler.getComponent<rtype::component::DeletOrPrint>(entity.first).delet == true) {
            std::strcpy(del.uuid, entity.first.data());
            del.type = rtype::network::MessageTypeServer::DELETE_CPT;
            del.mask_bitset = bulletMaskBitset(entity.first, handler);
            msg.clear();
            msg.resize(sizeof(struct rtype::network::DeleteComponentMssg));
            memcpy(msg.data(), &del, sizeof(struct rtype::network::DeleteComponentMssg));
            for (auto &client : handler.getComponent<rtype::component::ListClientNetwork>(id)._list) {
                rtype::system::NetworkWrite().send(id, std::make_pair(std::string(msg.begin(), msg.end()), client.second));
            }
            rtype::system::NetworkWrite().update(id);
            handler.deleteEntity(entity.first);
        }
    }
}

unsigned long rtype::system::SendEntities::bulletMaskBitset(const Entity &id, rtype::entity::ComponentManager &handler)
{
    unsigned long res = 0;

    res += rtype::idBitset::idPosition;
    res += rtype::idBitset::idDestination;
    res += rtype::idBitset::idStartingTime;
    res += rtype::idBitset::idSpeed;
    res += rtype::idBitset::idSurface;
    res += rtype::idBitset::idStartCriteria;
    res += rtype::idBitset::idType;
    return (res);
}

const std::vector<char> rtype::system::SendEntities::bulletMessageComponent(const Entity &id, rtype::entity::ComponentManager &handler)
{
    std::vector<char> res(2000);
    int len = 0;

    std::memcpy(res.data(), &handler.getComponent<rtype::component::Position>(id), sizeof(handler.getComponent<rtype::component::Position>(id)));
    len += sizeof(handler.getComponent<rtype::component::Position>(id));

    std::memcpy(res.data() + len, &handler.getComponent<rtype::component::Destination>(id), sizeof(handler.getComponent<rtype::component::Destination>(id)));
    len += sizeof(handler.getComponent<rtype::component::Destination>(id));

    std::memcpy(res.data() + len, &handler.getComponent<rtype::component::StartingTime>(id), sizeof(handler.getComponent<rtype::component::StartingTime>(id)));
    len += sizeof(handler.getComponent<rtype::component::StartingTime>(id));

    std::memcpy(res.data() + len, &handler.getComponent<rtype::component::Speed>(id), sizeof(handler.getComponent<rtype::component::Speed>(id)));
    len += sizeof(handler.getComponent<rtype::component::Speed>(id));

    std::memcpy(res.data() + len, &handler.getComponent<rtype::component::Surface>(id), sizeof(handler.getComponent<rtype::component::Surface>(id)));
    len += sizeof(handler.getComponent<rtype::component::Surface>(id));

    std::memcpy(res.data() + len, &handler.getComponent<rtype::component::StartCriteria>(id), sizeof(handler.getComponent<rtype::component::StartCriteria>(id)));
    len += sizeof(handler.getComponent<rtype::component::StartCriteria>(id));

    std::memcpy(res.data() + len, &handler.getComponent<rtype::component::Type>(id), sizeof(handler.getComponent<rtype::component::Type>(id)));
    return (res);
}

unsigned long rtype::system::SendEntities::mobMaskBitset(const Entity &id, rtype::entity::ComponentManager &handler)
{
    unsigned long res = 0;

    res += rtype::idBitset::idPosition;
    res += rtype::idBitset::idType;
    res += rtype::idBitset::idLife;
    return (res);
}

const std::vector<char> rtype::system::SendEntities::mobMessageComponent(const Entity &id, rtype::entity::ComponentManager &handler)
{
    std::vector<char> res(2000);
    int len = 0;

    std::memcpy(res.data(), &handler.getComponent<rtype::component::Position>(id), sizeof(handler.getComponent<rtype::component::Position>(id)));
    len += sizeof(handler.getComponent<rtype::component::Position>(id));

    std::memcpy(res.data() + len, &handler.getComponent<rtype::component::Life>(id), sizeof(handler.getComponent<rtype::component::Life>(id)));
    len += sizeof(handler.getComponent<rtype::component::Life>(id));

    std::memcpy(res.data() + len, &handler.getComponent<rtype::component::Type>(id), sizeof(handler.getComponent<rtype::component::Type>(id)));
    return (res);
}

unsigned long rtype::system::SendEntities::playerMaskBitset(const Entity &id, rtype::entity::ComponentManager &handler)
{
    unsigned long res = 0;

    res += rtype::idBitset::idPosition;
    res += rtype::idBitset::idLife;
    res += rtype::idBitset::idType;
    return (res);
}

const std::vector<char> rtype::system::SendEntities::playerMessageComponent(const Entity &id, rtype::entity::ComponentManager &handler)
{
    std::vector<char> res(2000);
    int len = 0;


    std::memcpy(res.data(), &handler.getComponent<rtype::component::Position>(id), sizeof(handler.getComponent<rtype::component::Position>(id)));
    len += sizeof(handler.getComponent<rtype::component::Position>(id));

    std::memcpy(res.data() + len, &handler.getComponent<rtype::component::Life>(id), sizeof(handler.getComponent<rtype::component::Life>(id)));
    len += sizeof(handler.getComponent<rtype::component::Life>(id));

    std::memcpy(res.data() + len, &handler.getComponent<rtype::component::Type>(id), sizeof(handler.getComponent<rtype::component::Type>(id)));

    // std::cerr << "TYPEEEEEEEEEEEEE = " << handler.getComponent<rtype::component::Type>(id)._type << std::endl;
    rtype::component::Position pos(0, 0);
    std::memcpy(&pos, res.data(), sizeof(handler.getComponent<rtype::component::Position>(id)));
    // std::cerr << "playerMessageComponent snd mmcpy" << std::endl;
    // std::cerr << "POS X : " << pos._x << std::endl;
    // std::cerr << "POS Y : " << pos._y << std::endl;
    return (res);
}
