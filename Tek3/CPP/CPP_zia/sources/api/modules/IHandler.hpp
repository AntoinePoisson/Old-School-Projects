/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IHandler
*/

#ifndef IHANDLER_HPP_
#define IHANDLER_HPP_

#include "ILogger.hpp"
#include "../config/IConf.hpp"
#include "../context/IRequest.hpp"
#include "../context/IResponse.hpp"
#include "../context/IContext.hpp"

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
        * @interface IResponse
        * Abstract HTTP handler.
        */
        class IHandler
        {
            public:
                virtual ~IHandler(void) = default;

                /**
                * @fn handle
                * Handle request.
                * @param const IRequest &req: the original request
                * @param IResponse &res: the under-construction response
                * @param IContext &ctx: the request-associated context
                * @param ILogger &log: the client-associated logger
                */
                virtual void handle(const IRequest &req, IResponse &res, IContext &ctx, ILogger &log) = 0;
        };
        using FN_createHandler = Zia::Module::IHandler* (Zia::IConf &conf);
    } // namespace Module
} // namespace Zia
#endif /* !IHANDLER_HPP_ */
