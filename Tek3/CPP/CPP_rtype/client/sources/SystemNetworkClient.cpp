/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemNetworkClient
*/

#include "MediatorClient.hpp"
#include "singleton/ECManager.hpp"

#include "systems/NetworkClient.hpp"

#include "components/Physics.hpp"
#include "components/Life.hpp"
#include "components/Display.hpp"
#include "components/TempComponents.hpp"
#include "components/Sound.hpp"


void rtype::system::StartNetworkClient::update(const Entity &id)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [STARTNETWORKCLIENT]: update" << std::endl;
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    std::shared_ptr<rtype::component::IOService> io(new rtype::component::IOService);
    std::shared_ptr<rtype::component::Socket> sock(new rtype::component::Socket(io->_ioService));
    std::shared_ptr<rtype::component::OpponentNetworkInfo> oppNetworkInfo(new rtype::component::OpponentNetworkInfo(boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 0})); // Juste pour init
    rtype::component::QueueMessageReceive queueReceive;
    rtype::component::QueueMessageSend queueSend;
    rtype::component::TempRead a;
//    rtype::Mediator med = rtype::Mediator::get();

    sock->_socket.open(boost::asio::ip::udp::v4());
    std::shared_ptr<rtype::component::MyNetworkInfo> myNetworkInfo(new rtype::component::MyNetworkInfo(sock->_socket.local_endpoint()));
    std::cout << "[Start]: Client send to : " << oppNetworkInfo->_endpoint.address().to_string() << "@" << oppNetworkInfo->_endpoint.port() << std::endl;
    std::cout << "[Start]: Client info to : " << myNetworkInfo->_endpoint.address().to_string() << "@" << myNetworkInfo->_endpoint.port() << std::endl;
    handler.addComponent(id, io);
    handler.addComponent(id, sock);
    handler.addComponent(id, myNetworkInfo);
    handler.addComponent(id, oppNetworkInfo);
    handler.addComponent(id, queueReceive);
    handler.addComponent(id, queueSend);
    // handler.addTempComponent(id, a);
    // handler._eMan._tempEntities[id] = TempSignature(idRead);
    // med.mediate(id);
    // MEDIATOR NETWORKREAD
}

void rtype::system::CloseNetworkClient::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    handler.getComponent<rtype::component::Socket>(id)._socket.close();
    handler.getComponent<rtype::component::IOService>(id)._ioService.stop();
    handler.removeComponent<rtype::component::IOService>(id);
    handler.removeComponent<rtype::component::Socket>(id);
    handler.removeComponent<rtype::component::MyNetworkInfo>(id);
    handler.removeComponent<rtype::component::OpponentNetworkInfo>(id);
    handler.removeComponent<rtype::component::QueueMessageReceive>(id);
    handler.removeComponent<rtype::component::QueueMessageSend>(id);
    std::cout << "[Stop]: Client Network Close." << std::endl;
}

rtype::subsystem::InterpretNetworkClient::InterpretNetworkClient()
{
    std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: CTOR" << std::endl;
    _font = "../assets/Roboto-Bold.ttf";//replace

    _imageFile.insert({rtype::component::PLAYERBLUE, (rtype::client::Image){rtype::component::drawOrder::SECOND, .path="../assets/images/used/PlayerBlue1.png", 0, 0}});
    _imageFile.insert({rtype::component::PLAYERGREEN, (rtype::client::Image){rtype::component::drawOrder::SECOND, .path="../assets/images/used/PlayerGreen1.png", 0, 0}});
    _imageFile.insert({rtype::component::PLAYERPURPLE, (rtype::client::Image){rtype::component::drawOrder::SECOND, .path="../assets/images/used/PlayerPurple1.png", 0, 0}});
    _imageFile.insert({rtype::component::PLAYERRED, (rtype::client::Image){rtype::component::drawOrder::SECOND, .path="../assets/images/used/PlayerRed1.png", 0, 0}});
    _imageFile.insert({rtype::component::MONSTER1, (rtype::client::Image){rtype::component::drawOrder::SECOND, .path="../assets/images/used/Enemy1.png", 0, 0}});
    _imageFile.insert({rtype::component::MONSTER2, (rtype::client::Image){rtype::component::drawOrder::SECOND, .path="../assets/images/used/Enemy2.png", 0, 0}});
    _imageFile.insert({rtype::component::MONSTER3, (rtype::client::Image){rtype::component::drawOrder::SECOND, .path="../assets/images/used/Enemy3.png", 0, 0}});
    _imageFile.insert({rtype::component::MONSTER4, (rtype::client::Image){rtype::component::drawOrder::SECOND, .path="../assets/images/used/Enemy4.png", 0, 0}});
    _imageFile.insert({rtype::component::BULLET5, (rtype::client::Image){rtype::component::drawOrder::SECOND, .path="../assets/images/used/Bullet5.png", 0, 0}});
    
    _imageFile.insert({rtype::component::DEFEAT, (rtype::client::Image){rtype::component::drawOrder::THIRD, .path="../assets/images/used/loose.png", 700, 100}});
    _imageFile.insert({rtype::component::VICTORY, (rtype::client::Image){rtype::component::drawOrder::THIRD, .path="../assets/images/used/victory.png", 700, 100}});


    _spriteSheetFile.insert({rtype::component::BULLET1, (rtype::client::SpriteSheet){0, 0, "../assets/images/used/Bullet111.png", rtype::component::drawOrder::THIRD, std::chrono::system_clock::now(), 17, 6, std::chrono::milliseconds{50}, true, 17, 16}});
    _spriteSheetFile.insert({rtype::component::BULLET2, (rtype::client::SpriteSheet){0, 0, "../assets/images/used/Bullet2.png", rtype::component::drawOrder::THIRD, std::chrono::system_clock::now(), 34, 3, std::chrono::milliseconds{50}, true, 34, 34}});
    _spriteSheetFile.insert({rtype::component::BULLET3, (rtype::client::SpriteSheet){0, 0, "../assets/images/used/Bullet41.png", rtype::component::drawOrder::THIRD, std::chrono::system_clock::now(), 18, 16, std::chrono::milliseconds{50}, true, 18, 16}});
    _spriteSheetFile.insert({rtype::component::BULLET4, (rtype::client::SpriteSheet){0, 0, "../assets/images/used/Bullet31.png", rtype::component::drawOrder::THIRD, std::chrono::system_clock::now(), 66, 8, std::chrono::milliseconds{50}, true, 66, 34}});


    // _textFile.insert({rtype::component::PLAYERRED, (rtype::client::Text){.path="../assets/Roboto-Bold.ttf", 50, 50 "Player : red", 24, sf::Color::White, sf::Text::Regular}});// replace

    _musicFile.insert({rtype::component::BULLET1, (rtype::client::Audio){.path="../assets/musics/samples/boom.ogg", true, false, 0, 100}});
    _musicFile.insert({rtype::component::BULLET2, (rtype::client::Audio){.path="../assets/musics/samples/shoot.wav", true, false, 0, 100}});
    _musicFile.insert({rtype::component::BULLET3, (rtype::client::Audio){.path="../assets/musics/pew-pew.ogg", true, false, 0, 100}});
    _musicFile.insert({rtype::component::BULLET4, (rtype::client::Audio){.path="../assets/musics/pew-pew.ogg", true, false, 0, 100}});
    _musicFile.insert({rtype::component::BULLET5, (rtype::client::Audio){.path="../assets/musics/pew-pew.ogg", true, false, 0, 100}});


}

void rtype::subsystem::InterpretNetworkClient::update(const Entity &id)
{
    rtype::entity::ComponentManager &ecMan = rtype::singleton::ECManager::get();
    auto pair = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageRecvClient>();
    std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: update" << std::endl;

    while (!pair.second->_messages.empty()) {
        std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: update: msg type = " << pair.second->_messages.front().first << std::endl;
        if (pair.second->_messages.front().first == rtype::network::ENDPOINT_S)
            this->handleEndPointMssg(pair.second->_messages.front().second);
        else if (pair.second->_messages.front().first == rtype::network::ENDGAME)
            this->handleEndMssg(pair.second->_messages.front().second);
        else if (pair.second->_messages.front().first == rtype::network::DELETE_CPT)
            this->handleDeleteCptMssg(pair.second->_messages.front().second);
        else if (pair.second->_messages.front().first == rtype::network::DISPLAY_REFRESH)
            this->handleRefreshMssg(pair.second->_messages.front().second);
        // add codeAction message quit ?
        pair.second->_messages.pop();
    }
}

void rtype::subsystem::InterpretNetworkClient::handleEndPointMssg(const std::string &msg)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: handleEndPointMssg" << std::endl;
    if (!msg.size())
        return;
    rtype::entity::ComponentManager &ecMan = rtype::singleton::ECManager::get();
    rtype::client::Mediator &med = rtype::client::Mediator::get();


    //get server endpoint
    rtype::network::EndpointMssg endPointFromServer = {};
    auto endP = ecMan._cMan.getComponentFromType<rtype::component::ServerEndpoints>();
    char *edp = static_cast<char *>(static_cast<void *>(&endPointFromServer));
    std::memcpy(edp + sizeof(int), msg.data(), sizeof(rtype::network::EndpointMssg) - sizeof(int));
    // std::memcpy(&endPointFromServer + sizeof(int), msg.data(), sizeof(rtype::network::EndpointMssg) - sizeof(int));
    endP.second->_udp_addr = std::string(endPointFromServer.addr);
    endP.second->_udp_port = endPointFromServer.port;
    std::cerr << "endP.second->_udp_addr = " << endP.second->_udp_addr << std::endl;
    std::cerr << "endP.second->_udp_port = " << endP.second->_udp_port << std::endl;



    //create endpoint client
    std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: handleEndPointMssg endpoint client" << std::endl;
    auto socketP = ecMan._cMan.getComponentFromType<rtype::component::Socket>();
    rtype::network::EndpointMssg endPointClient = {.port = socketP.second->_socket.local_endpoint().port()};
    std::string addr = socketP.second->_socket.local_endpoint().address().to_string();
    memcpy(endPointClient.addr, addr.data(), addr.size());
    void *voidMsg = static_cast<void *>(&endPointClient);
    std::string mssg(static_cast<char *>(voidMsg), sizeof(rtype::network::EndpointMssg));
    ecMan._cMan.getComponentFromType<rtype::component::QueueMessageSendClient>().second->_messages.push(mssg);
    med.mediate(ecMan._cMan.getComponentFromType<rtype::component::SocketTCP>().first);



    //update scene
    std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: handleEndPointMssg change scene" << std::endl;
    auto sender = ecMan._cMan.getComponentFromType<rtype::component::Scene>();
    sender.second->_scene = rtype::client::scenes::GAME;
}

void rtype::subsystem::InterpretNetworkClient::handleEndMssg(const std::string &msg)
{
    std::cout << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: handleEndMssg" << std::endl;
    if (!msg.size())
        return;
    rtype::entity::ComponentManager &ecMan = rtype::singleton::ECManager::get();
    rtype::client::Mediator &med = rtype::client::Mediator::get();
    rtype::network::EndGameMssg end = {};
    Entity uuid = ecMan._eMan.createEntity();

    char *edp = static_cast<char *>(static_cast<void *>(&end));
    std::memcpy(edp + sizeof(int), msg.data(), sizeof(rtype::network::EndGameMssg) - sizeof(int));
    if (end.has_won == true)
        this->updateImageTextSound(uuid, rtype::component::componentType::VICTORY);
    else
        this->updateImageTextSound(uuid, rtype::component::componentType::DEFEAT);
    //component EndGame
    // auto pair = ecMan._cMan.getComponentFromType<rtype::component::EndGame>();
    //fill endGame (tableau score)
    // med.update(pair.first);
}

void rtype::subsystem::InterpretNetworkClient::handleDeleteCptMssg(const std::string &msg)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: handleDeleteCptMssg" << std::endl;
    if (!msg.size())
        return;
    rtype::entity::ComponentManager &ecMan = rtype::singleton::ECManager::get();
    rtype::network::DeleteComponentMssg del = {0};

    char *edp = static_cast<char *>(static_cast<void *>(&del));
    std::memcpy(edp + sizeof(int), msg.data(), sizeof(rtype::network::DeleteComponentMssg) - sizeof(int));
    std::string uuid(del.uuid, 36);

    Signature sig;
    std::cout << "delete component " << uuid << std::endl;
    try {
        sig = ecMan._eMan.getSignature(uuid);
    } catch (const rtype::entity::Exception &e) {
        std::cerr << "Failed to get entity in delete cpt mssg" << std::endl;
        return;
    }
    // std::cout << ecMan.getComponent<rtype::component::Position>(uuid)._x << std::endl;
    Signature res = sig ^ Signature(idSprite); //remove sprite id
    //& serverId if they send us server's component in addition of what they should receive

    if (res.to_ullong() == del.mask_bitset) {
        ecMan.deleteEntity(uuid);
    } else {
        this->deleteComponentsHelper(uuid, res);
        // ecMan.removeComponent(std::string(del.uuid), del.mask_bitset);
    }
}

int rtype::subsystem::InterpretNetworkClient::deleteComponentsHelper(const Entity &id, const Signature &sig)
{
    rtype::entity::ComponentManager &ecMan = rtype::singleton::ECManager::get();

    if ((sig & Signature(rtype::idBitset::idPosition)).count() == 1) {
        ecMan.removeComponent<rtype::component::Position>(id);
    }
    if ((sig & Signature(rtype::idBitset::idLife)).count() == 1) {
        ecMan.removeComponent<rtype::component::Life>(id);
    }
    if ((sig & Signature(rtype::idBitset::idType)).count() == 1) {
        ecMan.removeComponent<rtype::component::Type>(id);
    }
    if ((sig & Signature(rtype::idBitset::idDestination)).count() == 1) {
        ecMan.removeComponent<rtype::component::Destination>(id);
    }
    if ((sig & Signature(rtype::idBitset::idStartingTime)).count() == 1) {
        ecMan.removeComponent<rtype::component::StartingTime>(id);
    }
    if ((sig & Signature(rtype::idBitset::idSpeed)).count() == 1) {
        ecMan.removeComponent<rtype::component::Speed>(id);
    }
    if ((sig & Signature(rtype::idBitset::idStartCriteria)).count() == 1) {
        ecMan.removeComponent<rtype::component::StartCriteria>(id);
    }
    return (0);
}

void rtype::subsystem::InterpretNetworkClient::handleRefreshMssg(const std::string &msg)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: handleRefreshMssg" << std::endl;
    if (!msg.size())
        return;
    rtype::entity::ComponentManager &ecMan = rtype::singleton::ECManager::get();
    rtype::client::Mediator &med = rtype::client::Mediator::get();
    rtype::network::DisplayRefreshMssg entity = {};
    char *edp = static_cast<char *>(static_cast<void *>(&entity));
    std::memcpy(edp + sizeof(int), msg.data(), sizeof(rtype::network::DisplayRefreshMssg) - sizeof(int));
    // std::cout << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: handleRefreshMssg: entity bitset = " << entity.mask_bitset << std::endl;
    std::map<rtype::idBitset, std::shared_ptr<rtype::component::AComponent>> newComp = getComponentFromMessage(std::string(entity.message, 2000), entity.mask_bitset);
    std::string uuid(entity.uuiid, 36);
    bool created = false;
    std::shared_ptr<rtype::component::AComponent> tmp;
    auto enities = ecMan._eMan.getEntities(); 

    if (enities.find(uuid) == enities.end()) {
        ecMan._eMan.createEntity(uuid);
        created = true;
    }
    std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: handleRefreshMssg: UUID = " << uuid << std::endl;
    if (entity.mask_bitset & idPosition) {
        std::cerr << "POS" << std::endl;
        std::shared_ptr<rtype::component::Position> newPos(std::dynamic_pointer_cast<rtype::component::Position>(newComp[idPosition]));
        // std::cerr << "x = " << newPos->_x << std::endl;
        // std::cerr << "y = " << newPos->_y << std::endl;

        if (!created) {
            rtype::component::Position &pos = ecMan.getComponent<rtype::component::Position>(uuid);

            // std::cerr << "OLD X = " << pos._x << std::endl;
            // std::cerr << "OLD Y = " << pos._y << std::endl;
            pos._x = newPos->_x;
            pos._y = newPos->_y;
            // std::cerr << "ENTITY NOT CREATED NEW X = " << pos._x << std::endl;
            // std::cerr << "ENTITY NOT CREATED NEW Y = " << pos._y << std::endl;
        } else {
            rtype::component::Position pos(newPos->_x, newPos->_y);

            ecMan.addComponent(uuid, pos);
        }
    }
    if (entity.mask_bitset & idDestination) {
        std::cerr << "DEST" << std::endl;
        std::shared_ptr<rtype::component::Destination> newDest(std::dynamic_pointer_cast<rtype::component::Destination>(newComp[idDestination]));
        // std::cerr << "x = " << newDest->_x << std::endl;
        // std::cerr << "y = " << newDest->_y << std::endl;

        if (!created) {
            rtype::component::Destination &dest = ecMan.getComponent<rtype::component::Destination>(uuid);

            dest._x = newDest->_x;
            dest._y = newDest->_y;
        } else {
            rtype::component::Destination dest(newDest->_x, newDest->_y);

            ecMan.addComponent(uuid, dest);
        }
    }
    if (entity.mask_bitset & idStartingTime) {
        std::cerr << "STARTING TIME" << std::endl;
        std::shared_ptr<rtype::component::StartingTime> newStartingTime(std::dynamic_pointer_cast<rtype::component::StartingTime>(newComp[idStartingTime]));
        std::cerr << "startingTime = " << std::chrono::system_clock::to_time_t(newStartingTime->_startAt) << std::endl;

        if (!created) {
            rtype::component::StartingTime &startingTime = ecMan.getComponent<rtype::component::StartingTime>(uuid);

            startingTime._startAt = newStartingTime->_startAt;
        } else {
            rtype::component::StartingTime startingTime(newStartingTime->_startAt);

            ecMan.addComponent(uuid, startingTime);
        }
    }
    if (entity.mask_bitset & idSpeed) {
        std::cerr << "SPEED" << std::endl;
        std::shared_ptr<rtype::component::Speed> newSpeed(std::dynamic_pointer_cast<rtype::component::Speed>(newComp[idSpeed]));
        std::cerr << "speed = " << newSpeed->_speed << std::endl;

        if (!created) {
            rtype::component::Speed &speed = ecMan.getComponent<rtype::component::Speed>(uuid);

            speed._speed = newSpeed->_speed;
        } else {
            rtype::component::Speed speed(newSpeed->_speed);

            ecMan.addComponent(uuid, speed);
        }
    }
    if (entity.mask_bitset & idSurface) {
        std::cerr << "SURFACE" << std::endl;
        std::shared_ptr<rtype::component::Surface> newSurface(std::dynamic_pointer_cast<rtype::component::Surface>(newComp[idSurface]));
        std::cerr << "width = " << newSurface->_width << std::endl;
        std::cerr << "height = " << newSurface->_height << std::endl;

        if (!created) {
            rtype::component::Surface &surface = ecMan.getComponent<rtype::component::Surface>(uuid);

            surface._width = newSurface->_width;
            surface._height = newSurface->_height;
        } else {
            rtype::component::Surface surface(newSurface->_width, newSurface->_height);

            ecMan.addComponent(uuid, surface);
        }
    }
    if (entity.mask_bitset & idLife) {
        std::cerr << "LIFE" << std::endl;
        std::shared_ptr<rtype::component::Life> newLife(std::dynamic_pointer_cast<rtype::component::Life>(newComp[idLife]));
        std::cerr << "life = " << newLife->_life << std::endl;

        if (!created) {
            rtype::component::Life &life = ecMan.getComponent<rtype::component::Life>(uuid);

            life._life = newLife->_life;
        } else {
            rtype::component::Life life(newLife->_life);

            ecMan.addComponent(uuid, life);
        }
    }
    if (entity.mask_bitset & idStartCriteria) {
        std::cerr << "START CRITERIA" << std::endl;
        std::shared_ptr<rtype::component::StartCriteria> newStartCriteria(std::dynamic_pointer_cast<rtype::component::StartCriteria>(newComp[idStartCriteria]));

        if (!created) {
            rtype::component::StartCriteria &startCriteria = ecMan.getComponent<rtype::component::StartCriteria>(uuid);

            startCriteria._pos._x = newStartCriteria->_pos._x;
            startCriteria._pos._y = newStartCriteria->_pos._y;
            startCriteria._h = newStartCriteria->_h;
            startCriteria._o = newStartCriteria->_o;
            startCriteria._a = newStartCriteria->_a;
            startCriteria._sin = newStartCriteria->_sin;
            startCriteria._cos = newStartCriteria->_cos;
        } else {
            rtype::component::StartCriteria startCriteria(rtype::component::Position(1, 2), rtype::component::Destination(2, 1));

            startCriteria._pos._x = newStartCriteria->_pos._x;
            startCriteria._pos._y = newStartCriteria->_pos._y;
            startCriteria._h = newStartCriteria->_h;
            startCriteria._o = newStartCriteria->_o;
            startCriteria._a = newStartCriteria->_a;
            startCriteria._sin = newStartCriteria->_sin;
            startCriteria._cos = newStartCriteria->_cos;
            ecMan.addComponent(uuid, startCriteria);
        }
    }
    if (entity.mask_bitset & idType) {
        std::cerr << "TYPE" << std::endl;
        std::shared_ptr<rtype::component::Type> newType(std::dynamic_pointer_cast<rtype::component::Type>(newComp[idType]));
        std::cerr << "type = " << newType->_type << std::endl;

        if (!created) {
            rtype::component::Type &type = ecMan.getComponent<rtype::component::Type>(uuid);

            type._type = newType->_type;
        } else {
            rtype::component::Type type(newType->_type);

            ecMan.addComponent(uuid, type);
        }
        updateImageTextSound(uuid, newType->_type);
        if (newType->_type >= rtype::component::componentType::MONSTER1 &&
            newType->_type <= rtype::component::componentType::MONSTER4 &&
            (ecMan._eMan.getSignature(uuid) & Signature(idTimerMob)).count() == 0) {
            rtype::component::Position &pos = ecMan.getComponent<rtype::component::Position>(uuid);
            rtype::component::TimerMob timer(std::time(nullptr), pos._x, pos._y);

            ecMan.addComponent(uuid, timer);
        }
    }
}

void rtype::subsystem::InterpretNetworkClient::updateImageTextSound(Entity &id, rtype::component::componentType type)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: updateImageTextSound" << std::endl;
    rtype::entity::ComponentManager &ecMan = rtype::singleton::ECManager::get();
    rtype::client::Mediator &med = rtype::client::Mediator::get();
    rtype::client::EntityFactory facto;

    std::cerr << "TYPE = " << type << std::endl;
    if (type >= rtype::component::componentType::BULLET1 &&
        type <= rtype::component::componentType::BULLET5) {
        std::cerr << "SPRITESHEET" << std::endl;
        facto.createSpriteSheet(_spriteSheetFile[type], id);
    } else if (((type >= rtype::component::componentType::PLAYERRED &&
                 type < rtype::component::componentType::BULLET1) &&
               (ecMan._eMan.getSignature(id) & Signature(idSprite)).count() == 0)){
        std::cerr << "SPRITE" << std::endl;
        facto.createImage(_imageFile[type], id);
    } else if (type == rtype::component::componentType::DEFEAT 
        || type == rtype::component::componentType::VICTORY) {
            facto.createSimpleImage(_imageFile[type]);
        }
    if (type == rtype::component::componentType::BULLET5 &&
        (ecMan._eMan.getSignature(id) & Signature(idText)).count() == 0) {
        std::cerr << "TEXT" << std::endl;
        facto.createText(_textFile[type], id);
    }
    if (type >= rtype::component::componentType::BULLET1 &&
        type <= rtype::component::componentType::BULLET5 &&
        ((ecMan._eMan.getSignature(id) & Signature(idMusic)).count() == 0 ||
         (ecMan._eMan.getSignature(id) & Signature(idSound)).count() == 0)) {
        std::cerr << "MUSIC" << std::endl;
        facto.createAudio(_musicFile[type], id);
    }
}

std::shared_ptr<rtype::component::AComponent> rtype::subsystem::getComp(unsigned long &bitset, size_t &index, const std::string &msg)
{
    if (bitset & idPosition) {
        std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComp : idPosition" << std::endl;
        std::string body(msg.data() + index, sizeof(rtype::component::Position));
        rtype::component::Position comp(0, 0);

        std::memcpy(&comp, body.data(), sizeof(rtype::component::Position));
        bitset -= idPosition;
        index += sizeof(rtype::component::Position);
        return (std::make_shared<rtype::component::Position>(comp));
    }
    if (bitset & idDestination) {
        std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComp : idDestination" << std::endl;
        std::string body(msg.data() + index, sizeof(rtype::component::Destination));
        rtype::component::Destination comp(0, 0);

        std::memcpy(&comp, body.data(), sizeof(rtype::component::Destination));
        bitset -= idDestination;
        index += sizeof(rtype::component::Destination);
        return (std::make_shared<rtype::component::Destination>(comp));
    }
    if (bitset & idStartingTime) {
        std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComp : idStartingTime" << std::endl;
        std::string body(msg.data() + index, sizeof(rtype::component::StartingTime));
        rtype::component::StartingTime comp(std::chrono::system_clock::now());

        std::memcpy(&comp, body.data(), sizeof(rtype::component::StartingTime));
        bitset -= idStartingTime;
        index += sizeof(rtype::component::StartingTime);
        return (std::make_shared<rtype::component::StartingTime>(comp));
    }
    if (bitset & idSpeed) {
        std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComp : idSpeed" << std::endl;
        std::string body(msg.data() + index, sizeof(rtype::component::Speed));
        rtype::component::Speed comp(0);

        std::memcpy(&comp, body.data(), sizeof(rtype::component::Speed));
        bitset -= idSpeed;
        index += sizeof(rtype::component::Speed);
        return (std::make_shared<rtype::component::Speed>(comp));
    }
    if (bitset & idSurface) {
        std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComp : idSurface" << std::endl;
        std::string body(msg.data() + index, sizeof(rtype::component::Surface));
        rtype::component::Surface comp(0, 0);

        std::memcpy(&comp, body.data(), sizeof(rtype::component::Surface));
        bitset -= idSurface;
        index += sizeof(rtype::component::Surface);
        return (std::make_shared<rtype::component::Surface>(comp));
    }
    if (bitset & idLife) {
        std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComp : idLife" << std::endl;
        std::string body(msg.data() + index, sizeof(rtype::component::Life));
        rtype::component::Life comp(0);
        
        std::memcpy(&comp, body.data(), sizeof(rtype::component::Life));
        bitset -= idLife;
        index += sizeof(rtype::component::Life);
        return (std::make_shared<rtype::component::Life>(comp));
    }
    if (bitset & idStartCriteria) {
        std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComp : idStartCriteria" << std::endl;
        std::string body(msg.data() + index, sizeof(rtype::component::StartCriteria));
        rtype::component::StartCriteria comp(rtype::component::Position(1, 1), rtype::component::Destination(1, 1));

        std::memcpy(&comp, body.data(), sizeof(rtype::component::StartCriteria));
        bitset -= idStartCriteria;
        index += sizeof(rtype::component::StartCriteria);
        return (std::make_shared<rtype::component::StartCriteria>(comp));
    }
    if (bitset & idType) {
        std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComp : idType" << std::endl;
        std::string body(msg.data() + index, sizeof(rtype::component::Type));
        rtype::component::Type comp((rtype::component::componentType)0);

        std::memcpy(&comp, body.data(), sizeof(rtype::component::Type));
        bitset -= idType;
        index += sizeof(rtype::component::Type);
        return (std::make_shared<rtype::component::Type>(comp));
    }
    std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComp : NULL" << std::endl;
    return (nullptr);
}

std::map<rtype::idBitset, std::shared_ptr<rtype::component::AComponent>> rtype::subsystem::InterpretNetworkClient::getComponentFromMessage(const std::string &msg, unsigned long bitset)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComponentFromMessage" << std::endl;
    if (!msg.size())
        return {};
    // std::map<rtype::idBitset, rtype::component::AComponent> tmp {};
    std::map<rtype::idBitset, std::shared_ptr<rtype::component::AComponent>> newComp {};
    unsigned long lastBitset = bitset;

    for (size_t index = 0; index < msg.size(); ) {
        // std::cerr << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComponentFromMessage" << std::endl;
        std::shared_ptr<rtype::component::AComponent> tmpC(std::dynamic_pointer_cast<rtype::component::AComponent>(getComp(bitset, index, msg)));

        // std::cout << "bitset: " << bitset << std::endl;
        // std::cout << "lastBitset - bitset: " << lastBitset - bitset << std::endl;
        // std::cout << "msg.size(): " << msg.size() << std::endl;
        // std::cout << "index: " << index << std::endl;

        if (tmpC == nullptr) {
            // std::cout << "NULLLLLLLLLLLLLL" << std::endl;
            if (bitset != 0)
                std::cout << "[CLIENT]: [SYSTEM]: [INTERPRETNETWORKCLIENT]: getComponentFromMessage: wrong bitset:" << bitset << std::endl;
            break;
        }
        // std::cout << "INSERT" << std::endl;
        newComp.insert({(rtype::idBitset)(lastBitset - bitset), tmpC});

        // if ((lastBitset - bitset) & idType) {
        //     std::cerr << "TYPE" << std::endl;
        //     std::shared_ptr<rtype::component::Type> type(
        //         std::dynamic_pointer_cast<rtype::component::Type>(newComp[idType]));
        //     std::cerr << "type->_type = " << type->_type << std::endl;
        // }


        lastBitset = bitset;
    }
    return (newComp);
}











int rtype::network::getRemainingSize(int header)
{
    if (header == rtype::network::MessageTypeServer::DISPLAY_REFRESH)
        return sizeof(rtype::network::DisplayRefreshMssg) - sizeof(int);
    if (header == rtype::network::MessageTypeServer::DELETE_CPT)
        return sizeof(rtype::network::DeleteComponentMssg) - sizeof(int);
    if (header == rtype::network::MessageTypeServer::ENDPOINT_S)
        return sizeof(rtype::network::EndpointMssg) - sizeof(int);
    if (header == rtype::network::MessageTypeServer::ENDGAME)
        return sizeof(rtype::network::EndGameMssg) - sizeof(int);
    return (-1);
}

int rtype::network::paquetParser(const std::string &buffer)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    auto pairQueue = handler._cMan.getComponentFromType<rtype::component::QueueMessageRecvClient>();

    const char *buff = buffer.data();
    size_t size = buffer.size();
    size_t index = 0;

    while (index < size) {
        //get headr
        const void *tmp = static_cast<const void *>(buff + index);
        int header = *(static_cast<const int *>(tmp));
        int remains = getRemainingSize(header);
        // std::cout << "header " << header << std::endl;

        if (remains == -1) {
            std::cout << "wrong header type: " << header << std::endl;
            return (-1);
        }

        //get body
        const char *rawbody = buff + index + sizeof(int);
        std::string body(rawbody, remains);
        

        pairQueue.second->_messages.push(std::make_pair(header, body));
        index += remains + sizeof(int);
    }
    return (0);
    // auto &med = rtype::client::Mediator::get();
    // handler._cMan.getComponentFromType<rtype::component::QueueMessageRecvClient>();

    // med.mediate(pairQueue.first);
}
