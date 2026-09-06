/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** PipelineHandlers
*/

#ifndef PIPELINEHANDLERS_HPP_
#define PIPELINEHANDLERS_HPP_

#include "../core/Core.hpp"
#include "../api/context/IRequest.hpp"
#include "../api/context/Context.hpp"
#include "../api/context/Response.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    /**
     * @class PipelineHandlers
     * Loop throught all Module
     */
    class PipelineHandlers
    {
        private:
            static void sendResponseToClient(std::shared_ptr<Zia::Response> &res, std::shared_ptr<Zia::IConnection> &client, std::shared_ptr<bool> &stopped);
            static void heritageHeaderToResponse(std::shared_ptr<Zia::Response> &res, const Zia::IRequest *req);
        public:
            ~PipelineHandlers() = default;

            /**
             * @brief loopPipeline
             * Loop all module
             * @param core ptr to core
             * @param fnPtrGetStatus ptr to funct
             * @param fnPtrGetRequest ptr to funct
             */
            static void loopPipeline(Core *core, enum ControlPipeline_e &(Zia::Core::*fnPtrGetStatus)(void), Zia::CompleteRequest (Zia::Core::*fnPtrGetRequest)(void));
    };
} // namespace Zia

#endif /* !PIPELINEHANDLERS_HPP_ */
