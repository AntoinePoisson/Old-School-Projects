/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemInterpretCollisionServer
*/

#include "systems/InterpretCollisionServer.hpp"
#include "singleton/ECManager.hpp"
#include "GameEngine.hpp"
#include "Network.hpp"

void rtype::system::InterpretCollisionServer::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    struct rtype::network::DeleteComponentMssg del = {0};
    std::vector<char> msg;

    for (auto &entity : handler._cMan.getComponentsFromType<rtype::component::ItsPlayer>()) {
        for (auto &collised : handler.getComponent<rtype::component::Collision>(entity.first)._entitiesId) {
            if (rtype::GameEngine::checkIfEntityIs(collised, rtype::whoIs::Bullet)) {
                handler.getComponent<rtype::component::Life>(entity.first)._life -= handler.getComponent<rtype::component::Damage>(collised)._damage;
                handler.getComponent<rtype::component::DeletOrPrint>(collised).delet = true;
                if (handler.getComponent<rtype::component::Life>(entity.first)._life <= 0)
                    std::cout << "One Player is Dead" << std::endl;
            }
            if (rtype::GameEngine::checkIfEntityIs(collised, rtype::whoIs::Monster)) {
                handler.getComponent<rtype::component::Life>(entity.first)._life -= handler.getComponent<rtype::component::Damage>(collised)._damage;
                if (handler.getComponent<rtype::component::Life>(entity.first)._life <= 0)
                    std::cout << "One Player is Dead" << std::endl;
            }
        }
        handler.getComponent<rtype::component::Collision>(entity.first)._entitiesId.clear();
    }

    for (auto &entity : handler._cMan.getComponentsFromType<rtype::component::ItsMob>()) {
        for (auto &collised : handler.getComponent<rtype::component::Collision>(entity.first)._entitiesId) {
            if (rtype::GameEngine::checkIfEntityIs(collised, rtype::whoIs::Bullet)) {
                handler.getComponent<rtype::component::Life>(entity.first)._life -= handler.getComponent<rtype::component::Damage>(collised)._damage;
                handler.getComponent<rtype::component::DeletOrPrint>(collised).delet = true;
            }
        }
        handler.getComponent<rtype::component::Collision>(entity.first)._entitiesId.clear();
        if (handler.getComponent<rtype::component::Life>(entity.first)._life <= 0) {
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
            handler.getComponent<rtype::component::NbrMob>(id)._count -= 1;
        }
    }
}
