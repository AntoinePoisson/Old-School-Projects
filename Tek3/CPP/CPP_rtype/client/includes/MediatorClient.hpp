/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Mediator
*/

#ifndef COMMONMEDIATOR_HPP_
#define COMMONMEDIATOR_HPP_

#include "entities/ComponentManager.hpp"
#include "entities/IManager.hpp"
#include "systems/ISubSystem.hpp"
#include "singleton/ECManager.hpp"

namespace rtype {
    namespace client {

        template<size_t sz> struct bitset_comparer {
            bool operator() (const std::bitset<sz> &b1, const std::bitset<sz> &b2) const {
                return b1.to_ullong() < b2.to_ullong();
            }
        };

        class Mediator
        {
            rtype::entity::ComponentManager &_ecMan;
            std::map<Signature, std::shared_ptr<system::ISubSystem>, bitset_comparer<NB_OF_CPTS>> _subSystems;
            // std::map<const Signature&, std::shared_ptr<system::ISubSystem>> _subSystems;

        public:
            Mediator(rtype::entity::ComponentManager &ecMan);
            ~Mediator() = default;

            void mediate(const Entity &entities); //used for collision ?

            void addSubSystem(const Signature &sig, std::shared_ptr<system::ISubSystem> subSystem);
            void deleteSubSystem(const Signature &sig);
            void deleteAllSubSystem();
            void replaceSubSystem(const Signature &sig, std::shared_ptr<system::ISubSystem> subSystem);

            static Mediator& get() {
                static Mediator res(rtype::singleton::ECManager::get());
                return res;
            }
        };
    }
}

#endif /* !COMMONMEDIATOR_HPP_ */

// for (entity.all)

// systemInterpret(entity) {
// socket != NULL;
// entity += componenentMessage;
// }

// mediator(entity) {
// entity.bitSetTEMPO == message -> call subsystemeSend(entity);
// }

// subsystemSend(entity) {
// socket.send(entitiy.componentMessage.text());
// }
