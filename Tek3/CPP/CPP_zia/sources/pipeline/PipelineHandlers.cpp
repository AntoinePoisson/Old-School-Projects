/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** PipelineHandlers
*/

#include "PipelineHandlers.hpp"
#include "../tools/HandleResponse.hpp"
#include "../exception/AException.hpp"
#include "../api/context/Context.hpp"
#include "../api/context/Response.hpp"
#include "../api/context/Request.hpp"

    //! Public
void Zia::PipelineHandlers::loopPipeline(Core *core, enum ControlPipeline_e &(Zia::Core::*fnPtrGetStatus)(void), Zia::CompleteRequest (Zia::Core::*fnPtrGetRequest)(void))
{
    std::vector<Zia::Module::IHandler *> listModulesHandlers;
    Zia::CompleteRequest receiveResquest = std::make_pair(nullptr, std::make_pair(nullptr, nullptr));
    std::shared_ptr<bool> status = std::make_shared<bool>(false);
    std::shared_ptr<Zia::Response> res = nullptr;
    std::shared_ptr<Zia::Context> ctx = nullptr;

    while (core->getStatus() == Continue && (core->*fnPtrGetStatus)() != ControlPipeline_e::Close) {
        if ((core->*fnPtrGetStatus)() == ControlPipeline_e::Reload) {
            listModulesHandlers = core->getModulesHandlers();
            (core->*fnPtrGetStatus)() = ControlPipeline_e::Working;
        }
        receiveResquest = (core->*fnPtrGetRequest)();
        if (receiveResquest.first == nullptr)
            continue;
            // Loop
        *status = false;
        res = std::make_shared<Zia::Response>(status);
        ctx = std::make_shared<Zia::Context>();
        heritageHeaderToResponse(res, (receiveResquest.first));
        for (auto handler : listModulesHandlers) {
            try {
                if (core->getStatus() != Continue || (core->*fnPtrGetStatus)() == ControlPipeline_e::Close) {
                    return;
                }
                if (*status == true) {
                    continue;
                }
                receiveResquest.second.first->log("[LoopPipeline]: Before Call Handlers...");
                handler->handle(*(receiveResquest.first), *res, *ctx, *(receiveResquest.second.first));
                receiveResquest.second.first->log("[LoopPipeline]: ...After Call Handlers");
            } catch(const Zia::AException &exception) {
                std::cerr << exception.what();
                receiveResquest.second.first->log(exception.what());
            } catch(const std::exception &exception) {
                std::cerr << exception.what() << std::endl;
                receiveResquest.second.first->log(exception.what());
            } catch(...) {
                std::cerr << "[loopPipeline]: Cathing throw in loop of module" << std::endl;
            }
        }
        sendResponseToClient(res, receiveResquest.second.first, *(receiveResquest.second.second));
        receiveResquest = std::make_pair(nullptr, std::make_pair(nullptr, nullptr));
    }
}



    //! Private
void Zia::PipelineHandlers::sendResponseToClient(std::shared_ptr<Zia::Response> &res, std::shared_ptr<Zia::IConnection> &client, std::shared_ptr<bool> &stopped)
{
    if (res->checkModifictionByModule() == false) {
        Zia::HandleResponse::sendReponseToClient(Zia::HandleResponse::genRespErr(501), *client);
        client->log("[Client]: Close Socket by Pipeline.");
        *stopped = true;
        return;
    }
    if (!res->getHeader("Keep-Alive") && ((!res->getHeader("Connection")) || (res->getHeader("Connection") && *(res->getHeader("Connection")) != "keep-alive"))) {
        res->setHeader("Connection", "close");
    }
    std::vector<char> result = Zia::HandleResponse::convertResponse(*res);

    client->log("[PipelineHandlers] Sending response");
    client->write(result.size(), &result.front());
    if (!res->getHeader("Keep-Alive") && (res->getHeader("Connection") && (*(res->getHeader("Connection")) != "keep-alive"))) {
        client->log("[Client]: Close Socket by Pipeline.");
        *stopped = true;
    }
}

void Zia::PipelineHandlers::heritageHeaderToResponse(std::shared_ptr<Zia::Response> &res, const Zia::IRequest *req)
{
    if (req->getHeader("Keep-Alive")) {
        res->setHeader("Keep-Alive", *(req->getHeader("Keep-Alive")));
        res->checkModifictionByModule() = false;
    }
    if (req->getHeader("Connection") && (*(req->getHeader("Connection")) == "keep-alive")) {
        res->setHeader("Connection", "keep-alive");
        res->checkModifictionByModule() = false;
    }
}