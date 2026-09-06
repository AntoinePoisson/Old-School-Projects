/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Request
*/

#ifndef REQUESTZIASERVEUR_HPP_
#define REQUESTZIASERVEUR_HPP_

#include <unordered_map>

#include "IRequest.hpp"
#include "../../core/Core.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    /**
     * @class Request
     * Represent a Request from a client
     */
    class Request : public IRequest
    {
        private:
            Zia::ILogger &_log;
            std::string _method;
            std::string _fullURL;
            std::string _filename;
            std::unordered_map<std::string, std::string> _headers;
            std::unordered_map<std::string, std::string> _arguments;
            std::vector<char> _body;
            std::string _ipClient;

        public:
            Request(Zia::ILogger &log, const std::vector<std::string> &buf, const std::string &ip = "0.0.0.0");
            ~Request();

            const std::string &getClientIP(void) const;
            const std::string &getMethod(void) const;
            const std::string &getProtocol(void) const;
            const std::string &getFilename(void) const;
            const std::string *getArgument(const std::string &name) const;
            std::vector<std::string> getArgumentsKeys(void) const;
            const std::string &getURL(void) const;
            const std::string *getHeader(const std::string &key) const;
            std::vector<std::string> getHeaderKeys(void) const;
            const std::vector<char> *getBody(void) const;
            std::vector<std::string> seperateStringAt(const std::string &str, const char c);

            /**
             * @class Emitter
             * Allow to send the new request to Core
             */
            class Emitter : public IEmitter
            {
                private:
                    Zia::Core *_core;
                    std::shared_ptr<Zia::IConnection> _client;
                    std::shared_ptr<bool> &_stopped;
                    std::shared_ptr<std::chrono::steady_clock::time_point> &_clock;
                    std::shared_ptr<bool> &_oneRequest;
                public:
                    Emitter(Zia::Core *core, std::shared_ptr<Zia::IConnection> client, std::shared_ptr<bool> &stopped, std::shared_ptr<std::chrono::steady_clock::time_point> &clock, std::shared_ptr<bool> &oneRequest);
                    ~Emitter() = default;

                    const std::string &getIp(void);
                    void emit(const IRequest &request);
            };
    };
} // namespace Zia

#endif /* !REQUESTZIASERVEUR_HPP_ */
