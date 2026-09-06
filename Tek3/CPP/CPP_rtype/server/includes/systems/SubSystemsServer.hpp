/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System SubSystemServer
*/

#ifndef SERVERSYSTEMSUBSYSTEMSERVER_HPP_
#define SERVERSYSTEMSUBSYSTEMSERVER_HPP_

#include "systems/ISubSystem.hpp"

namespace rtype {
    namespace subsystem {

        class InterpretNetworkServer : public system::ISubSystem {
            public:
                InterpretNetworkServer() = default;
                virtual ~InterpretNetworkServer() = default;
                void update(const Entity &id);
        };

    }
}

#endif /* !SERVERSYSTEMSUBSYSTEMSERVER_HPP_ */
