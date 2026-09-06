/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** ILogger
*/

#ifndef ILOGGER_HPP_
#define ILOGGER_HPP_

#include <string>

#include "../config/IConf.hpp"

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
    * @interface ILogger
    * Abstract logging system.
    */
    class ILogger
    {
        public:
            virtual ~ILogger(void) = default;

            /**
            * @fn log
            * Log a string to the logging stream.
            * @param const std::string &str: the string to log
            */
            virtual void log(const std::string &str) = 0;
    };
    /**
    * @namespace Module
    * All interfaces for modules.
    * One interface = one module kind.
    */
    namespace Module
    {
        using ILogger = Zia::ILogger;
        using FN_createLogger = Zia::Module::ILogger* (Zia::IConf &conf);
    } // namespace Module
} // namespace Zia

#endif /* !ILOGGER_HPP_ */
