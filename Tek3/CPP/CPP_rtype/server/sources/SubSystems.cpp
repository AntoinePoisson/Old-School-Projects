/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SubSystem
*/

#include "SubSystems.hpp"
#include "components/TempComponents.hpp"
#include "systems/Network.hpp"
#include "Mediator.hpp"
#include "singleton/ECManager.hpp"

void rtype::subsystem::OpenAsyncRead::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    std::cout << "CA RENTRE DANS NETWOR openAsyncRead SUB" << std::endl;
    rtype::system::NetworkRead().openAsyncRead(id);
    handler._cMan.removeTempComponent<rtype::component::TempRead>(id);
}

void rtype::subsystem::NetworkRead::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    std::cout << "CA RENTRE DANS NETWOR READ SUB" << std::endl;
    rtype::system::NetworkRead().update(id);
    handler._cMan.removeTempComponent<rtype::component::TempRead>(id);
}

void rtype::subsystem::NetworkAddSomeWrite::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::component::TempWrite a = handler._cMan.getTempComponent<rtype::component::TempWrite>(id);

    rtype::system::NetworkAddSomeWrite().add(id, a._message, a._endpoint);
    handler._cMan.removeTempComponent<rtype::component::TempWrite>(id);
}