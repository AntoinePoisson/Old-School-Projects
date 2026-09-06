/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Server
*/

#ifndef SERVERSERVER_HPP_
#define SERVERSERVER_HPP_

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <queue>
#include "AException.hpp"
#include "systems/Network.hpp"
#include "systems/NetworkServer.hpp"

#define COLLISION_ENABLE true

#define MAP_HEIGHT 800
#define MAP_WIDTH 1920

#define PLAYER_SPEED 20
#define PLAYER_INIT_X 100
#define PLAYER_INIT_Y 100
#define PLAYER_INIT_LIFE 100
#define PLAYER_HEIGHT 32
#define PLAYER_WIDTH 68

#define SPEED_BULLET 1500 // pixel/secondes
#define MONSTER_LIFE 100

#define MONSTER_INIT_NBR 2
#define MONSTER_MAX_NBR 16

#define MONSTER1_LIFE 100
#define MONSTER1_SPEED 6

#define MONSTER_HEIGHT1 180
#define MONSTER_WIDTH1 150
#define MONSTER_DMG1 15

#define MONSTER_HEIGHT2 102
#define MONSTER_WIDTH2 84
#define MONSTER_DMG2 25

#define MONSTER_HEIGHT3 99
#define MONSTER_WIDTH3 100
#define MONSTER_DMG3 75

#define MONSTER_HEIGHT4 100
#define MONSTER_WIDTH4 112
#define MONSTER_DMG4 100

#define BULLET_HEIGHT1 17
#define BULLET_WIDTH1 16
#define BULLET_DMG1 25

#define BULLET_HEIGHT2 34
#define BULLET_WIDTH2 34
#define BULLET_DMG2 50

#define BULLET_HEIGHT3 66
#define BULLET_WIDTH3 34
#define BULLET_DMG3 75

#define BULLET_HEIGHT4 18
#define BULLET_WIDTH4 16
#define BULLET_DMG4 100


namespace rtype {
    namespace OOP {

        class HandleCtrlC : public rtype::AException {
            public:
                HandleCtrlC(const std::string &str_error, const std::string &componentName = "Ctrl C", unsigned int valueThrow = 0)
                    : rtype::AException(str_error, componentName, valueThrow) {};
        };

        enum stateClient_e {
            WAIT = 0,
            QUIT = 1,
            SOLO = 11,
            DUO = 12,
            TRIO = 13,
            QUAD = 14,
            INGAME = 20,
        };

        class Client {
            private:
                boost::asio::ip::tcp::socket _sock;
                bool _turnOn;
                std::string _buffRead;
                std::string _buffWrite;
                std::queue<std::string> _receiveQ;
                std::queue<std::string> _sendQ;
                stateClient_e _status;

                void openAsyncRead(void);
                void handlerRead(const boost::system::error_code& error, std::size_t size, std::shared_ptr<std::string> msg);
                void openAsyncWrite(void);
                void handlerWrite(const boost::system::error_code& error, std::size_t size);

            public:
                Client(boost::asio::io_service &io_service);
                ~Client();

                static boost::shared_ptr<rtype::OOP::Client> createClient(boost::asio::io_service &io_service) {
                    return (boost::shared_ptr<Client> (new Client(io_service)));
                }
                void connection(void);
                void disconnect(void);
                std::string receivePacket(void);
                void sendPacket(std::string packet);
                int getStatus(void) const;
                void setStatus(stateClient_e status);
                boost::asio::ip::tcp::socket &getSocket(void) {
                    return _sock;
                }
        };

        class Server {
            private:
                static void createPlayers(const rtype::entity::Entity &entityId);
                void acceptConnection(void);
                void handlerAddClient(boost::shared_ptr<rtype::OOP::Client> &connect, const boost::system::error_code& err);
                void handleClientCommand(std::string message, boost::shared_ptr<rtype::OOP::Client> &client);
                void checkCreateParty(int nbr);
                static void runnerParty(std::vector<boost::shared_ptr<rtype::OOP::Client>> &squad);

                std::vector<boost::shared_ptr<rtype::OOP::Client>> _listClient;
                boost::asio::io_service _ioService;
                boost::asio::ip::tcp::acceptor _accept;
            public:
                Server(const std::string &ip);
                Server(const std::string &ip, int port);
                Server();
                ~Server();

                static rtype::entity::Entity getPlayerByEndpoint(const rtype::component::OpponentNetworkInfo& endpoint);
                void run(void);

                static boost::asio::ip::tcp::endpoint &getEnpoint(boost::asio::ip::tcp::endpoint info) {
                    static boost::asio::ip::tcp::endpoint save = info;
                    return (save);
                }

                static std::vector<boost::thread *> &getListThread(void) {
                    static std::vector<boost::thread *> res;
                    return (res);
                }
        };
    }
}

#endif /* !SERVERSERVER_HPP_ */
