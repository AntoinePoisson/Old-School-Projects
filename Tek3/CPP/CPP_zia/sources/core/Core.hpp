/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <boost/asio.hpp>
#include <boost/thread/mutex.hpp>

#include "../Zia.hpp"
#include "../server/ServerNetwork.hpp"
#include "../api/io/IConnection.hpp"
#include "../api/modules/Logger.hpp"
#include "../api/modules/IHandler.hpp"
#include "../api/config/Conf.hpp"
#include "../api/context/IRequest.hpp"
#include "../fileWatcher/FileWatcher.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    class FileWatcher;

    /**
     * @def CompleteRequest
     * Represent a request stockage
     */
    using CompleteRequest = std::pair<const Zia::IRequest *, std::pair<std::shared_ptr<Zia::IConnection>, std::shared_ptr<bool> *>>;

    /**
     * @class Core
     * @brief Main class of program
     * Orchester of server
     */
    class Core
    {
        friend class Zia::FileWatcher;

        private:
            boost::mutex _mutex;
            std::shared_ptr<IConf> _conf;
            std::shared_ptr<ILogger> _logger;
            std::shared_ptr<boost::thread> _ThreadPipeline;
            std::vector<std::shared_ptr<boost::asio::io_context::work>> _listServerWorker;
            std::vector<std::unique_ptr<ServerNetwork>> _listServer;
            std::vector<std::shared_ptr<IConnection>> _listClient;
            std::vector<std::shared_ptr<boost::thread>> _listClientThread;
            std::vector<CompleteRequest> _listRequest;
            std::vector<std::pair<Zia::TypeSharedObject_e, void *>> _listHandlerModules;
            bool *_reboot;
            std::vector<std::string> _watchList;
            std::unique_ptr<Zia::FileWatcher> _fileWatcher = nullptr;

            /**
             * @fn getNewRequest
             * Receive request in core (use only on core)
             * @return std::pair<std::shared_ptr<Zia::IRequest>, std::shared_ptr<Zia::IConnection>> maybe nullptr or pair of request and client
             */
            CompleteRequest getNewRequest(void);
            /**
             * @fn getPipelineBehaviour
             * Give the comportenant of Pipeline of Module Handlers
             * @return enum ControlPipeline_e& reference to Behaviour
             */
            enum ControlPipeline_e &getPipelineBehaviour(void);
            /**
             * @fn parseServers
             * Parse the configuration file to get server specification
             */
            void parseServers(const std::unique_ptr<Zia::Json::IObject> &configParsed);
            /**
             * @fn parseModules
             * Parse the configuration file to get server modules
             */
            void parseModules(const std::unique_ptr<Zia::Json::IObject> &configParsed);
            /**
             * @fn parseHandlers
             * Parse the configuration file to get server handlers
             */
            void parseHandlers(const std::unique_ptr<Zia::Json::IObject> &configParsed);
            /**
             * @fn stripExtension
             * Strip string file extensions
             * @param path path of file
             * @return extension-less string
             */
            std::string stripExtension(const std::string &path);
        public:
            /**
             * @brief Construct a new Core object
             * @param configPath path to config file
             */
            Core(const std::string &configPath, bool *reboot);
            ~Core();

            void run(void);
            /**
             * @brief Allow to know when core is close
             * (Special function for handle Ctrl C with multi thread)
             * @return enum CoreState_e& status of Core
             */
            static enum CoreState_e &getStatus(void);
            /**
             * @fn addNewRequest
             * Adding a new request to core (use in tread of loopClient)
             * @param req request
             * @param client client
             */
            void addNewRequest(const Zia::IRequest *req, std::shared_ptr<Zia::IConnection> client, std::shared_ptr<bool> &stopped);
            /**
             * @fn Return The class
             * Get Class from Modules already load by Core
             * WARNING: DON'T HANDLE MODULES HANDLES
             * @param nameModule enum TypeSharedObject
             * @return void* ptr to class or nullptr if error
             */
            void *getModule(const TypeSharedObject_e &nameModule);
            /**
             * @fn Return The classes
             * Get Classes from Modules already load by Core
             * WARNING: ONLY HANDLE MODULES HANDLES
             * @return std::vector<void *> vector of ptr to class or nullptr if error
             */
            std::vector<Zia::Module::IHandler *> getModulesHandlers(void);
            /**
             * @fn get nbr of current client
             * Get Client nbr
             * @param setNbr value nbr client
             * @return const size_t value nbr client
             */
            static const int &getNbrCurrentClient(int setNbr);
            /**
             * @fn isFirstTime
             * Allow to know if first load
             * @return int -1 | 0 or 1
             */
            static int &isFirstTime(void);
    };
} // namespace Zia


#endif /* !CORE_HPP_ */
