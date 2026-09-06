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

        class OpenAsyncRead : public system::ISubSystem {
            public:
                OpenAsyncRead() = default;
                virtual ~OpenAsyncRead() = default;
                void update(const Entity &id) final;
        };

        class NetworkRead : public system::ISubSystem {
            public:
                NetworkRead() = default;
                virtual ~NetworkRead() = default;
                void update(const Entity &id) final;
        };

        class NetworkAddSomeWrite : public system::ISubSystem {
            public:
                NetworkAddSomeWrite() = default;
                virtual ~NetworkAddSomeWrite() = default;
                void update(const Entity &id) final;
        };
    }
}

#endif /* !COMMONSUBSYSTEM_HPP_ */
