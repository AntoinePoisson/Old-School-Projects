/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System Sub
*/

#ifndef COMMONSUBSYSTEMS_HPP_
#define COMMONSUBSYSTEMS_HPP_

#include "systems/ISubSystem.hpp"

namespace rtype {
    namespace subsystem {

        class EventHandler : public system::ISubSystem
        {
            public:
                EventHandler() = default;
                virtual ~EventHandler() = default;

                void update(const Entity &id);
                void handleKeyboard(const Entity &id);
                void handleMouse(const Entity &id);
                void handleButtonAction(const Entity &id);
                std::string getCodeActionMssgString(int player, int actionId);
                void handleVolume(const Entity &id, bool plus);
        };

        // class NetworkRead : public system::ISubSystem
        // {
        //     public:
        //         NetworkRead() = default;
        //         virtual ~NetworkRead() = default;

        //         void update(const Entity &id) final;
        // };

        // class NetworkAddSomeWrite : public system::ISubSystem
        // {
        //     public:
        //         NetworkAddSomeWrite() = default;
        //         virtual ~NetworkAddSomeWrite() = default;

        //         void update(const Entity &id) final;
        // };
    }
}

#endif /* !COMMONSUBSYSTEM_HPP_ */
