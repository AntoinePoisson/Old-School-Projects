/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IRequest
*/

#ifndef IREQUEST_HPP_
#define IREQUEST_HPP_

#include <string>
#include <vector>

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
    * @interface IRequest
    * Abstract HTTP request.
    */
    class IRequest
    {
        public:
            virtual ~IRequest(void) = default;

            /**
            * @fn getClientIP
            * Get client IP. Ex: `"192.168.1.90"`.
            * @return const std::string&: the client IP
            */
            virtual const std::string& getClientIP(void) const = 0;

            /**
            * @fn getMethod
            * Get HTTP method for the request. Ex: `"GET"`, `"POST"` or `"DELETE"`.
            * @return const std::string&: the method in caps
            */
            virtual const std::string& getMethod(void) const = 0;

            /**
            * @fn getProtocol
            * Get HTTP protocol for the request. Ex: `"HTTP/1.1"`.
            * @return const std::string&: the protocol as a string
            */
            virtual const std::string& getProtocol(void) const = 0;

            /**
            * @fn getFilename
            * Get request filename, without any argument. Ex: `"/login.html"`
            * @return const std::string&: the request filename
            */
            virtual const std::string& getFilename(void) const = 0;

            /**
            * @fn getArgument
            * Query an argument (key-values trailing in URL). Returns non-null if found, null otherwise.
            * @param const std::string &name: the name of the argument to query
            * @return const std::string*: the optional argument
            */
            virtual const std::string* getArgument(const std::string &name) const = 0;

            /**
            * @fn getArgumentsKeys
            * Get keys for all arguments. Those keys can be used in any call to `getArgument`.
            * @return std::vector<std::string>: the optional argument
            */
            virtual std::vector<std::string> getArgumentsKeys(void) const = 0;

            /**
            * @fn getURL
            * Get full URL, with arguments. Ex: `"/login.html?username=John&password=12345678"`
            * @return const std::string&: the protocol as a string
            */
            virtual const std::string& getURL(void) const = 0;

            /**
            * @fn getHeader
            * Query a header parameter. Returns non-null if found, null otherwise.
            * @param const std::string &key: the key of the parameter to query. Ex: `"Connection"`
            * @return const std::string*: the optional parameter
            */
            virtual const std::string* getHeader(const std::string &key) const = 0;

            /**
            * @fn getHeaderKeys
            * Query header keys. Those keys can be used in any call to `getHeader`.
            * @return const std::string*: the header keys
            */
            virtual std::vector<std::string> getHeaderKeys(void) const = 0;

            /**
            * @fn getBody
            * Query request body. Returns non-null if present, null otherwise.
            * @return const std::vector<char>*: the optional buffer containing body data
            */
            virtual const std::vector<char>* getBody(void) const = 0;

            /**
            * @interface IEmitter
            * Represents an incoming requests receiver.
            */
            class IEmitter
            {
                public:
                    virtual ~IEmitter(void) = default;

                    /**
                    * @fn emit
                    * Emit a request.
                    * @param const Request &request: the emitted request
                    */
                    virtual void emit(const IRequest &request) = 0;
            };
    };
} // namespace Zia

#endif /* !IREQUEST_HPP_ */
