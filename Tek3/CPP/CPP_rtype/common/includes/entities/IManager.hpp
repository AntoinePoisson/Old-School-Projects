/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Entity IManager
*/

#ifndef COMMONENTENTITYIMANAGER_HPP_
#define COMMONENTENTITYIMANAGER_HPP_

#define NB_OF_CPTS 50
#define NB_OF_TEMP_CPTS 5

#include <bitset>

using Signature = std::bitset<NB_OF_CPTS>;
using TempSignature = std::bitset<NB_OF_TEMP_CPTS>;
using Entity = std::string;

namespace rtype {
    namespace entity {

        class IManager
        {
            public:
                virtual ~IManager() = default;

                virtual const Entity createEntity() = 0;
                virtual const Entity createEntity(const Signature &sig) = 0;
                virtual Signature getSignature(const Entity &entity_id) const = 0;
                virtual TempSignature getTempSignature(const Entity &entity_id) const = 0;
                virtual std::map<Entity, Signature> getEntities() const = 0;
                virtual bool removeEntity(const Entity &entitt_id) = 0;
                virtual bool appendSignature(const Entity &entity_id, const Signature &additional_sig) = 0;
                virtual bool removeSignature(const Entity &entity_id, const Signature &sig) = 0;
        };

    }
}


#endif /* !COMMONENTENTITYIMANAGER_HPP_ */
