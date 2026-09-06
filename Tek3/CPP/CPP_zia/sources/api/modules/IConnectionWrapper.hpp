/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IConnectionWrapper
*/

#ifndef IConnectionWrapper_HPP_
#define IConnectionWrapper_HPP_

#include "ILogger.hpp"
#include "../config/IConf.hpp"
#include "../io/IConnection.hpp"

#if _MSC_VER && !__INTEL_COMPILER
# define ZIA_EXPORT_SYMBOL __declspec(dllexport)
#else
# define ZIA_EXPORT_SYMBOL
#endif

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
    * @namespace Module
    * All interfaces for modules.
    * One interface = one module kind.
    */
    namespace Module
    {
        /**
        * @interface IConnectionWrapper
        * A module wrapping an existing connection into a new connection.
        * Typically used to implement a SSL or TLS layer on top of HTTP.
        */
        class IConnectionWrapper
        {
            public:
                virtual ~IConnectionWrapper(void) = default;

                /**
                * @fn create
                * Create a connection derivative.
                * @param IConnection &connection: the base connection
                * @return std::unique_ptr<IConnection>: the derived connection
                * @note Return value must be destroyed before connection.
                */
                virtual std::unique_ptr<IConnection> create(IConnection &connection) = 0;
        };
        using FN_createConnectionWrapper = Zia::Module::IConnectionWrapper* (Zia::IConf &conf);
    } // namespace Module
} // namespace Zia

#endif /* !IConnectionWrapper_HPP_ */
