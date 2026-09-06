/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Connection
*/

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include <boost/asio.hpp>
#include <memory>
#include <queue>

#include "IConnection.hpp"
#include "../modules/Logger.hpp"
#include "../../Zia.hpp"

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
     * @class Connection
     * Herite of IConnection
     * Handle client socket
     */
    class Connection : public IConnection
    {
        private:
            int _status;
            boost::asio::ip::tcp::socket _socket;
            Zia::TypeRequest_e _requestType;
            std::queue<std::string> _sendQueue;
            std::shared_ptr<Zia::ILogger> _logger;
            std::string _ipClient;
            int _nativeSocket;

            void openAsyncWrite();
            void handlerWrite(const boost::system::error_code& error, std::size_t size);
        public:
            /**
             * @brief Construct a new Connection object
             * @param _ioContext iocontext of server
             * @param log (optional) log file (if not create this own)
             */
            Connection(boost::asio::io_context &_ioContext, std::shared_ptr<Zia::ILogger> log = nullptr, bool secure = false);
            virtual ~Connection();

            /**
             * @fn Create a Connection object
             * Use to create instance of class
             * @param _ioContext iocontext of server
             * @param log (optional) log file (if not create this own)
             * @return std::shared_ptr<Zia::Connection> Connection class
             */
            static std::shared_ptr<Zia::Connection> createConnection(boost::asio::io_context &_ioContext, std::shared_ptr<Zia::ILogger> log, bool secure) noexcept;
            /**
             * @fn getSocket
             * Get the Socket client
             * @return boost::asio::ip::tcp::socket& socket
             */
            boost::asio::ip::tcp::socket &getSocket() noexcept;
            const boost::asio::ip::tcp::socket &getSocket() const noexcept;
            /**
             * @fn Get the Http type
             * Allow to know if the socket is https or htpp
             * @return const size_t& type
             */
            const Zia::TypeRequest_e &getHttpType() const;
            /**
             * @fn getLogger
             * Get the Logger of Connection
             * @return const std::shared_ptr<Zia::ILogger>& log
             */
            const std::shared_ptr<Zia::ILogger> &getLogger() const noexcept;
            /**
             * @fn getStatus
             * Know status socket and client (a little useless)
             * @return int enum ConnectionState_e
             */
            int getStatus() const noexcept;
            /**
             * @fn connecting
             * Active socket
             */
            void connecting();
            /**
             * @fn disconnecting
             * Close socket
             */
            void disconnecting();
            /**
             * @fn log
             * Herited of IConnection
             * Write string in log of connection
             * @param str message string
             */
            void log(const std::string &str) override;
            /**
             * @fn read
             * Herited of IConnection
             * Read socket mode no-blocking
             * @param buf_size size of parameter "buf"
             * @param buf allocat memory for storing
             * @return size_t size of reading (return 0 if nothing to read)
             */
            size_t read(size_t buf_size, char *buf) override;
            /**
             * @fn write
             * Herited of IConnection
             * Write in socket (async method)
             * @param buf_size size of parameter "buf"
             * @param buf message to write
             * @return size_t size of successfully writing data (useless)
             */
            size_t write(size_t buf_size, const char *buf) override;
            /**
            * @fn getRemoteIP
            * Get the IP of the other end of the connection. Ex: `"192.168.1.90"`.
            * @return const std::string&: the remote IP
            */
            const std::string &getRemoteIP(void) const override;
            /**
            * @fn getNativeSocket
            * Return the native socket file descriptor
            * @return int: the file descriptor
            */
            int getNativeSocket(void) const override;
    };
} // namespace Zia

#endif /* !CONNECTION_HPP_ */
