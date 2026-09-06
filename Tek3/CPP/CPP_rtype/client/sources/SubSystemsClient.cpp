/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SubSystem
*/

#include "SubSystemsClient.hpp"
#include "MediatorClient.hpp"
#include "singleton/ECManager.hpp"
#include "systems/Network.hpp"
#include "systems/Audio.hpp"
#include "components/Events.hpp"
#include "components/Type.hpp"
#include "components/Scene.hpp"
#include "Network.hpp"

void rtype::subsystem::EventHandler::update(const Entity &id)
{
    this->handleKeyboard(id);
    this->handleMouse(id);
}

void rtype::subsystem::EventHandler::handleKeyboard(const Entity &id)
{
    rtype::entity::ComponentManager &ecMan = rtype::singleton::ECManager::get();
    rtype::component::KeyboardEvent &event = ecMan.getComponent<rtype::component::KeyboardEvent>(id);
    auto sender = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageSendClient>();
    auto queue = sender.second;
    rtype::client::Mediator &med = rtype::client::Mediator::get();

    for (auto &key : event._keys) {
        if (key & 31 && ecMan._cMan.getComponentFromType<rtype::component::Scene>().second->_scene == rtype::client::scenes::GAME) {
            std::cout << "[CLIENT]: [SYSTEM]: [SUBSYSTEMSCLIENT]: [HANDLEKEYBOARD]: event = " << key << std::endl;
            queue->_messages.push(getCodeActionMssgString(0, key));
            // med.mediate(sender.first);
            auto sockUDP = ecMan._cMan.getComponentFromType<rtype::component::Socket>();
            med.mediate(sockUDP.first);
        } else if (key & rtype::component::keyboardEventType::QUIT) {
            if (ecMan._cMan.getComponentFromType<rtype::component::SocketTCP>().second->_socket.is_open()) {
                queue->_messages.push(getCodeActionMssgString(0, key));
                med.mediate(sender.first);
            }

            ecMan._cMan.getComponentFromType<rtype::component::Scene>().second->_scene = rtype::client::scenes::QUIT;
            std::cerr << "[CLIENT]: [SYSTEM]: [SUBSYSTEMSCLIENT]: [HANDLEKEYBOARD]: QUIT" << std::endl;
        }
    }
}

void rtype::subsystem::EventHandler::handleMouse(const Entity &id)
{
    auto &ecMan = rtype::singleton::ECManager::get();
    auto &mouse = ecMan.getComponent<rtype::component::MouseEvent>(id);

    for (auto &pos : mouse._pos) {
        auto buttons = ecMan._cMan.getComponentsFromType<rtype::component::ButtonAction>();
        // std::cerr << "LEN MOUSE POS : " << mouse._pos.size() << std::endl;

        for (auto &button : buttons) {
            auto &surf = ecMan.getComponent<rtype::component::Surface>(button.first);
            auto &cPos = ecMan.getComponent<rtype::component::Position>(button.first);

            // std::cerr << "button.first : " << button.first << std::endl;
            // std::cerr << "button x : " << cPos._x << " y : " << cPos._y << std::endl;
            // std::cerr << "button width : " << cPos._x + surf._width << " height : " << cPos._x + surf._height << std::endl;
            if (pos.x < cPos._x + surf._width && pos.x > cPos._x
                    && pos.y < cPos._y + surf._height && pos.y > cPos._y)
                this->handleButtonAction(button.first);
        }
    }
}

void rtype::subsystem::EventHandler::handleButtonAction(const Entity &id)
{
    rtype::entity::ComponentManager &ecMan = rtype::singleton::ECManager::get();
    auto sender = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageSendClient>();
    // auto sender = ecMan._cMan.getComponentFromType<rtype::component::Socket>();
    auto socket = ecMan._cMan.getComponentFromType<rtype::component::SocketTCP>();
    auto queue = sender.second;
    auto &buttonAction = ecMan.getComponent<rtype::component::ButtonAction>(id);
    rtype::client::Mediator &med = rtype::client::Mediator::get();

    if (buttonAction._action <= rtype::component::buttonAction::PLAY4) {
        std::cerr << "[CLIENT]: [SYSTEM]: [SUBSYSTEMSCLIENT]: [HANDLEBUTTONACTION]: action = PLAY, nb player = " << buttonAction._action << std::endl;
        auto socket = ecMan._cMan.getComponentFromType<rtype::component::SocketTCP>();
        auto endP = ecMan._cMan.getComponentFromType<rtype::component::ServerEndpoints>();

        if (socket.second->_socket.is_open())
            return;
        socket.second->_socket.open(boost::asio::ip::tcp::v4());
        // std::cout << endP.second->_tcp_addr << "@" << endP.second->_tcp_port << std::endl;
        socket.second->_socket.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(endP.second->_tcp_addr), endP.second->_tcp_port));
        queue->_messages.push(getCodeActionMssgString(buttonAction._action, rtype::network::CodeAction::PLAY));
        med.mediate(socket.first);
    } else if (buttonAction._action == rtype::component::buttonAction::QUITGAME) {
        std::cerr << "[CLIENT]: [SYSTEM]: [SUBSYSTEMSCLIENT]: [HANDLEBUTTONACTION]: action = QUITGAME" << std::endl;
        queue->_messages.push(getCodeActionMssgString(0, rtype::network::CodeAction::QUIT));
        med.mediate(socket.first);
        auto sender = ecMan._cMan.getComponentFromType<rtype::component::Scene>();
        sender.second->_scene = rtype::client::scenes::MENU;

        auto queue1 = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageSendClient>();
        auto queue2 = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageRecvClient>();

        //empty queues
        while (!queue1.second->_messages.empty())
            queue1.second->_messages.pop();
        while (!queue2.second->_messages.empty())
            queue2.second->_messages.pop();

        socket.second->_socket.close();
        //clear message queue
    } else if (buttonAction._action == rtype::component::buttonAction::QUITPRGM) {
        std::cerr << "[CLIENT]: [SYSTEM]: [SUBSYSTEMSCLIENT]: [HANDLEBUTTONACTION]: action = QUITPRGM" << std::endl;
        queue->_messages.push(getCodeActionMssgString(0, rtype::network::CodeAction::QUIT));
        med.mediate(socket.first);

        auto sender = ecMan._cMan.getComponentFromType<rtype::component::Scene>();
        sender.second->_scene = rtype::client::scenes::QUIT;
    } else if (buttonAction._action == rtype::component::buttonAction::VOLPLUS) {
        std::cerr << "[CLIENT]: [SYSTEM]: [SUBSYSTEMSCLIENT]: [HANDLEBUTTONACTION]: action = VOLPLUS" << std::endl;
        handleVolume(id, true);
    } else if (buttonAction._action == rtype::component::buttonAction::VOLMINUS) {
        std::cerr << "[CLIENT]: [SYSTEM]: [SUBSYSTEMSCLIENT]: [HANDLEBUTTONACTION]: action = VOLMINUS" << std::endl;
        handleVolume(id, false);
    }
}

// #include <ctime>
// #include <iostream>
std::string rtype::subsystem::EventHandler::getCodeActionMssgString(int player, int actionId)
{
    rtype::network::CodeActionMssg caMsg {.timestamp = std::time(nullptr),
                                          .nb_player = player,
                                          .action = actionId};
    void *voidMsg = static_cast<void *>(&caMsg);
    std::string msg(static_cast<char *>(voidMsg), sizeof(rtype::network::CodeActionMssg));

    return (msg);
}

void rtype::subsystem::EventHandler::handleVolume(const Entity &id, bool plus)
{
    rtype::entity::ComponentManager &ecMan = rtype::singleton::ECManager::get();
    rtype::system::Audio audio(ecMan);
    auto vol = ecMan._cMan.getComponentFromType<rtype::component::GlobalVolume>();

    if (plus) {
        if (vol.second->_volume == 100 || vol.second->_volume + 10 > 100)
            return;
        audio.setVolumeAll(id, vol.second->_volume += 10);
    } else {
        if (vol.second->_volume == 0 || vol.second->_volume - 10 < 0)
            return;
        audio.setVolumeAll(id, vol.second->_volume -= 10);
    }
}

// void rtype::subsystem::NetworkRead::update(const Entity &id)
// {
//     rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

//     rtype::system::NetworkRead().update(id);
//     handler.removeComponent<rtype::component::TempRead>(id);
// }

// void rtype::subsystem::NetworkAddSomeWrite::update(const Entity &id)
// {
//     rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
//     rtype::component::TempWrite a = handler.getComponent<rtype::component::TempWrite>(id);

//     rtype::system::NetworkAddSomeWrite().add(id, a._message, a._endpoint);
//     handler.removeComponent<rtype::component::TempWrite>(id);
// }
