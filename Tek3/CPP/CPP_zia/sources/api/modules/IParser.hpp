/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IParser
*/

#ifndef IPARSER_HPP_
#define IPARSER_HPP_

#include "ILogger.hpp"
#include "../config/IConf.hpp"
#include "../io/IInput.hpp"
#include "../context/IRequest.hpp"

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
        * @interface IParser
        * Abstract HTTP request parser.
        * Will be called with an input stream, this module can.
        * emit parsed requests using requestEmitter.
        */
        class IParser
        {
            public:
                virtual ~IParser(void) = default;

                /**
                * @interface IInstance
                * Parser instance, storing parser state and stream / logger / request emitter.
                */
                class IInstance
                {
                    public:
                        virtual ~IInstance(void) = default;

                        /**
                        * @fn parse
                        * Parse incoming requests from available bytes on input stream.
                        * @note The stream / logger / request emitter are implicitely referenced on construction.
                        */
                        virtual void parse(void) = 0;
                };

                /**
                * @fn create
                * Create a parser instance with input, logger and request receiver.
                * @param IInput &input: the input stream
                * @param ILogger &log: the logger associated with the input stream
                * @param IRequest::IEmitter &requestEmitter: the emitter where parsed requests should go
                * @return std::unique_ptr<IInstance>: the parser instance associated with such objects.
                */
                virtual std::unique_ptr<IInstance> create(IInput &input, ILogger &log, IRequest::IEmitter &requestEmitter) = 0;
        };
        using FN_createParser = Zia::Module::IParser* (Zia::IConf &conf);
    } // namespace Module
} // namespace Zia


#endif /* !IPARSER_HPP_ */
