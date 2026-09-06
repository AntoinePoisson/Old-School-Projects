// #include "singleton/ECManager.hpp"
#include "scene/SceneManager.hpp"

#include "components/Scene.hpp"
#include "components/Network.hpp"
#include "components/Unremovable.hpp"
#include "components/Type.hpp"

#include "RType.hpp"
#include "Network.hpp"

#include <chrono>

rtype::client::SceneManager::SceneManager(const std::string &addr, const short &port)
    : _preserved_entities(new rtype::component::Unremovable)
{
    std::string addrToBindWith = addr;
    if (addr == "localhost")
        addrToBindWith = "127.0.0.1";

    _currentScene = rtype::client::scenes::MENU;
    struct rtype::component::Scene s(rtype::client::scenes::MENU);
    //build entity scene with components
    _sceneId = _ecMan.createEntity(Signature(rtype::idBitset::idScene), s);
    _preserved_entities->entities.push_back(_sceneId);

    Entity id;
    std::shared_ptr<rtype::component::IOService> io(new rtype::component::IOService);
    std::shared_ptr<rtype::component::Socket> sockUDP(new rtype::component::Socket(io->_ioService));
    std::shared_ptr<rtype::component::SocketTCP> sockTCP(new rtype::component::SocketTCP(io->_ioService));

    boost::system::error_code error;

    sockUDP->_socket.open(boost::asio::ip::udp::v4(), error);
    sockUDP->_socket.bind(boost::asio::ip::udp::endpoint{boost::asio::ip::make_address(addr), 0});
    // sockUDP->_socket.bind(boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 0));

    auto edp = sockUDP->_socket.local_endpoint();

    std::cout << "UDP client endpoint: " << edp.address().to_string() << "@" << edp.port() << std::endl;

    id = _ecMan.createEntity(Signature(rtype::idBitset::idIOService), io);
    _preserved_entities->entities.push_back(id);

    id = _ecMan.createEntity(Signature(rtype::idBitset::idSocketTCP), sockTCP);
    _preserved_entities->entities.push_back(id);


    id = _ecMan.createEntity(Signature(rtype::idBitset::idSocket), sockUDP);
    _preserved_entities->entities.push_back(id);

    struct rtype::component::ServerEndpoints sve(addrToBindWith, port);

    id = _ecMan.createEntity(Signature(rtype::idBitset::idServerEndpoints), sve);
    _preserved_entities->entities.push_back(id);


    id = _ecMan.createEntity(Signature(rtype::idBitset::idUnremovable), _preserved_entities);
    _preserved_entities->entities.push_back(id);

    auto queue = std::shared_ptr<rtype::component::QueueMessageSendClient>(new rtype::component::QueueMessageSendClient());
    id = _ecMan.createEntity(Signature(rtype::idBitset::idQueueMessageSendClient), queue);
    _preserved_entities->entities.push_back(id);

    auto queueRcvd = std::shared_ptr<rtype::component::QueueMessageRecvClient>(new rtype::component::QueueMessageRecvClient());
    id = _ecMan.createEntity(Signature(rtype::idBitset::idQueueMessageRecvClient), queueRcvd);
    _preserved_entities->entities.push_back(id);

    //init systemList for Menu and Game
}

void rtype::client::SceneManager::loop()
{
    this->setupSceneSystemLists();
    enum rtype::client::scenes current_scene = rtype::client::scenes::MENU;

    while (1) {
        // std::cout << "getSystem" << std::endl;
        auto &systems = this->getSystems();
        std::cout << "new loop" << std::endl;
        // std::cout << "after get system" << std::endl;
        for (auto sys = systems.begin(); sys != systems.end();) {
            // std::cout << "cococ" << std::endl;
            if (current_scene != this->getCurrentScene()) {
                std::cerr << "IF current_scene != this->getCurrentScene()" << std::endl;
                current_scene = this->getCurrentScene();
                _currentScene = current_scene;
                break;
            }
            (*sys)->update(Entity(_sceneId));
            if (std::next(sys, 1) == systems.end())
                sys = systems.begin();
            else {
                sys++;
            }
        }
        this->clearSceneEntities();
        // systems.clear();
        if (current_scene == rtype::client::scenes::QUIT) {
            std::cout<< "quit programm" << std::endl;
            //end client session
            break;
        }
    }
}

enum rtype::client::scenes rtype::client::SceneManager::getCurrentScene()
{
    auto scnCpt = _ecMan.getComponent<rtype::component::Scene>(this->_sceneId);

    return scnCpt._scene;
}

void rtype::client::SceneManager::clearSceneEntities()
{
    auto entMap = _ecMan._eMan.getEntities();

    for (auto it = entMap.begin(); it != entMap.end(); it++) {
        auto found = std::find(_preserved_entities->entities.begin(), _preserved_entities->entities.end(), it->first);
        if (found == _preserved_entities->entities.end()) {
            _ecMan.deleteEntity(it->first);
        }
    }
}

void rtype::client::SceneManager::setupSceneSystemLists()
{
    std::shared_ptr<rtype::system::Window> window(new rtype::system::Window(_ecMan));
    std::shared_ptr<rtype::system::Audio> audio(new rtype::system::Audio(_ecMan));
    std::shared_ptr<rtype::system::Prediction> pred(new rtype::system::Prediction(_ecMan));
    std::shared_ptr<rtype::system::NetworkTCPReader> netTCP(new rtype::system::NetworkTCPReader());
    std::shared_ptr<rtype::system::NetworkUDPReader> netUDP(new rtype::system::NetworkUDPReader());

    _sysListMenu = {netTCP, window, audio};
    _sysListGame = {netTCP, netUDP, window, audio, pred};

    std::shared_ptr<rtype::subsystem::NetworkTCPWriter> netWrTCP(new rtype::subsystem::NetworkTCPWriter);
    std::shared_ptr<rtype::subsystem::NetworkUDPWriter> netWrUDP(new rtype::subsystem::NetworkUDPWriter);
    std::shared_ptr<rtype::subsystem::EventHandler> event(new rtype::subsystem::EventHandler);
    std::shared_ptr<rtype::subsystem::InterpretNetworkClient> interpreter(new rtype::subsystem::InterpretNetworkClient);
    _subSysList = {netWrTCP, netWrUDP, event, interpreter};
    //tcp = [0]
    //udp = [1]

    auto &med = rtype::client::Mediator::get();

    med.addSubSystem(Signature(rtype::idBitset::idSFMLEvent), event);
    med.addSubSystem(Signature(rtype::idBitset::idQueueMessageRecvClient), interpreter);
    med.addSubSystem(Signature(rtype::idBitset::idSocket), _subSysList[rtype::client::NetworkWriterIndex::UDP]);
    med.addSubSystem(Signature(rtype::idBitset::idSocketTCP), _subSysList[rtype::client::NetworkWriterIndex::TCP]);

}

rtype::client::SystemList &rtype::client::SceneManager::getSystems()
{
    auto &med = rtype::client::Mediator::get();

    if (_currentScene == rtype::client::scenes::GAME) {
        // med.addSubSystem(Signature(rtype::idBitset::idQueueMessageSendClient), _subSysList[rtype::client::NetworkWriterIndex::UDP]);
        //Window, Audio, ButtonSystem(in mediator), clientTCP(in mediator), InterpreterMenu
        this->applySceneEntities();
        return _sysListGame;
    }
    // else menu
    //if  (_currentScene == rtype::client::scenes::MENU) {
        // med.addSubSystem(Signature(rtype::idBitset::idQueueMessageSendClient), _subSysList[rtype::client::NetworkWriterIndex::TCP]);
    this->applySceneEntities();
    return _sysListMenu;
    // }
}

void rtype::client::SceneManager::applySceneEntities()
{
    std::string head = ".";
    if (_currentScene == rtype::client::scenes::MENU) {
        std::string button = head + "./assets/images/used/default2_button.png";
        std::string buttonPlus = head + "./assets/images/used/sound_plus.png";
        std::string buttonMinus = head + "./assets/images/used/sound_minus.png";
        std::string text = head + "./assets/images/used/text/space.ttf";

        struct rtype::client::Button play1 = {.x = 500, .y = 200, .xTxt = 680, .yTxt = 215, .fontPath = text, .textString = "SOLO", .textSize = 40, .imagePath = button,
                       .action = rtype::component::buttonAction::PLAY1,  .width = 442, .height = 89, .start_at = std::chrono::system_clock::now()};
        struct rtype::client::Button play2 = {.x = 500, .y = 300, .xTxt = 680, .yTxt = 315, .fontPath = text, .textString = "DUO",
                            .textSize = 40, .imagePath = button, .action = rtype::component::buttonAction::PLAY2, .width = 442, .height = 89, .start_at = std::chrono::system_clock::now()};
        struct rtype::client::Button play3 = {.x = 500, .y = 400, .xTxt = 680, .yTxt = 415, .fontPath = text, .textString =
                    "TRIO", .textSize = 40, .imagePath = button, .action = rtype::component::buttonAction::PLAY3, .width = 442, .height = 89, .start_at = std::chrono::system_clock::now()};
        struct rtype::client::Button play4 = {.x = 500, .y = 500, .xTxt = 650, .yTxt = 515, .fontPath = text, .textString = "QUADRO", .textSize = 40, .imagePath = button,
                            .action = rtype::component::buttonAction::PLAY4, .width = 442, .height = 89, .start_at = std::chrono::system_clock::now()};
        struct rtype::client::Button quit = {.x = 500, .y = 600, .xTxt = 680, .yTxt = 615, .fontPath = text, .textString = "QUIT", .textSize = 40, .imagePath = button, .action = rtype::component::buttonAction::QUITPRGM, .width = 442, .height = 89, .start_at = std::chrono::system_clock::now()};
        struct rtype::client::Button volPlus = {.x = 1100, .y = 200, .xTxt = 950, .yTxt = 215, .imagePath = buttonPlus, .action = rtype::component::buttonAction::VOLPLUS, .width = 100, .height = 100, .start_at = std::chrono::system_clock::now()};
        struct rtype::client::Button volMinus = {.x = 1250, .y = 200, .xTxt = 1050, .yTxt = 215, .imagePath = buttonMinus, .action = rtype::component::buttonAction::VOLMINUS, .width = 100, .height = 100, .start_at = std::chrono::system_clock::now()};

        std::vector<rtype::client::Button> buttons = {play1, play2, play3, play4, quit, volPlus, volMinus, quit};

        _eFac.createButtons(buttons);

        std::string background = head + "./assets/images/used/menu_background.png";

        struct rtype::client::Image back= {.order = rtype::component::drawOrder::FIRST, .path = background, .x = 0, .y = 0};

        Entity uuid = _eFac.createSimpleImage(back);
        _eFac.createAudio({.path="../assets/musics/menu.ogg", true, true, 0, 100}, uuid);

    }

    if (_currentScene == rtype::client::scenes::GAME) {
        std::string background = head + "./assets/images/used/background3.png";

        struct rtype::client::SpriteSheet sheet = {.x = 0, .y = 0, background, .order = rtype::component::drawOrder::FIRST,
                            .startTime = std::chrono::system_clock::now(), .offset = 4, .nbSheet = 480, .duration = std::chrono::milliseconds{50}, true, 1920, 1024};

        // struct rtype::client::Image sheet= {.order = rtype::component::drawOrder::FIRST, .path = background, .x = 0, .y = 0};

        Entity uuid = _eFac.createSpriteSheet(sheet);
        _eFac.createAudio({.path="../assets/musics/interstellar.ogg", true, true, 0, 100}, uuid);
        // _eFac.createSimpleImage(sheet);

        std::string buttonPlus = head + "./assets/images/used/sound_plus.png";
        std::string buttonMinus = head + "./assets/images/used/sound_minus.png";
        std::string button = head + "./assets/images/used/default2_button.png";
        std::string text = head + "./assets/images/used/text/space.ttf";


        struct rtype::client::Button volPlus = {.x = 475, .y = 880, .imagePath = buttonPlus,
                        .action = rtype::component::buttonAction::VOLPLUS, .width = 100, .height = 100, .start_at = std::chrono::system_clock::now()};
        struct rtype::client::Button volMinus = {.x = 625, .y = 880, .imagePath = buttonMinus,
                    .action = rtype::component::buttonAction::VOLMINUS, .width = 100, .height = 100, .start_at = std::chrono::system_clock::now()};

        struct rtype::client::Button quit = {.x = 0, .y = 900, .xTxt = 180, .yTxt = 915, .fontPath = text, .textString = "QUIT", .textSize = 40, .imagePath = button,
                    .action = rtype::component::buttonAction::QUITPRGM, .width = 442, .height = 89, .start_at = std::chrono::system_clock::now()};
        struct rtype::client::Button quitgame = {.x = 700, .y = 900, .xTxt = 800, .yTxt = 915, .fontPath = text, "QUIT GAME", .textSize = 40, .imagePath = button, .action = rtype::component::buttonAction::QUITGAME,
                     .width = 442, .height = 89, .start_at = std::chrono::system_clock::now()};
        std::vector<rtype::client::Button> buttons = {quit, volPlus, volMinus, quitgame};

        _eFac.createButtons(buttons);
    }

}

rtype::client::SceneManager::~SceneManager()
{
    //close network component
    auto sockUDP = _ecMan._cMan.getComponentFromType<rtype::component::Socket>();
    if (sockUDP.second->_socket.is_open()) {
        sockUDP.second->_socket.close();
    }
    auto sockTCP = _ecMan._cMan.getComponentFromType<rtype::component::SocketTCP>();
    if (sockTCP.second->_socket.is_open()) {
        sockTCP.second->_socket.close();
    }
    auto io = _ecMan._cMan.getComponentFromType<rtype::component::IOService>();
    io.second->_ioService.stop();
}
