/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Response
*/

#ifndef RESPONSE_HPP_
#define RESPONSE_HPP_

#include <memory>
#include <map>

#include "IResponse.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    /**
     * @class Response
     * Represent a Zia Reponse
     */
    class Response : public IResponse
    {
        private:
            std::shared_ptr<bool> _statusModule;
            size_t _code;
            std::map<std::string, std::string> _header;
            std::vector<char> _body;
            bool _modif;
        public:
            Response(std::shared_ptr<bool> &status);
            ~Response() = default;

            /**
             * @brief checkModifictionByModule
             * Allow to check if a module edit the reponse or not
             * @return true module edited by a module
             * @return false module not edited
             */
            bool &checkModifictionByModule(void);
            void abortPipeline(void);
            size_t getCode(void) const;
            void setCode(size_t code);
            const std::string *getHeader(const std::string &key) const;
            void setHeader(const std::string &key, const std::string &value);
            const std::vector<char> *getBody(void) const;
            void setBody(const std::vector<char> &body);
    };
} // namespace Zia

#endif /* !RESPONSE_HPP_ */
