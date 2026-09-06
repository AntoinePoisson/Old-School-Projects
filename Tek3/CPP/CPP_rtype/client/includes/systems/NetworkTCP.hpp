/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System ChangeMe
*/

#ifndef NETWORKTCP_HPP_
#define CLIENTSYSTEMCHANGEME_HPP_

#include "systems/ASystem.hpp"
#include "singleton/ECManager.hpp"

#include "systems/ISubSystem.hpp"


namespace rtype {
    namespace system {
        class NetworkTCPReader : public ASystem {
            private:
                std::shared_ptr<rtype::component::SocketTCP> _s;
                std::shared_ptr<rtype::component::QueueMessageRecvClient> _queue_mssg;
                Entity _queueId; // for mediator and interpreter
            protected:
            public:
                NetworkTCPReader();
                ~NetworkTCPReader() = default;
                bool readMessage();
                int readHeader();
                void update(const Entity &id) final;
        };
    }
    namespace subsystem {
        class NetworkTCPWriter : public system::ISubSystem {
            private:
            protected:
                std::shared_ptr<rtype::component::QueueMessageSendClient> _queue_mssg;
                std::shared_ptr<rtype::component::SocketTCP> _s;

            public:
                NetworkTCPWriter();
                ~NetworkTCPWriter() = default;
                void update(const Entity &id);
        };
    }
}

#endif /* !CLIENTSYSTEMCHANGEME_HPP_ */
