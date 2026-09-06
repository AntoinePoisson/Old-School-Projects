#ifndef NETWORKUPD_HPP
#define NETWORKUDP_HPP

#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "components/Network.hpp"
#include "Network.hpp"

#include "entities/ComponentManager.hpp"
#include "systems/ASystem.hpp"

#include "systems/ISubSystem.hpp"

namespace rtype {
    namespace system {

        class NetworkUDPReader : public ASystem
        {
            private:
                std::shared_ptr<rtype::component::Socket> _s;
                std::shared_ptr<rtype::component::QueueMessageRecvClient> _queue_mssg;
                Entity _queueId; // for mediator and interpreter
                boost::asio::ip::udp::endpoint _serverEdp;
            private:
                void handlerRead(const boost::system::error_code& err, std::size_t size, Entity _idEntity, boost::asio::ip::udp::endpoint *_endpoint, std::string *_buff);

            public:
                NetworkUDPReader();
                virtual ~NetworkUDPReader() = default;

                void update(const Entity &e);
                void openAsyncRead(const Entity &id);
        };
    }

    namespace subsystem {
        class NetworkUDPWriter : public system::ISubSystem
        {
            private:
                std::shared_ptr<rtype::component::Socket> _s;
                std::shared_ptr<rtype::component::QueueMessageSendClient> _queue_mssg;
                boost::asio::ip::udp::endpoint _serverEdp;

            private:
                void handlerWrite(const boost::system::error_code& err, std::size_t size, Entity _idEntity);
                void openAsyncWrite(const Entity &id);

            public:
                NetworkUDPWriter();
                virtual ~NetworkUDPWriter() = default;

                void update(const Entity &id);
        };
    }

        // class NetworkAddSomeWrite : public ASystem
        // {
        //     public:
        //         NetworkAddSomeWrite() = default;
        //         virtual ~NetworkAddSomeWrite() = default;

        //         void update(const Entity &id) {};
        //         void add(const Entity &id, std::string &message, rtype::component::OpponentNetworkInfo &dest);
        // };

}

#endif