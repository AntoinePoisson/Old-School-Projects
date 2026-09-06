/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemShootServer
*/

#include "systems/ShootServer.hpp"
#include "singleton/ECManager.hpp"
#include "GameEngine.hpp"
#include "Server.hpp"

void rtype::system::ShootBullet::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::component::Position pos = handler.getComponent<rtype::component::Position>(id);
    rtype::component::Level level = handler.getComponent<rtype::component::Level>(id);

    rtype::GameEngine::createBullet(MAP_HEIGHT, pos._y, pos._x, pos._y, level._level);
}

void rtype::system::CheckBullet::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    for (auto &entity : handler._cMan.getComponentsFromType<rtype::component::ItsBullet>()) {
        rtype::component::Position &pos = handler.getComponent<rtype::component::Position>(entity.first);
        rtype::component::Destination dest = handler.getComponent<rtype::component::Destination>(entity.first);
        rtype::component::Speed speed = handler.getComponent<rtype::component::Speed>(entity.first);
        rtype::component::DeletOrPrint &del = handler.getComponent<rtype::component::DeletOrPrint>(entity.first);
        int direction = dest._x - pos._x;
        if (pos._x <= 0 || pos._x >= MAP_HEIGHT) {
            del.delet = true;
        //    handler.deleteEntity(entity.first);
            continue;
        }
        if (direction <= 0)
            for (int i = 0; i < (speed._speed  / TIMERGAME); i++)
                pos._x = pos._x - 1;
        else {
            for (int i = 0; i < (speed._speed / TIMERGAME); i++)
                pos._x = pos._x + 1;
        }
    }
}