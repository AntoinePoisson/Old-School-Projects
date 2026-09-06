/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** EntityComponentManager
*/

#include "entities/ComponentManager.hpp"
#include "RType.hpp"

// rtype::entity::ComponentManager::ComponentManager(const rtype::entity::AManager &ent = _entManager, const rtype::component::AManager &cpt = _cptManager)
rtype::entity::ComponentManager::ComponentManager()
// _eMan(_entManager), _cMan(_cptManager)
{
    _refSignature.insert({std::type_index(typeid(rtype::component::Position)), Signature(rtype::idPosition)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Destination)), Signature(rtype::idDestination)});
    _refSignature.insert({std::type_index(typeid(rtype::component::NextPosition)), Signature(rtype::idNextPosition)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Direction)), Signature(rtype::idDirection)});
    _refSignature.insert({std::type_index(typeid(rtype::component::StartingTime)), Signature(rtype::idStartingTime)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Speed)), Signature(rtype::idSpeed)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Surface)), Signature(rtype::idSurface)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Collision)), Signature(rtype::idCollision)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Collided)), Signature(rtype::idCollided)});
    _refSignature.insert({std::type_index(typeid(rtype::component::ConceidedDamage)), Signature(rtype::idConceidedDamage)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Damage)), Signature(rtype::idDamage)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Life)), Signature(rtype::idLife)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Sprite)), Signature(rtype::idSprite)});
    _refSignature.insert({std::type_index(typeid(rtype::component::SpriteSheet)), Signature(rtype::idSpriteSheet)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Text)), Signature(rtype::idText)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Sound)), Signature(rtype::idSound)});
    _refSignature.insert({std::type_index(typeid(rtype::component::StartCriteria)), Signature(rtype::idStartCriteria)});
    _refSignature.insert({std::type_index(typeid(rtype::component::KeyboardEvent)), Signature(rtype::idKeyboardEvent)});
    _refSignature.insert({std::type_index(typeid(rtype::component::IOService)), Signature(rtype::idIOService)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Socket)), Signature(rtype::idSocket)});
    _refSignature.insert({std::type_index(typeid(rtype::component::MyNetworkInfo)), Signature(rtype::idMyNetworkInfo)});
    _refSignature.insert({std::type_index(typeid(rtype::component::OpponentNetworkInfo)), Signature(rtype::idOpponentNetworkInfo)});
    _refSignature.insert({std::type_index(typeid(rtype::component::QueueMessageReceive)), Signature(rtype::idQueueMessageReceive)});
    _refSignature.insert({std::type_index(typeid(rtype::component::QueueMessageSend)), Signature(rtype::idQueueMessageSend)});
    _refSignature.insert({std::type_index(typeid(rtype::component::ListClientNetwork)), Signature(rtype::idListClientNetwork)});
    _refSignature.insert({std::type_index(typeid(rtype::component::ListAction)), Signature(rtype::idListAction)});
    _refSignature.insert({std::type_index(typeid(rtype::component::SFMLEvent)), Signature(rtype::idSFMLEvent)});
    _refSignature.insert({std::type_index(typeid(rtype::component::SFMLWindow)), Signature(rtype::idSFMLWindow)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Music)), Signature(rtype::idMusic)});
    _refSignature.insert({std::type_index(typeid(rtype::component::DisplayOrder)), Signature(rtype::idDisplayOrder)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Type)), Signature(rtype::idType)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Scene)), Signature(rtype::idScene)});
    _refSignature.insert({std::type_index(typeid(rtype::component::SocketTCP)), Signature(rtype::idSocketTCP)});
    _refSignature.insert({std::type_index(typeid(rtype::component::QueueMessageSendClient)), Signature(rtype::idQueueMessageSendClient)});
    _refSignature.insert({std::type_index(typeid(rtype::component::QueueMessageRecvClient)), Signature(rtype::idQueueMessageRecvClient)});
    _refSignature.insert({std::type_index(typeid(rtype::component::ServerEndpoints)), Signature(rtype::idServerEndpoints)});
    _refSignature.insert({std::type_index(typeid(rtype::component::MouseEvent)), Signature(rtype::idMouseEvent)});
    _refSignature.insert({std::type_index(typeid(rtype::component::ButtonAction)), Signature(rtype::idButtonAction)});
    _refSignature.insert({std::type_index(typeid(rtype::component::ItsServer)), Signature(rtype::idServer)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Unremovable)), Signature(rtype::idUnremovable)});
    _refSignature.insert({std::type_index(typeid(rtype::component::ItsPlayer)), Signature(rtype::idPlayer)});
    _refSignature.insert({std::type_index(typeid(rtype::component::ItsBullet)), Signature(rtype::idBullet)});
    _refSignature.insert({std::type_index(typeid(rtype::component::ItsMob)), Signature(rtype::idMob)});
    _refSignature.insert({std::type_index(typeid(rtype::component::ListMethodeMob)), Signature(rtype::idListMethodeMob)});
    _refSignature.insert({std::type_index(typeid(rtype::component::NbrMob)), Signature(rtype::idNbrMob)});
    _refSignature.insert({std::type_index(typeid(rtype::component::Level)), Signature(rtype::idLevel)});
    _refSignature.insert({std::type_index(typeid(rtype::component::DeletOrPrint)), Signature(rtype::idDeletOrPrint)});
    _refSignature.insert({std::type_index(typeid(rtype::component::GlobalVolume)), Signature(rtype::idGlobalVolume)});
    _refSignature.insert({std::type_index(typeid(rtype::component::TimerMob)), Signature(rtype::idTimerMob)});
}

bool rtype::entity::ComponentManager::deleteEntity(const Entity &id)
{
    _eMan.removeEntity(id);
    _cMan.removeEntityComponents(id);
    return true;
}

rtype::entity::ComponentManager &rtype::entity::ComponentManager::get(void)
{
    static rtype::entity::ComponentManager res = rtype::entity::ComponentManager();

    return res;
}

const Entity rtype::entity::ComponentManager::addComponents(const Entity &id)
{
    return id;
}

bool rtype::entity::ComponentManager::removeComponentFromTypeIndex(const Entity &id, const std::type_index &value)
{
    if (_refSignature.find(value) == _refSignature.end()) {
        throw rtype::component::Exception("Remove Component: Component type does not correspond to any registered component");
    }
    _eMan.removeSignature(id, _refSignature[value]);
    _cMan.removeComponentFromTypeIndex(id, value);
    return (true);
}
