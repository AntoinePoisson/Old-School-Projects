/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Core
*/

#include <iostream>
#include <boost/asio.hpp>
#include <sys/stat.h>
#include <sys/types.h>
#include <filesystem>
#include <regex>


#ifdef _WIN32
	#include <direct.h>
	#define mkdir(name, _) _mkdir(name)
#endif


#ifdef _WIN32
	#define DYNAMIC_LIB_EXTENSION__ ".dll"
#else
    #define DYNAMIC_LIB_EXTENSION__ ".so"
#endif


#include "Core.hpp"
#include "exception/AException.hpp"
#include "client/Client.hpp"
#include "pipeline/PipelineHandlers.hpp"
#include "api/io/Connection.hpp"
#include "loader/ManagerSharedObject.hpp"

    //! Public
Zia::Core::Core(const std::string &configPath, bool *reboot)
{
    if (Zia::Core::isFirstTime() != 0 && Zia::Core::isFirstTime() != 1) {
        Zia::Core::isFirstTime() = 1;
    }
    getPipelineBehaviour() =  Zia::ControlPipeline_e::Reload;
    _reboot = reboot;
    _conf = std::make_shared<Zia::Conf>(configPath);
    std::unique_ptr<Zia::Json::IObject> configParsed = _conf->read();
    if (configParsed == nullptr) {
        std::cerr << "\033[33m[Warning]\033[0m: There is currently no server running, please update your configuration file, or check if it exists" << std::endl;
        throw Zia::AException("[Core]", "Couldn't load configuration file", 84);
    } else {
        _watchList.push_back(configPath);
        this->parseServers(configParsed);
        this->parseModules(configParsed);
        this->parseHandlers(configParsed);
        _fileWatcher = std::make_unique<Zia::FileWatcher>("./", std::chrono::milliseconds(333), this);
    }
        // Launch the server on different port and thread
    for (auto &server : _listServer)
        _listServerWorker.push_back(server->run());
        // Launch Pipeline of Module
    _ThreadPipeline = std::make_shared<boost::thread>(boost::thread(&Zia::PipelineHandlers::loopPipeline, this, &Core::getPipelineBehaviour, &Core::getNewRequest));
        // Handle Ctrl + C
    signal(SIGINT, [](int){ Zia::Core::getStatus() = Zia::CoreState_e::Stop; });
    if (isFirstTime() == 1) {
        std::cout << "[Core]: Start" << std::endl;
        _logger->log("[Core]: Start");
    } else {
        std::cout << "[Core]: Successfully Reload" << std::endl;
        _logger->log("\n\n[Core]: Successfully Reload");
    }
}

Zia::Core::~Core()
{
    Zia::Core::getStatus() = Zia::CoreState_e::Stop;
    getPipelineBehaviour() = Zia::ControlPipeline_e::Close;
    for (auto &serverWorker : _listServerWorker) {
        serverWorker->get_io_context().stop();
    }
    _listClient.clear();
    _listServerWorker.clear();
    _listServer.clear();
    if (*_reboot == false) {
        _logger->log("[Close]: Close Zia.");
        std::cout << "[Core]: Close" << std::endl;
    } else {
        _logger->log("[Core]: Need Reload\n\n");
        std::cout << "[Core]: Need Reload" << std::endl;
    }
    Zia::Core::isFirstTime() = 0;
    if (!(*(this->_reboot)))
        std::exit(0);
}

void Zia::Core::run(void)
{
    std::shared_ptr<Zia::IConnection> newClient(nullptr);

    try {
        while (Zia::Core::getStatus() == Zia::CoreState_e::Continue) {
                // Loop Check Client is "Open" (if not remove him from client list)
            for (auto client = std::begin(_listClient); client != std::end(_listClient);) {
                if (!(dynamic_cast<Zia::Connection *> (client->get())) ||
                    ((dynamic_cast<Zia::Connection *> (client->get())->getSocket().is_open()) == false)) {
                    client = _listClient.erase(client);
                    _logger->log("[Erase]: Client From Core.");
                    getNbrCurrentClient(_listClient.size());
                } else
                    ++client;
            }
                // Loop Server (check if new client)
            for (auto &server : _listServer) {
                if (!(newClient = server->receiveNewConnection()))
                    continue;
                getNbrCurrentClient(_listClient.size());
                _listClient.push_back(newClient);
                _listClientThread.push_back(std::make_shared<boost::thread>(boost::thread(&Zia::Client::loopClient, newClient, this)));
            }
        }
    } catch(const AException &exception) {
        _logger->log(exception.what());
        std::cerr << exception.what();
    } catch(const std::exception &exception) {
        _logger->log(exception.what());
        std::cerr << exception.what() << std::endl;
    }
}

enum Zia::CoreState_e &Zia::Core::getStatus(void)
{
    static enum CoreState_e state = Zia::CoreState_e::Continue;

    return state;
}

void Zia::Core::addNewRequest(const Zia::IRequest *req, std::shared_ptr<Zia::IConnection> client, std::shared_ptr<bool> &stopped)
{
    std::pair<const Zia::IRequest *, std::pair<std::shared_ptr<IConnection>, std::shared_ptr<bool> *>> res(req, std::make_pair(client, &stopped));

    _mutex.lock();
    _listRequest.push_back(res);
    _mutex.unlock();
}

void *Zia::Core::getModule(const Zia::TypeSharedObject_e &nameModule)
{
    void *handle = nullptr;
    Zia::TypeSharedObject_e moduleLoadSym = ModuleUnknown;

    if (nameModule == ModuleUnknown || nameModule == ModuleHandler) {
        return nullptr;
    }
    _mutex.lock();
    for (auto element : _listHandlerModules) {
        if (element.first == nameModule) {
            handle = element.second;
            break;
        }
    }
    if (!handle) {
        _mutex.unlock();
        return nullptr;
    }
    moduleLoadSym = nameModule;
    handle = Zia::ManagerSharedObject::autoLoadSym(handle, moduleLoadSym, nullptr, false);
    std::unique_ptr<Zia::Json::IObject> json = _conf->read();
    if (json == nullptr || moduleLoadSym != nameModule) {
        _mutex.unlock();
        return nullptr;
    }
    if (ModuleConnectionWrapper == nameModule) {
        std::unique_ptr<Zia::Json::IObject> save(json->getObject("connection_wrapper"));
        std::optional<std::string> pathToModule = std::nullopt;
        if ((save == nullptr) || ((pathToModule = save->getString("conf")) == std::nullopt)) {
            _mutex.unlock();
            return nullptr;
        }
        Zia::Module::FN_createConnectionWrapper *castedHandle = reinterpret_cast<Zia::Module::FN_createConnectionWrapper *>(handle);
        if ((!castedHandle)) {
            _mutex.unlock();
            return nullptr;
        }
        _mutex.unlock();
        try {
            Zia::Conf conf(*pathToModule);
            return (reinterpret_cast<void *>((*castedHandle)(conf)));
        } catch(const Zia::AException &excep) {
            _logger->log(excep.what());
            return nullptr;
        } catch(...) {
            return (nullptr);
        }
    }
    if (ModuleLogger == nameModule) {
        std::unique_ptr<Zia::Json::IObject> save(json->getObject("logger"));
        std::optional<std::string> pathToModule = std::nullopt;
        if ((save == nullptr) || ((pathToModule = save->getString("conf")) == std::nullopt)) {
            _mutex.unlock();
            return nullptr;
        }
        Zia::Module::FN_createLogger *castedHandle = reinterpret_cast<Zia::Module::FN_createLogger *>(handle);
        if ((!castedHandle)) {
            _mutex.unlock();
            return nullptr;
        }
        _mutex.unlock();
        try {
            Zia::Conf conf(*pathToModule);
            return (reinterpret_cast<void *>((*castedHandle)(conf)));
        } catch(const Zia::AException &excep) {
            _logger->log(excep.what());
            return nullptr;
        } catch(...) {
            return (nullptr);
        }
    }
    if (ModuleParser == nameModule) {
        std::unique_ptr<Zia::Json::IObject> save(json->getObject("parser"));
        std::optional<std::string> pathToModule = std::nullopt;
        if ((save == nullptr) || ((pathToModule = save->getString("conf")) == std::nullopt)) {
            _mutex.unlock();
            return nullptr;
        }
        Zia::Module::FN_createParser *castedHandle = reinterpret_cast<Zia::Module::FN_createParser *>(handle);
        if ((!castedHandle)) {
            _mutex.unlock();
            return nullptr;
        }
        _mutex.unlock();
        try {
            Zia::Conf conf(*pathToModule);
            return (reinterpret_cast<void *>((*castedHandle)(conf)));
        } catch(const Zia::AException &excep) {
            _logger->log(excep.what());
            return nullptr;
        } catch(...) {
            return (nullptr);
        }
    }
    _mutex.unlock();
    return nullptr;
}

std::vector<Zia::Module::IHandler *> Zia::Core::getModulesHandlers(void)
{
    std::vector<Zia::Module::IHandler *> res;
    Zia::TypeSharedObject_e moduleLoadSym = ModuleUnknown;

    _mutex.lock();
    std::unique_ptr<Zia::Json::IObject> json = _conf->read();
    if (json == nullptr) {
        _mutex.unlock();
        return res;
    }
    std::unique_ptr<Zia::Json::IArray> save(json->getArray("handlers"));
    Zia::Json::IObject *tmp = nullptr;
    std::optional<std::string> pathToModule = std::nullopt;
    size_t i = 0;
    void *handle = nullptr;

    for (auto element : _listHandlerModules) {
        if (element.first == ModuleHandler) {
            i += 1;
            moduleLoadSym = ModuleHandler;
            handle = Zia::ManagerSharedObject::autoLoadSym(element.second, moduleLoadSym, nullptr, false);
            if ((!save) || (!handle) || (moduleLoadSym != ModuleHandler) || (!(tmp = save->getObject(i - 1))) || ((pathToModule = tmp->getString("conf")) == std::nullopt))
                continue;
            Zia::Module::FN_createHandler *castedHandle = reinterpret_cast<Zia::Module::FN_createHandler *>(handle);
            if ((!castedHandle))
                continue;
            try {
                Zia::Conf conf(*pathToModule);
                res.push_back((*castedHandle)(conf));
            } catch(const Zia::AException &excep) {
                _logger->log(excep.what());
            } catch(...) {
            }
        }
    }
    _mutex.unlock();
    return res;
}

const int &Zia::Core::getNbrCurrentClient(int setNbr)
{
    static int nbr = 0;

    if (setNbr >= 0) {
        nbr = setNbr;
    }
    return (nbr);
}

int &Zia::Core::isFirstTime(void)
{
    static int status = 1;

    return status;
}



    //! Private
Zia::CompleteRequest Zia::Core::getNewRequest(void)
{
    _mutex.lock();
    if (_listRequest.empty() == true) {
        _mutex.unlock();
        return std::make_pair(nullptr, std::make_pair(nullptr, nullptr));
    }
    CompleteRequest res = _listRequest.front();
    _listRequest.erase(_listRequest.begin());
    _mutex.unlock();
    return res;
}

enum Zia::ControlPipeline_e &Zia::Core::getPipelineBehaviour(void)
{
    static enum ControlPipeline_e state = Zia::ControlPipeline_e::Reload;

    return state;
}

std::string Zia::Core::stripExtension(const std::string &path)
{
    if (path != std::string (DYNAMIC_LIB_EXTENSION__) && path.size() > strlen(DYNAMIC_LIB_EXTENSION__) && path.substr(path.size() - strlen(DYNAMIC_LIB_EXTENSION__)) == std::string(DYNAMIC_LIB_EXTENSION__) )
        return (path.substr(0, path.size() - strlen(DYNAMIC_LIB_EXTENSION__)));
    else
        return (path);
}

void Zia::Core::parseServers(const std::unique_ptr<Zia::Json::IObject> &configParsed)
{
    Zia::Json::IArray* servers = configParsed->getArray("servers");
    if (servers == nullptr || servers->getSize() < 1)
        std::cout << "\033[33m[Warning]\033[0m: There is currently no server running, please update your configuration file" << std::endl;
    std::map<std::string, std::shared_ptr<Zia::ILogger>> log_map;
    log_map["./resources/log/Core.log"] = std::make_shared<Zia::Logger>("./resources/log/Core.log");
    _logger = log_map["./resources/log/Core.log"];
    for (std::size_t i = 0; i < servers->getSize(); i++) {
        if (servers->getObject(i)->getString("log") != std::nullopt && (*(servers->getObject(i)->getString("log"))).size() > 0 && log_map.find(*(servers->getObject(i)->getString("log"))) == log_map.end())
            log_map[*(servers->getObject(i)->getString("log"))] = std::make_shared<Zia::Logger>(*(servers->getObject(i)->getString("log")));
    }
    bool started = false;
    for (std::size_t i = 0; i < servers->getSize(); i++) {
        bool error = false;
        bool secure = false;
        if (servers->getObject(i)->getString("ip") == std::nullopt || !std::regex_match(*(servers->getObject(i)->getString("ip")), std::regex("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$"))) {
            error = true;
            std::cerr << "\033[31m[Error]\033[0m: Bad ip address" << std::endl;
        }
        if (servers->getObject(i)->getInteger("port") == std::nullopt || *(servers->getObject(i)->getInteger("port")) < 0 || *(servers->getObject(i)->getInteger("port")) > 65535) {
            error = true;
            std::cerr << "\033[31m[Error]\033[0m: Bad port number" << std::endl;
        }
        if (error == true) {
            std::cerr << "\033[31m[Error\033[0m: Couldn't start server " << std::to_string(i + 1) << std::endl;
            continue;
        }
        if (servers->getObject(i)->getBool("secure") != std::nullopt && *(servers->getObject(i)->getBool("secure")))
            secure = true;
        started = true;
        if (servers->getObject(i)->getString("log") != std::nullopt && (*(servers->getObject(i)->getString("log"))).size() > 0)
            _listServer.push_back(std::make_unique<ServerNetwork>(*(servers->getObject(i)->getString("ip")), *(servers->getObject(i)->getInteger("port")), log_map[*(servers->getObject(i)->getString("log"))], secure));
        else
            _listServer.push_back(std::make_unique<ServerNetwork>(*(servers->getObject(i)->getString("ip")), *(servers->getObject(i)->getInteger("port")), _logger, secure));
    }
    if (started == false)
        std::cout << "\033[33m[Warning]\033[0m: There is currently no server running, please update your configuration file" << std::endl;
}

void Zia::Core::parseModules(const std::unique_ptr<Zia::Json::IObject> &configParsed)
{
    if (configParsed->getObject("connection_wrapper")->getString("path") == std::nullopt || this->stripExtension(*(configParsed->getObject("connection_wrapper")->getString("path"))).size() < 1 || !std::filesystem::exists( this->stripExtension(*(configParsed->getObject("connection_wrapper")->getString("path"))) + DYNAMIC_LIB_EXTENSION__ ) || !std::filesystem::is_regular_file( this->stripExtension(*(configParsed->getObject("connection_wrapper")->getString("path"))) + DYNAMIC_LIB_EXTENSION__ )) {
        std::cout << "\033[33m[Warning]\033[0m: There is no, or there is a misconfiguration for \"connection_wrapper\" module, trying the default one" << std::endl;
        if (!std::filesystem::exists( std::string("./build/modules/lib/libModuleConnectionWrapper") + DYNAMIC_LIB_EXTENSION__ ) || !std::filesystem::is_regular_file( std::string("./build/modules/lib/libModuleConnectionWrapper") + DYNAMIC_LIB_EXTENSION__ )) {
            std::cerr << "\033[31m[Error]\033[0m: Default \"connection_wrapper\" module not found, the server won't be able to run, try to update your configuration file" << std::endl;
            throw Zia::AException("[Core]", "Couldn't load module \"connection_wrapper\"", 84);
        } else {
            _listHandlerModules.push_back(std::make_pair<Zia::TypeSharedObject_e, void *>(ModuleConnectionWrapper, Zia::ManagerSharedObject::openFile("./build/modules/lib/libModuleConnectionWrapper", _logger)));
            _watchList.push_back(std::string("./build/modules/lib/libModuleConnectionWrapper") + DYNAMIC_LIB_EXTENSION__);
            if (configParsed->getObject("connection_wrapper")->getString("path") != std::nullopt && this->stripExtension(*(configParsed->getObject("connection_wrapper")->getString("path"))).size() > 0)
                _watchList.push_back(this->stripExtension(*(configParsed->getObject("connection_wrapper")->getString("path"))) + DYNAMIC_LIB_EXTENSION__);
        }
    } else {
        _listHandlerModules.push_back(std::make_pair<Zia::TypeSharedObject_e, void *>(ModuleConnectionWrapper, Zia::ManagerSharedObject::openFile(this->stripExtension(*(configParsed->getObject("connection_wrapper")->getString("path"))), _logger)));
        _watchList.push_back(this->stripExtension(*(configParsed->getObject("connection_wrapper")->getString("path"))) + DYNAMIC_LIB_EXTENSION__);
    }
    if (configParsed->getObject("parser")->getString("path") == std::nullopt || this->stripExtension(*(configParsed->getObject("parser")->getString("path"))).size() < 1 || !std::filesystem::exists( this->stripExtension(*(configParsed->getObject("parser")->getString("path"))) + DYNAMIC_LIB_EXTENSION__ ) || !std::filesystem::is_regular_file( this->stripExtension(*(configParsed->getObject("parser")->getString("path"))) + DYNAMIC_LIB_EXTENSION__ )) {
        std::cout << "\033[33m[Warning]\033[0m: There is no, or there is a misconfiguration for \"parser\" module, trying the default one" << std::endl;
        if (!std::filesystem::exists( std::string("./build/modules/lib/libModuleParser") + DYNAMIC_LIB_EXTENSION__ ) || !std::filesystem::is_regular_file( std::string("./build/modules/lib/libModuleParser") + DYNAMIC_LIB_EXTENSION__ )) {
            std::cerr << "\033[31m[Error]\033[0m: Default \"parser\" module not found, the server won't be able to run, try to update your configuration file" << std::endl;
            throw Zia::AException("[Core]", "Couldn't load module \"parser\"", 84);
        } else {
            _listHandlerModules.push_back(std::make_pair<Zia::TypeSharedObject_e, void *>(ModuleParser, Zia::ManagerSharedObject::openFile("./build/modules/lib/libModuleParser", _logger)));
            _watchList.push_back(std::string("./build/modules/lib/libModuleParser") + DYNAMIC_LIB_EXTENSION__);
            if (configParsed->getObject("parser")->getString("path") != std::nullopt && this->stripExtension(*(configParsed->getObject("parser")->getString("path"))).size() > 0)
                _watchList.push_back(this->stripExtension(*(configParsed->getObject("parser")->getString("path"))) + DYNAMIC_LIB_EXTENSION__);
        }
    } else {
        _listHandlerModules.push_back(std::make_pair<Zia::TypeSharedObject_e, void *>(ModuleParser, Zia::ManagerSharedObject::openFile(this->stripExtension(*(configParsed->getObject("parser")->getString("path"))), _logger)));
        _watchList.push_back(this->stripExtension(*(configParsed->getObject("parser")->getString("path"))) + DYNAMIC_LIB_EXTENSION__);
    }
}

void Zia::Core::parseHandlers(const std::unique_ptr<Zia::Json::IObject> &configParsed)
{
    Zia::Json::IArray* arrayHandler = configParsed->getArray("handlers");

    for (size_t i = 0; i < arrayHandler->getSize(); i++) {
        if (arrayHandler->getObject(i)->getString("path") != std::nullopt && this->stripExtension( *(arrayHandler->getObject(i)->getString("path")) ).size() > 0 && std::filesystem::exists( this->stripExtension(*(arrayHandler->getObject(i)->getString("path"))) + DYNAMIC_LIB_EXTENSION__ ) && std::filesystem::is_regular_file( this->stripExtension(*(arrayHandler->getObject(i)->getString("path"))) + DYNAMIC_LIB_EXTENSION__ )) {
            _listHandlerModules.push_back(std::make_pair<Zia::TypeSharedObject_e, void *>(ModuleHandler, Zia::ManagerSharedObject::openFile(this->stripExtension( *(arrayHandler->getObject(i)->getString("path")) ), _logger)));
            _watchList.push_back(this->stripExtension(*(arrayHandler->getObject(i)->getString("path"))) + DYNAMIC_LIB_EXTENSION__);
        } else {
            if (arrayHandler->getObject(i)->getString("path") != std::nullopt && this->stripExtension( *(arrayHandler->getObject(i)->getString("path")) ).size() > 0)
                _watchList.push_back(this->stripExtension(*(arrayHandler->getObject(i)->getString("path"))) + DYNAMIC_LIB_EXTENSION__);
            std::cout << "\033[33m[Warning]\033[0m: Couldn't load handler number " << std::to_string(i + 1) << ", try updating configuration file" << std::endl;
        }
    }
}