/*
** EPITECH PROJECT, 2021
** ZiaAPI
** File description:
** Zia
*/

#ifndef ZIA_HPP_
#define ZIA_HPP_

#define BYPASS_API_LIMITATION "89618aca-7d32-11eb-9439-0242ac130002"

#define PROTECTION_DDOS 6

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    /**
     * @brief Enum
     * Type of shared file
     */
    enum TypeSharedObject_e {
        ModuleUnknown = 0,
        ModuleConnectionWrapper = 1,
        ModuleHandler = 2,
        ModuleLogger = 3,
        ModuleParser = 4,
    };

    /**
     * @brief Enum
     * Standard status of cose
     */
    enum CoreState_e {
        Continue = 0,
        Stop = 1,
    };

    /**
     * @brief Enum
     * Control comportement of Pipeline of module Handlers
     */
    enum ControlPipeline_e {
        Working = 0,
        Reload = 1,
        Close = 2,
    };

    /**
     * @brief Enum
     * Standard status of client socket
     */
    enum ConnectionState_e {
        Not_Connection = 0,
        Connect = 1,
        Disconnected = 2,
    };

    /**
     * @brief Enum
     * Type of request htpp
     */
    enum TypeRequest_e {
        Http = 0,
        Https = 1,
    };

    /**
     * @brief Enum
     * default return value
     */
    enum {
        Ok = 0,
        Err = 84,
    };
} // namespace zia

#endif /* !ZIA_HPP_ */
