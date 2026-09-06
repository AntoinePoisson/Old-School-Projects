/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** SubSystemServer
*/

#include "systems/SubSystemsServer.hpp"
#include "singleton/ECManager.hpp"
#include "entities/ComponentManager.hpp"

void rtype::subsystem::InterpretNetworkServer::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    // rtype::component::Socket sock = handler.getComponent(id, );

    // if (sock._socket.is_open() == false)
    //     return;
    // sock._socket.close();
    // remove socket / io_context / network info / QueueMessageReceive / QueueMessageSend
}
