/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Movement
*/

#include "systems/MovementPlayerServer.hpp"
#include "singleton/ECManager.hpp"
#include "Server.hpp"

void rtype::system::MovementPlayerServer::action(const Entity &id, enum rtype::network::CodeAction move)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    switch (move) {
        case rtype::network::RIGHT:
            if (handler.getComponent<rtype::component::Position>(id)._x + PLAYER_SPEED + PLAYER_WIDTH <= MAP_WIDTH)
                handler.getComponent<rtype::component::Position>(id)._x += PLAYER_SPEED;
            break;
        case rtype::network::LEFT:
            if (handler.getComponent<rtype::component::Position>(id)._x - PLAYER_SPEED >= 0)
                handler.getComponent<rtype::component::Position>(id)._x -= PLAYER_SPEED;
            break;
        case rtype::network::UP:
            if (handler.getComponent<rtype::component::Position>(id)._y - PLAYER_SPEED >= 0)
                handler.getComponent<rtype::component::Position>(id)._y -= PLAYER_SPEED;
            break;
        case rtype::network::DOWN:
            if (handler.getComponent<rtype::component::Position>(id)._y + PLAYER_SPEED + PLAYER_HEIGHT <= MAP_HEIGHT)
                handler.getComponent<rtype::component::Position>(id)._y += PLAYER_SPEED;
            break;
    }
}
