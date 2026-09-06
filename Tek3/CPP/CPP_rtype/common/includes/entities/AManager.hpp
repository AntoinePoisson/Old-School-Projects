/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Entity Entity
*/

#ifndef COMMONENTITYAENTITYMANAGER_HPP_
#define COMMONENTITYAENTITYMANAGER_HPP_

#include <map>
#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "entities/Exception.hpp"
#include "entities/IManager.hpp"

namespace rtype {
    namespace entity {
        using Entity = std::string;

        class AManager : public IManager
        {
            public:
                std::map<Entity, Signature> _entities;
                std::vector<Entity> _idEntities;
                void setTempEntities();
            public:
                AManager() = default;
                virtual ~AManager() = default;

                const Entity createEntity() final;
                const Entity createEntity(const Signature &sig) final;
                const Entity createEntity(Entity uuid);

                Signature getSignature(const Entity &entity_id) const final;
                TempSignature getTempSignature(const Entity &entity_id) const final;
                bool removeEntity(const Entity &entitt_id) final;
                std::map<Entity, TempSignature> _tempEntities;
                std::map<Entity, Signature> getEntities() const final;
                bool appendSignature(const Entity &entity_id, const Signature &additional_sig) final;
                bool removeSignature(const Entity &entity_id, const Signature &sig) final;
        };

    }
}


#endif /* !COMMONENTITYAENTITYMANAGER_HPP_ */
