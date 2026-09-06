/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <memory>
#include <functional>

#include "../core/Core.hpp"
#include "../api/io/Connection.hpp"
#include "../api/config/Conf.hpp"
#include "../api/modules/IConnectionWrapper.hpp"
#include "../api/modules/IParser.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    /**
     * @class Client
     * This class handle loop client
     * (Setup client / Read socket / Parse request / Send request to core)
     */
    class Client
    {
        private:
            static void writeOrPrintMessage(const std::string &message, const std::shared_ptr<Zia::IConnection> &client, bool onFailurePrint = true);
        public:
            ~Client() = default;

            /**
             * @fn loopClient
             * Loop of client (must be use in Thread !)
             * @param client Iconnection of client
             * @param conf conf file of core
             * @param core reference to core (for use fnPtr addNewRequest)
             */
            static void loopClient(std::shared_ptr<Zia::IConnection> client, Zia::Core *core);
    };
} // namespace Zia


#endif /* !CLIENT_HPP_ */
