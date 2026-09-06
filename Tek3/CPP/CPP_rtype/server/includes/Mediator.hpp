/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Mediator
*/

#ifndef COMMONMEDIATOR_HPP_
#define COMMONMEDIATOR_HPP_

#include "entities/ComponentManager.hpp"
#include "systems/ISubSystem.hpp"
#include "singleton/ECManager.hpp"
#include <unordered_map>

#define NB_OF_CPTS_TEMP 5

namespace rtype {

    template<size_t sz> struct bitset_comparer {
        bool operator() (const std::bitset<sz> &b1, const std::bitset<sz> &b2) const {
            return b1.to_ullong() == b2.to_ullong();
        }
    };

    class Mediator {
        public:
         Mediator(rtype::entity::ComponentManager &ecMan);
        ~Mediator() = default;

        void mediate(const Entity &entities); //used for collision ?

        // void addSubSystem(const Signature &sig, SubSystem &subSystem);
        void addSubSystem(const TempSignature &sig, std::shared_ptr<system::ISubSystem> subSystem);
        void resetTempSignature(const Entity &entities);
        static Mediator& get() {
            static Mediator res(rtype::singleton::ECManager::get());
                return res;
        }

        private:
        rtype::entity::ComponentManager &_ecMan;
        std::unordered_map<TempSignature, std::shared_ptr<system::ISubSystem>> _subSystems;
    };
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