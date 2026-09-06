/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** ComponentManager
*/

#include "components/AManager.hpp"

bool rtype::component::AManager::removeEntityComponents(const Entity &entity_id)
{
    if (_components.find(entity_id) == _components.end()) {
        throw rtype::component::Exception("Remove Entity: " + entity_id + " not found");
    }
    _components.erase(entity_id);
    if (!(_tempComponent.find(entity_id) == _tempComponent.end()))
        _tempComponent.erase(entity_id);
    return true;
}

bool rtype::component::AManager::removeComponentFromTypeIndex(const Entity &entity_id, const std::type_index &index)
{
    if (_components.find(entity_id) == _components.end()) {
        throw rtype::entity::Exception("Remove Entity: " + entity_id + " not found");
    }
    if (_components[entity_id].find(index) == _components[entity_id].end()) {
        throw rtype::component::Exception("Remove Component: doesn't exist");
    }
    _components[entity_id].erase(index);
    return true;
}
