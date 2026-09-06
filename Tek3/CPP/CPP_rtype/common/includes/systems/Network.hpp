/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System Network
*/

#ifndef COMMONSYSTEMNETWORK_HPP_
#define COMMONSYSTEMNETWORK_HPP_

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "components/Network.hpp"
#include "entities/ComponentManager.hpp"
#include "systems/ASystem.hpp"

namespace rtype {
    namespace system {

        //use code action in common/includes/Network
        // typedef struct codeAction_s {
        //     int type;
        //     time_t timestamp;
        //     int nb_player;
        //     int action;
        // } codeAction_t;

        class NetworkRead : public ASystem
        {
            private:
                void handlerRead(const boost::system::error_code& err, std::size_t size, Entity _idEntity, std::shared_ptr<boost::asio::ip::udp::endpoint> _endpoint, std::shared_ptr<std::string> _buff);

            public:
                NetworkRead() = default;
                virtual ~NetworkRead() = default;

                void update(const Entity &e);
                void openAsyncRead(const Entity &id);
        };

        class NetworkWrite : public ASystem
        {
            private:
                void handlerWrite(const boost::system::error_code& err, std::size_t size, Entity _idEntity);
                void useless(const boost::system::error_code& err, std::size_t size);

            public:
                NetworkWrite() = default;
                virtual ~NetworkWrite() = default;

                void update(const Entity &id);
                void send(const Entity &id, std::pair<std::string, rtype::component::OpponentNetworkInfo> msg);
        };

        class NetworkAddSomeWrite : public ASystem
        {
            public:
                NetworkAddSomeWrite() = default;
                virtual ~NetworkAddSomeWrite() = default;

                void update(const Entity &id) {};
                void add(const Entity &id, std::string &message, rtype::component::OpponentNetworkInfo &dest);
        };

    }
}

#endif /* !COMMONSYSTEMNETWORK_HPP_ */
