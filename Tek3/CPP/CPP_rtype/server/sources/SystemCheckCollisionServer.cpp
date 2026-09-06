/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** systemCheckCollisionServer
*/

#include "systems/CheckCollisionServer.hpp"
#include "singleton/ECManager.hpp"
#include "Server.hpp"

void rtype::system::CheckCollisionServer::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    int CompareX = 0;
    int CompareY = 0;
    int CompareSurfaceX = 0;
    int CompareSurfaceY = 0;
    int ComparatorX = 0;
    int ComparatorY = 0;
    int ComparatorSurfaceX = 0;
    int ComparatorSurfaceY = 0;

    for (auto &entity : handler._eMan.getEntities()) {
        if (entity.first == id)
            continue;
        CompareY = handler.getComponent<rtype::component::Position>(entity.first)._y;
        CompareX = handler.getComponent<rtype::component::Position>(entity.first)._x;
        CompareSurfaceY = CompareY + handler.getComponent<rtype::component::Surface>(entity.first)._height;
        CompareSurfaceX = CompareX + handler.getComponent<rtype::component::Surface>(entity.first)._width;
        for (auto &el : handler._eMan.getEntities()) {
            if (el.first == id)
                continue;
                ComparatorY = handler.getComponent<rtype::component::Position>(el.first)._y;
                ComparatorX = handler.getComponent<rtype::component::Position>(el.first)._x;
                ComparatorSurfaceY = ComparatorY + handler.getComponent<rtype::component::Surface>(el.first)._height;
                ComparatorSurfaceX = ComparatorX + handler.getComponent<rtype::component::Surface>(el.first)._width;

                if (!COLLISION_ENABLE)
                    continue;
                if (CompareX < ComparatorX && (CompareSurfaceX) > ComparatorX) {
                    if ((CompareY < ComparatorY && (CompareSurfaceY) > ComparatorY) ||
                        (CompareY < (ComparatorSurfaceY) && (CompareSurfaceY) > (ComparatorSurfaceY))) {
                        handler.getComponent<rtype::component::Collision>(entity.first)._entitiesId.push_back(el.first);
                        continue;
                    }
                }
                if (ComparatorX < CompareX && (ComparatorSurfaceX) > CompareX) {
                    if ((ComparatorY < CompareY && (ComparatorSurfaceY) > CompareY) ||
                        (ComparatorY < (CompareSurfaceY) && (ComparatorSurfaceY) > (CompareSurfaceY))) {
                        handler.getComponent<rtype::component::Collision>(entity.first)._entitiesId.push_back(el.first);
                        continue;
                    }
                }
                if (CompareY < ComparatorY && (CompareSurfaceY) > ComparatorY) {
                    if ((CompareX < ComparatorX && (CompareSurfaceX) > ComparatorX) ||
                        (CompareX < (ComparatorSurfaceX) && (CompareSurfaceX) > (ComparatorSurfaceX))) {
                        handler.getComponent<rtype::component::Collision>(entity.first)._entitiesId.push_back(el.first);
                        continue;
                    }
                }
                if (ComparatorY < CompareY && (ComparatorSurfaceY) > CompareY) {
                    if ((ComparatorX < CompareX && (ComparatorSurfaceX) > CompareX) ||
                        (ComparatorX < (CompareSurfaceX) && (ComparatorSurfaceX) > (CompareSurfaceX))) {
                        handler.getComponent<rtype::component::Collision>(entity.first)._entitiesId.push_back(el.first);
                        std::cout << "4" << std::endl;
                        continue;
                    }
                }
        }
    }
}
