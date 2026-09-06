/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Conf
*/

#ifndef CONF_HPP_
#define CONF_HPP_

#include <nlohmann/json.hpp>

#include "IConf.hpp"
#include "Json.hpp"

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
     * @class Conf
     * Herite of Iconf
     * Handle config File
     */
    class Conf : public IConf
    {
        private:
            nlohmann::json _json;
            std::string _nameFile;
        public:
            /**
             * @brief Construct a new Conf object
             * @param nameFile path to Config file
             */
            Conf(const std::string &nameFile);
            ~Conf() = default;

            /**
             * @fn setNamefile
             * Change config file name
             * @param nameFile string name
             */
            void setNameFile(const std::string &nameFile) noexcept;
            /**
             * @fn getNameFile
             * Get the Name File
             * @return const std::string& name
             */
            const std::string &getNameFile(void) const;
            /**
             * @fn read
             * Read config file
             * @return std::unique_ptr<Json::IObject> Object Json
             */
            std::unique_ptr<Json::IObject> read(void) const final;
            /**
             * @fn write
             * Write in confg file
             * @param jsonObject IObject
             */
            void write(const Json::IObject &jsonObject) final;
    };
} // namespace Zia

#endif /* !CONF_HPP_ */
