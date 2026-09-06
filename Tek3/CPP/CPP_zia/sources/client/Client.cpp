/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Client
*/

#include <iostream>
#include <chrono>

#include "Client.hpp"
#include "../exception/AException.hpp"
#include "../loader/ManagerSharedObject.hpp"
#include "../tools/HandleResponse.hpp"
#include "../api/context/Request.hpp"
#include "../api/modules/IParser.hpp"
#include "../api/modules/IConnectionWrapper.hpp"

    //! Public
void Zia::Client::loopClient(std::shared_ptr<Zia::IConnection> client, Zia::Core *core)
{
    std::unique_ptr<Zia::Module::IConnectionWrapper> connectionWrapper(reinterpret_cast<Zia::Module::IConnectionWrapper *> (core->getModule(Zia::TypeSharedObject_e::ModuleConnectionWrapper)));
    std::unique_ptr<Zia::Module::IParser> parser(reinterpret_cast<Zia::Module::IParser *> (core->getModule(Zia::TypeSharedObject_e::ModuleParser)));

    if ((!connectionWrapper) || (!parser)) {
        Zia::HandleResponse::sendReponseToClient(Zia::HandleResponse::genRespInterErrServer(), *client);
        writeOrPrintMessage("[LoopClient]: Abord Client due to module problem.", client);
        return;
    }
    std::unique_ptr<IConnection> instanceConnection = nullptr;
    std::unique_ptr<Zia::Module::IParser::IInstance> instanceParser = nullptr;

    client->log("[LoopClient]: Before call create() du module...");
    try {
        instanceConnection = connectionWrapper->create(*client);
    } catch(...) {
        Zia::HandleResponse::sendReponseToClient(Zia::HandleResponse::genRespInterErrServer(), *client);
        writeOrPrintMessage("[LoopClient]: Failure call create methode.", client);
        dynamic_cast<Zia::Connection *> (client.get())->disconnecting();
        return;
    }
    if (!instanceConnection) {
        Zia::HandleResponse::sendReponseToClient(Zia::HandleResponse::genRespInterErrServer(), *client);
        writeOrPrintMessage("[LoopClient]: Abord Client due to module problem (create methode)", client);
        return;
    }
    std::shared_ptr<std::chrono::steady_clock::time_point> clock = std::make_shared<std::chrono::steady_clock::time_point>(std::chrono::steady_clock::now());
    std::shared_ptr<IConnection> transfo = std::move(instanceConnection);
    std::shared_ptr<bool> atleastOneRequest = std::make_shared<bool>(false);
    std::shared_ptr<bool> isStopped = std::make_shared<bool>(false);
    Zia::Request::Emitter emitter(core, transfo, isStopped, clock, atleastOneRequest);
    try {
        instanceParser = parser->create(*transfo, *client, emitter);
    } catch(...) {
        Zia::HandleResponse::sendReponseToClient(Zia::HandleResponse::genRespInterErrServer(), *client);
        writeOrPrintMessage("[LoopClient]: Failure call create methode.", client);
        dynamic_cast<Zia::Connection *> (client.get())->disconnecting();
        return;
    }
    client->log("[LoopClient]: ...After call create() du module");

    if (!instanceParser) {
        Zia::HandleResponse::sendReponseToClient(Zia::HandleResponse::genRespInterErrServer(), *client);
        writeOrPrintMessage("[LoopClient]: Abord Client due to module problem (create methode)", client);
        return;
    }
    try {
        while (Zia::Core::getStatus() == Zia::CoreState_e::Continue && *isStopped == false) {
            if ((*atleastOneRequest == false && std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - *clock).count() >= 5)
                || (*atleastOneRequest == true && std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - *clock).count() >= 2)) {
                writeOrPrintMessage("[LoopClient]: Time out Request.", client);
                if (*atleastOneRequest == false) {
                    Zia::HandleResponse::sendReponseToClient(Zia::HandleResponse::genRespErr(408), *transfo);
                }
                dynamic_cast<Zia::Connection *> (client.get())->disconnecting();
                return;
            }
            if (dynamic_cast<Zia::Connection *> (client.get())->getSocket().is_open() == false) {
                dynamic_cast<Zia::Connection *> (client.get())->disconnecting();
                return;
            }
            try {
                instanceParser->parse();
            } catch(Zia::AException &exception) {
                writeOrPrintMessage(exception.what(), client);
                if (exception.getValue() != 0) {
                    Zia::HandleResponse::sendReponseToClient(Zia::HandleResponse::genRespErr(exception.getValue()), *transfo);
                } else {
                    Zia::HandleResponse::sendReponseToClient(Zia::HandleResponse::genRespInterErrServer(), *transfo);
                }
                dynamic_cast<Zia::Connection *> (client.get())->disconnecting();
                return;
            }
        }
    } catch(Zia::AException &exception) {
        writeOrPrintMessage(exception.what(), client);
    } catch(...) {
        writeOrPrintMessage("[LoopClient]: Receive Throw.", client);
    }
    if (dynamic_cast<Zia::Connection *> (client.get())->getSocket().is_open() == false) {
        dynamic_cast<Zia::Connection *> (client.get())->disconnecting();
    }
}

    //! Private
void Zia::Client::writeOrPrintMessage(const std::string &message, const std::shared_ptr<Zia::IConnection> &client, bool onFailurePrint)
{
    Zia::Connection *logger = dynamic_cast<Zia::Connection *> (client.get());

    if (logger)
        logger->log(message);
    else if (onFailurePrint)
        std::cout << message << std::endl;
}
