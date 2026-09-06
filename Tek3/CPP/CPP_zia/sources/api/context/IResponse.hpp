/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IResponse
*/

#ifndef IRESPONSE_HPP_
#define IRESPONSE_HPP_

#include <string>
#include <vector>
#include <cstddef>

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
    * @interface IResponse
    * Abstract HTTP response.
    */
    class IResponse
    {
        public:
            virtual ~IResponse(void) = default;

            /**
            * @fn abortPipeline
            * Stop handlers traversal. After current handler, no more handler will be called for current response.
            */
            virtual void abortPipeline(void) = 0;

            /**
            * @fn getCode
            * Get response status.
            * Default code must be 200.
            * @return size_t: current value of the status code
            */
            virtual size_t getCode(void) const = 0;

            /**
            * @fn setCode
            * Set response status.
            * @param size_t code: value of the status code to set
            */
            virtual void setCode(size_t code) = 0;

            /**
            * @fn getHeader
            * Query a header parameter. Returns non-null if found, null otherwise.
            * @param const std::string &key: the key of the parameter to query. Ex: `"Connection"`
            * @return const std::string*: the optional parameter
            */
            virtual const std::string* getHeader(const std::string &key) const = 0;

            /**
            * @fn setHeader
            * Sets a header parameter.
            * @param const std::string &key: the key of the parameter to set. Ex: `"content-type"`
            * @param const std::string &value: the value of the parameter to set. Ex: `"application/json"`
            */
            virtual void setHeader(const std::string &key, const std::string &value) = 0;

            /**
            * @fn getBody
            * Query response body. Returns non-null if present, null otherwise.
            * @return const std::vector<char>*: the optional buffer containing body data
            */
            virtual const std::vector<char>* getBody(void) const = 0;

            /**
            * @fn setBody
            * Set response body.
            * @param const std::vector<char> &body: the buffer to set for body data
            */
            virtual void setBody(const std::vector<char> &body) = 0;
    };
} // namespace Zia

#endif /* !IRESPONSE_HPP_ */
