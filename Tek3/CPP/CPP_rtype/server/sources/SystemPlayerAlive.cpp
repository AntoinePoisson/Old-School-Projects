/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemPlayerAlive
*/

#include "systems/PlayerAlive.hpp"
#include "Network.hpp"
#include "singleton/ECManager.hpp"

void rtype::system::PlayerAlive::run(const Entity &id, std::vector<boost::shared_ptr<rtype::OOP::Client>> &squad)
{
    std::string msg;
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::network::CodeActionMssg transfert = {};
    int count = 0;
    std::vector<char> res;
    struct rtype::network::DeleteComponentMssg del = {0};

    for (auto &el : squad) {
        msg = el->receivePacket();
        std::memcpy(&transfert, msg.data(), sizeof(rtype::network::CodeActionMssg));
        if ((msg.size() && transfert.type == rtype::network::MessageTypeClient::CODE_ACTION &&
            transfert.action == rtype::network::CodeAction::QUIT) || (el->getSocket().is_open() == false)) {
            el->setStatus(rtype::OOP::stateClient_e::QUIT);
        }
        if (el->getStatus() == rtype::OOP::stateClient_e::QUIT) {
            // el->disconnect();
            if (handler.getComponent<rtype::component::ListClientNetwork>(id)._list.size() > count)
                handler.getComponent<rtype::component::Life>(handler.getComponent<rtype::component::ListClientNetwork>(id)._list[count].first)._life = 0;
        }
        count += 1;
    }
    count = 0;
    for (auto el = handler.getComponent<rtype::component::ListClientNetwork>(id)._list.begin(); handler.getComponent<rtype::component::ListClientNetwork>(id)._list.size() && el != handler.getComponent<rtype::component::ListClientNetwork>(id)._list.end(); el++) {
        if (handler.getComponent<rtype::component::Life>(el->first)._life <= 0) {
            std::strcpy(del.uuid, el->first.data());
            del.type = rtype::network::MessageTypeServer::DELETE_CPT;
            del.mask_bitset = rtype::idBitset::idPosition + rtype::idBitset::idLife + rtype::idBitset::idType;
            res.clear();
            res.resize(sizeof(struct rtype::network::DeleteComponentMssg));
            memcpy(res.data(), &del, sizeof(struct rtype::network::DeleteComponentMssg));
            for (auto &client : handler.getComponent<rtype::component::ListClientNetwork>(id)._list) {
                rtype::system::NetworkWrite().send(id, std::make_pair(std::string(res.begin(), res.end()), client.second));
            }
            rtype::network::EndGameMssg StructData = {0};
            StructData.has_won = false;
            StructData.type = rtype::network::MessageTypeServer::ENDGAME;
            std::vector<char> msg(sizeof(struct rtype::network::EndGameMssg));
            memcpy(msg.data(), &StructData, sizeof(struct rtype::network::EndGameMssg));
            rtype::system::NetworkWrite().send(id, std::make_pair(std::string(msg.begin(), msg.end()), el->second));

            (squad.begin() + count)->get()->sendPacket(std::string(msg.begin(), msg.end()));

            handler.deleteEntity(el->first);
            handler.getComponent<rtype::component::ListClientNetwork>(id)._list.erase(el);
            if (el != handler.getComponent<rtype::component::ListClientNetwork>(id)._list.begin())
                el--;
            (squad.begin() + count)->get()->disconnect();
            squad.erase(squad.begin() + count);
            std::cout << "[Game]: Disconnected Player." << std::endl;
        }
        count += 1;
    }
}
