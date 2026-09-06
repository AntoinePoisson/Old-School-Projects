/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IConf
*/

#ifndef ICONF_HPP_
#define ICONF_HPP_

#include <memory>

#include "IJson.hpp"

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
    * @interface IConf
    * Represents a configuration handler for a given entity.
    * Configuration can be read (raw bytes) and written (raw bytes + format hint).
    */
    class IConf
    {
        public:
            virtual ~IConf(void) = default;

            /**
            * @fn read
            * Read the configuration.
            * @return std::unique_ptr<Json::IObject>: configuration data
            * @note If the configuration if read and there was no precedent write to it,
            * this method returns an empty object.
            */
            virtual std::unique_ptr<Json::IObject> read(void) const = 0;

            /**
            * @fn write
            * Overwrite the configuration.
            * @param const Json::IObject &jsonObject: the object containing the data to use for conf
            */
            virtual void write(const Json::IObject &jsonObject) = 0;
    };
} // namespace Zia

#endif /* !ICONF_HPP_ */
