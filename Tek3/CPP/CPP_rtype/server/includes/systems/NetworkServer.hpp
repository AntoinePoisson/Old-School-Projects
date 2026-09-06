/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System StartServer
*/

#ifndef SERVERNETWORKSERVER_HPP_
#define SERVERNETWORKSERVER_HPP_

#include "systems/ASystem.hpp"
#include "entities/ComponentManager.hpp"
#include "components/Network.hpp"
#include "components/TempComponents.hpp"
#include "Server.hpp"

namespace rtype {
    namespace system {

        class StartNetworkServer : public ASystem {
            public:
                StartNetworkServer() = default;
                virtual ~StartNetworkServer() = default;

                void update(const Entity &id) final;
        };

        class CloseNetworkServer : public ASystem {
            public:
                CloseNetworkServer() = default;
                virtual ~CloseNetworkServer() = default;

                void update(const Entity &id) final;
        };

        class InterpretNetworkServer : public ASystem {
            public:
                InterpretNetworkServer() = default;
                virtual ~InterpretNetworkServer() = default;

                void update(const Entity &id) final;
        };

        class SendEntities : public ASystem {
            private:
                unsigned long playerMaskBitset(const Entity &id, rtype::entity::ComponentManager &handler);
                const std::vector<char> playerMessageComponent(const Entity &id, rtype::entity::ComponentManager &handler);
                unsigned long mobMaskBitset(const Entity &id, rtype::entity::ComponentManager &handler);
                const std::vector<char> mobMessageComponent(const Entity &id, rtype::entity::ComponentManager &handler);
                unsigned long bulletMaskBitset(const Entity &id, rtype::entity::ComponentManager &handler);
                const std::vector<char> bulletMessageComponent(const Entity &id, rtype::entity::ComponentManager &handler);

            public:
                SendEntities() = default;
                virtual ~SendEntities() = default;

                void update(const Entity &id) final;
        };

    }
}

#endif /* !STARTSERVER_HPP_ */
