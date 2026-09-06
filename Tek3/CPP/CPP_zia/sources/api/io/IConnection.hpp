/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IConnection
*/

#ifndef ICONNECTION_HPP_
#define ICONNECTION_HPP_

#include "IInputOutput.hpp"
#include "../modules/ILogger.hpp"

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
    * @interface IConnection
    * Represents a connection to the server.
    * The connection has a logging stream associated with it.
    */
    class IConnection : public IInputOutput, public ILogger
    {
        public:
            virtual ~IConnection(void) override = default;

            /**
            * @fn getRemoteIP
            * Get the IP of the other end of the connection. Ex: `"192.168.1.90"`.
            * @return const std::string&: the remote IP
            */
            virtual const std::string& getRemoteIP(void) const = 0;

            /**
            * @fn getNativeSocket
            * Return the native socket file descriptor
            * @return int: the file descriptor
            */
            virtual int getNativeSocket(void) const = 0;

    };
} // namespace Zia

#endif /* !ICONNECTION_HPP_ */
