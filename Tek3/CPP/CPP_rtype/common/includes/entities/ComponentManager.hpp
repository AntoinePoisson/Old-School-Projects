/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Entity ComponentManager
*/

#ifndef COMMONENTITYCOMPONENTMANAGER_HPP_
#define COMMONENTITYCOMPONENTMANAGER_HPP_


#include "entities/AManager.hpp"
#include "components/AManager.hpp"

#include "components/Sound.hpp"
#include "components/Window.hpp"
#include "components/Scene.hpp"
#include "components/Display.hpp"
#include "components/Events.hpp"
#include "components/Type.hpp"
#include "components/Collisions.hpp"
#include "components/Life.hpp"
#include "components/Physics.hpp"
#include "components/Network.hpp"
#include "components/Unremovable.hpp"

//server
#include "components/NetworkServer.hpp"
#include "components/PlayerServer.hpp"
#include "components/MethodeMob.hpp"
//client

namespace rtype {
    namespace entity {
        using Entity = std::string;

        class ComponentManager
        {
            private:
                std::map<std::type_index, Signature> _refSignature;
            public:
                rtype::component::AManager _cMan;
                rtype::entity::AManager _eMan;
            public:
                ComponentManager();
                ~ComponentManager() = default;
                /*deprecated*/
                static ComponentManager &get(void); //deprecated

                template<typename T>
                const Entity addComponent(const Entity &id, T &component)
                {
                    //add line to say if not exist then register entity within componentMan
                    if (_refSignature.find(std::type_index(typeid(T))) == _refSignature.end()) {
                        throw rtype::component::Exception("Add Component: Component type does not correspond to any registered component");
                    }
                    _cMan.addComponent(id, component);
                    _eMan.appendSignature(id,_refSignature[std::type_index(typeid(T))]);
                    return id;
                }

                template<typename T>
                const Entity addComponent(const Entity &id, std::shared_ptr<T> &component)
                {
                    //add line to say if not exist then register entity within componentMan
                    if (_refSignature.find(std::type_index(typeid(T))) == _refSignature.end()) {
                        throw rtype::component::Exception("Add Component: Component type does not correspond to any registered component");
                    }
                    _cMan.addComponent(id, component);
                    _eMan.appendSignature(id,_refSignature[std::type_index(typeid(T))]);
                    return id;
                }

                template<typename T>
                const Entity addComponents(const Entity &id, T &component)
                {
                    return addComponent(id, component);
                }

                template<typename T, typename ...Args>
                const Entity addComponents(const Entity &id, T &component, Args ...args)
                {
                    addComponent(id, component);
                    return addComponents(id, (args)...);
                }

                template<typename T>
                const Entity addTempComponent(const Entity &id, T &component)
                {
                    _cMan.addTempComponent(id, component);
                    return id;
                }

                const Entity addComponents(const Entity &id);
                //used in case you just want to add an entity without components

                template<typename ...Args>
                const Entity createEntity(const Signature &sig = Signature(0), Args ...args)
                {
                    const Entity id = _eMan.createEntity(sig);

                    return addComponents(id, (args)...);
                }

                const Entity createEntity(const Signature &sig = Signature(0)) {
                    const Entity id = _eMan.createEntity(sig);
                    return id;
                }

                template<typename T>
                bool removeComponent(const Entity &id)
                {
                    if (_refSignature.find(std::type_index(typeid(T))) == _refSignature.end()) {
                        throw rtype::component::Exception("Remove Component: Component type does not correspond to any registered component");
                    }
                    _eMan.removeSignature(id, _refSignature[std::type_index(typeid(T))]);
                    _cMan.removeComponent<T>(id);
                    return (true);
                }

                bool removeComponentFromTypeIndex(const Entity &id, const std::type_index &value);

                bool appendSignature(const Entity &entity_id, const Signature &additional_sig);

                template<typename T>
                T &getComponent(const Entity &id)
                {
                    return _cMan.getComponent<T>(id);
                }

                bool deleteEntity(const Entity &id);
        };

    }
}


#endif /* !COMMONENTITYCOMPONENTMANAGER_HPP_ */
