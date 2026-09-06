/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** EntityManager
*/

#include "entities/AManager.hpp"
#include <algorithm>

const Entity rtype::entity::AManager::createEntity()
{
    //default signature: 00000...
    Entity uuid = boost::uuids::to_string(boost::uuids::random_generator()());

    _entities[uuid] = Signature(0);
    _idEntities.push_back(uuid);
    _tempEntities[uuid] = TempSignature(0);
    return uuid;
}

const Entity rtype::entity::AManager::createEntity(const Signature &sig)
{
    Entity uuid = boost::uuids::to_string(boost::uuids::random_generator()());

    _entities[uuid] = sig;
    // std::cout << sig.to_ulong() << std::endl;
    _idEntities.push_back(uuid);
    _tempEntities[uuid] = TempSignature(0);
    return uuid;
}

const Entity rtype::entity::AManager::createEntity(Entity uuid)
{
    _entities[uuid] = Signature(0);
    _idEntities.push_back(uuid);
    _tempEntities[uuid] = TempSignature(0);
    return uuid;
}

void rtype::entity::AManager::setTempEntities()
{
    std::map<Entity, Signature>::iterator it = _entities.begin();

    while (it != _entities.end())
        _tempEntities[it->first] = TempSignature(0);
}


Signature rtype::entity::AManager::getSignature(const Entity &entity_id) const
{
    if (_entities.find(entity_id) == _entities.end()) {
        throw rtype::entity::Exception("Get Signature: entity " + entity_id + " not found");
    }
    // std::cout << "la" << _entities.find(entity_id)->second << std::endl;
    return _entities.find(entity_id)->second;
}

TempSignature rtype::entity::AManager::getTempSignature(const Entity &entity_id) const
{
    //std::cout << "TEMP ENTITITES " << _tempEntities.size() << std::endl;
    if (_tempEntities.find(entity_id) == _tempEntities.end()) {
        throw rtype::entity::Exception("Get TempSignature: entity " + entity_id + " not found");
    }
//    if (_tempEntities.find(entity_id)->second == TempSignature(8))
       //std::cout << "C4EST LES MEMES" <<std::endl;
    //std::cout << "ICI " << _tempEntities.find(entity_id)->second << " VS " << TempSignature(8) << std::endl;
    //std::cout << "ICI2 " << entity_id << std::endl;
    return _tempEntities.find(entity_id)->second;
}

std::map<Entity, Signature> rtype::entity::AManager::getEntities() const
{
    return _entities;
}


bool rtype::entity::AManager::removeEntity(const Entity &entity_id)
{
    if (_entities.find(entity_id) == _entities.end()) {
        throw rtype::entity::Exception("Remove Entity: " + entity_id + " not found");
    }
    _entities.erase(entity_id);
    auto it = std::find(_idEntities.begin(), _idEntities.end(), entity_id);
    _idEntities.erase(it);
    return true;
}

bool rtype::entity::AManager::appendSignature(const Entity &entity_id, const Signature &additional_sig)
{
    if (_entities.find(entity_id) == _entities.end()) {
        throw rtype::entity::Exception("Append Signature: entity " + entity_id + " not found");
    }
    auto res = _entities[entity_id] | additional_sig;
    _entities[entity_id] = res;
    return true;
}

bool rtype::entity::AManager::removeSignature(const Entity &entity_id, const Signature &sig)
{
    if (_entities.find(entity_id) == _entities.end()) {
        throw rtype::entity::Exception("Remove Signature: entity " + entity_id + " not found");
    }
    auto res = _entities[entity_id] ^ sig;
    _entities[entity_id] = res;
    return true;
}
