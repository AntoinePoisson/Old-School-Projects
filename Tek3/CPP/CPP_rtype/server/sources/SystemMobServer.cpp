/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemMobServer
*/

#include "systems/MobServer.hpp"
#include "components/MethodeMob.hpp"
#include "singleton/ECManager.hpp"
#include "libMobs/includes/ILibMob.hpp"
#include "Server.hpp"
#include "Network.hpp"

void rtype::system::MobServer::creationMob(const Entity &id, int stage)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    std::vector<void *> list = handler.getComponent<rtype::component::ListMethodeMob>(id)._list;

    rtype::system::ILibMob *tmp = reinterpret_cast<rtype::system::ILibMob *> (list.at(list.size() > 1 ? (std::rand() % (list.size() - 1)) : 0));
    tmp->createEntity(handler, -1, -1, -1, stage);
    handler.getComponent<rtype::component::NbrMob>(id)._count += 1;
}


void rtype::system::MobServer::run(const Entity &id, int *prevNbr, int *stage)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    struct rtype::network::DeleteComponentMssg del = {0};
    std::vector<char> msg;

    if (*stage == 0 && *prevNbr + 2 >= MONSTER_MAX_NBR) {
        *prevNbr = 2;
        *stage = 1;
        for (auto &entity : handler._cMan.getComponentsFromType<rtype::component::ItsPlayer>()) {
            handler.getComponent<rtype::component::Level>(entity.first)._level = 1;
        }
        handler.getComponent<rtype::component::NbrMob>(id)._count = 0;
        for (auto &entity : handler._cMan.getComponentsFromType<rtype::component::ItsMob>()) {
            std::strcpy(del.uuid, entity.first.data());
            del.type = rtype::network::MessageTypeServer::DELETE_CPT;
            del.mask_bitset = rtype::idBitset::idPosition + rtype::idBitset::idType + rtype::idBitset::idLife;
            msg.clear();
            msg.resize(sizeof(struct rtype::network::DeleteComponentMssg)); ///
            memcpy(msg.data(), &del, sizeof(struct rtype::network::DeleteComponentMssg)); ///
            for (auto &client : handler.getComponent<rtype::component::ListClientNetwork>(id)._list) {
                rtype::system::NetworkWrite().send(id, std::make_pair(std::string(msg.begin(), msg.end()), client.second));
            }
            handler.deleteEntity(entity.first);
        }
    }

    if (rtype::singleton::ECManager::get().getComponent<rtype::component::ListMethodeMob>(id)._list.size() == 0) {
        std::cerr << "NO MOB CAN'T LAUNCH GAME" << std::endl;
        return;
    }
    if (handler.getComponent<rtype::component::NbrMob>(id)._count != *prevNbr) {
        *prevNbr += 1;
        if (*prevNbr == MONSTER_MAX_NBR / 3) {
            for (auto &entity : handler._cMan.getComponentsFromType<rtype::component::ItsPlayer>()) {
                handler.getComponent<rtype::component::Level>(entity.first)._level = 2;
            }
        }
        if (*prevNbr == MONSTER_MAX_NBR / 2) {
            for (auto &entity : handler._cMan.getComponentsFromType<rtype::component::ItsPlayer>()) {
                handler.getComponent<rtype::component::Level>(entity.first)._level = 3;
            }
        }
        while (handler.getComponent<rtype::component::NbrMob>(id)._count < *prevNbr) {
            creationMob(id, *stage);
        }
    }
            // std::cout << "0000" << std::endl;
    for (auto mob : handler._cMan.getComponentsFromType<rtype::component::ItsMob>()) {
            // std::cout << "---- " <<  mob.first << std::endl;
        for (auto ia : handler.getComponent<rtype::component::ListMethodeMob>(id)._list) {
            // std::cout << "1111" << std::endl;
            rtype::system::ILibMob *tmp = reinterpret_cast<rtype::system::ILibMob *> (ia);
            // std::cout << "2222" << std::endl;
            tmp->handlerIAMob(handler, mob.first);
            // std::cout << "3333" << std::endl;
            // reinterpret_cast<rtype::system::ILibMob *> (ia)->handlerIAMob(handler, mob.first);
        }
    }
    // std::cout << "9999" << std::endl;
    // std::exit(0);
}
