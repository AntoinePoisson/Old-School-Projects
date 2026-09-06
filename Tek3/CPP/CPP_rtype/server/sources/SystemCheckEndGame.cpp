/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemLifeServer
*/

#include "systems/CheckEndGame.hpp"
#include "Network.hpp"
#include "singleton/ECManager.hpp"
#include "systems/NetworkServer.hpp"

void rtype::system::CheckEndGame::run(const Entity &id, std::vector<boost::shared_ptr<rtype::OOP::Client>> &squad)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    bool finishGame = false;

        // No Player
    if (rtype::singleton::ECManager::get().getComponent<rtype::component::ListClientNetwork>(id)._list.size() == 0) {
        rtype::network::EndGameMssg StructData = {0};
        StructData.type = rtype::network::MessageTypeServer::ENDGAME;
        StructData.has_won = false;
        std::vector<char> msg(sizeof(struct rtype::network::EndGameMssg));
        memcpy(msg.data(), &StructData, sizeof(struct rtype::network::EndGameMssg));
        for (auto &client : handler.getComponent<rtype::component::ListClientNetwork>(id)._list) {
            rtype::system::NetworkWrite().send(id, std::make_pair(std::string(msg.begin(), msg.end()), client.second));
        }
        for (auto el : squad) {
            el->sendPacket(std::string(msg.begin(), msg.end()));
        }
        throw GameIsFinish("No Player");
    }
        // No Mob
    if (rtype::singleton::ECManager::get().getComponent<rtype::component::ListMethodeMob>(id)._list.size() == 0) {
        std::cout << "[Error]: No Mob load with Dynamic Lib" << std::endl;
        rtype::network::EndGameMssg StructData = {0};
        StructData.type = rtype::network::MessageTypeServer::ENDGAME;
        StructData.has_won = false;
        std::vector<char> msg(sizeof(struct rtype::network::EndGameMssg));
        memcpy(msg.data(), &StructData, sizeof(struct rtype::network::EndGameMssg));
        for (auto &client : handler.getComponent<rtype::component::ListClientNetwork>(id)._list) {
            rtype::system::NetworkWrite().send(id, std::make_pair(std::string(msg.begin(), msg.end()), client.second));
        }
        for (auto el : squad) {
            el->sendPacket(std::string(msg.begin(), msg.end()));
        }
        throw GameIsFinish("No Mob");
    }

        // Check Condition Game Win
    if (rtype::singleton::ECManager::get().getComponent<rtype::component::NbrMob>(id)._count >= MONSTER_MAX_NBR) {
        rtype::network::EndGameMssg StructData;
        StructData.type = rtype::network::MessageTypeServer::ENDGAME;
        StructData.has_won = true;
        std::vector<char> msg(sizeof(struct rtype::network::EndGameMssg));
        memcpy(msg.data(), &StructData, sizeof(struct rtype::network::EndGameMssg));
        for (auto &client : handler.getComponent<rtype::component::ListClientNetwork>(id)._list) {
            rtype::system::NetworkWrite().send(id, std::make_pair(std::string(msg.begin(), msg.end()), client.second));
        }
        for (auto el : squad) {
            el->sendPacket(std::string(msg.begin(), msg.end()));
        }
        throw GameIsFinish("Game Win");
    }
        // Condition Game Over
    for (auto &entity : handler._cMan.getComponentsFromType<rtype::component::ItsPlayer>()) {
        if (handler.getComponent<rtype::component::Life>(entity.first)._life > 0) {
            return;
        }
    }
    rtype::network::EndGameMssg StructData = {0};
    StructData.type = rtype::network::MessageTypeServer::ENDGAME;
    StructData.has_won = false;
    std::vector<char> msg(sizeof(struct rtype::network::EndGameMssg));
    memcpy(msg.data(), &StructData, sizeof(struct rtype::network::EndGameMssg));
    for (auto &client : handler.getComponent<rtype::component::ListClientNetwork>(id)._list) {
        rtype::system::NetworkWrite().send(id, std::make_pair(std::string(msg.begin(), msg.end()), client.second));
    }
    for (auto el : squad) {
        el->sendPacket(std::string(msg.begin(), msg.end()));
    }
    throw GameIsFinish("Game Over");
}
