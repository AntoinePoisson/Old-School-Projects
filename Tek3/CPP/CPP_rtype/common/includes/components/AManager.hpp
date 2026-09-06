/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component AManager
*/

#ifndef COMMONCOMPONENTAMANAGER_HPP_
#define COMMONCOMPONENTAMANAGER_HPP_

#include <bitset>
#include <map>
#include <vector>
#include <typeindex>
#include <memory>

#include "components/IManager.hpp"
#include "components/AComponent.hpp"
#include "components/Exception.hpp"
#include "entities/Exception.hpp"

using Entity = std::string;

namespace rtype {
    namespace component {

        class AManager
        {
            public:
                std::map<const Entity, std::map<std::type_index, std::shared_ptr<AComponent>>> _components;
                std::map<const Entity, std::shared_ptr<AComponent>> _tempComponent;
            public:
                AManager() = default;
                virtual ~AManager() = default;

                template<typename T>
                bool addComponent(const std::string &entity_id, const T &cpt)
                {
                    std::type_index index(typeid(cpt));

                    if (_components[entity_id].find(index) != _components[entity_id].end()) {
                        throw rtype::component::Exception("Component already exist");
                    }
                    _components[entity_id][index] = std::make_shared<T>(cpt);
                    return true;
                }

                template<typename T>
                bool addComponent(const std::string &entity_id, std::shared_ptr<T> &cpt)
                {
                    std::type_index index(typeid(T));

                    if (_components[entity_id].find(index) != _components[entity_id].end()) {
                        throw rtype::component::Exception("Component already exist");
                    }
                    _components[entity_id][index] = cpt;
                    return true;
                }

                template<typename T>
                void addTempComponent(const std::string &entity_id, const T &cpt)
                {
                    _tempComponent[entity_id] = std::make_shared<T>(cpt);
                }

                bool removeComponentFromTypeIndex(const Entity &entity_id,  const std::type_index &value);

                template<typename T>
                bool removeComponent(const Entity &entity_id)
                {
                    std::type_index index(typeid(T));

                    if (_components.find(entity_id) == _components.end()) {
                        throw rtype::entity::Exception("Remove Entity: " + entity_id + " not found");
                    }
                    if (_components[entity_id].find(index) == _components[entity_id].end()) {
                        throw rtype::component::Exception("Remove Component: doesn't exist");
                    }
                    _components[entity_id].erase(index);
                    return true;
                }

                template<typename T>
                bool removeTempComponent(const Entity &entity_id)
                {
                    if (_tempComponent.find(entity_id) == _tempComponent.end()) {
                        throw rtype::entity::Exception("Remove Entity: " + entity_id + " not found");
                    }
                    if (_tempComponent.size() == 0) {
                        throw rtype::component::Exception("Remove Component: there is no components");
                    }
                    _tempComponent.erase(entity_id);
//                    _tempComponent[entity_id].erase(index);
                    return true;
                }

                template<typename T>
                T &getComponent(const Entity &entity_id)
                {
                    std::type_index index(typeid(T));

                    if (_components.find(entity_id) == _components.end()) {
                        std::cout << "HERE WRONG GETTER" << std::endl;
                        throw rtype::component::Exception("Get Component: entity " + entity_id + " not found");
                    }
                    auto cpt = _components[entity_id].find(index);
                    if (cpt == _components[entity_id].end()) {
                        throw rtype::component::Exception("Get Component: specified type doesn't exist for entity " + entity_id);
                    }
                    return static_cast<T&>(*(cpt->second));
                }

                template<typename T>
                T &getTempComponent(const Entity &entity_id)
                {
                    if (_tempComponent.find(entity_id) == _tempComponent.end()) {
                        throw rtype::component::Exception("Get Component: entity " + entity_id + " not found");
                    }
                    auto cpt = _tempComponent[entity_id];
                    // if (cpt == _tempComponent[entity_id].end()) {
                    //     throw rtype::component::Exception("Get Component: specified type doesn't exist for entity " + entity_id);
                    // }
                    return static_cast<T&>(*(cpt));
                }

                bool removeEntityComponents(const Entity &entity_id);

                template<typename T>
                std::pair<Entity,std::shared_ptr<T>>  getComponentFromType() {
                    std::type_index index(typeid(T));
                    for (auto entIt = _components.begin();
                     entIt != _components.end(); entIt++) {
                         if (entIt->second.find(index) == entIt->second.end())
                            continue;
                         else {
                            auto ptr = std::dynamic_pointer_cast<T>(entIt->second[index]);
                            return std::make_pair(entIt->first, ptr);
                         }
                     }
                    throw rtype::component::Exception("Get Component From Type: component type not found");
                }

                template<typename T>
                std::map<Entity, std::shared_ptr<T>> getComponentsFromType() {
                // std::map<Entity, T&> getComponentsFromType() {
                    std::type_index index(typeid(T));
                    std::map<Entity, std::shared_ptr<T>> matches;
                    for (auto entIt = _components.begin();
                     entIt != _components.end(); entIt++) {
                         if (entIt->second.find(index) == entIt->second.end())
                            continue;
                         else {
                            auto ptr = std::dynamic_pointer_cast<T>(entIt->second[index]);
                            matches.emplace(entIt->first, ptr);
                         }
                     }
                     return matches;
                }

        };

    }
}

#endif /* !COMMONCOMPONENTAMANAGER_HPP_ */
