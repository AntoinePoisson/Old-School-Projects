/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** ManagerSharedObject
*/

#include <iostream>

#include "ManagerSharedObject.hpp"

    //! Public
#ifdef __linux__
void *Zia::ManagerSharedObject::openFile(const std::string &fileName, std::shared_ptr<Zia::ILogger> log, bool displayMessage) noexcept
{
    void *handle = dlopen(std::string(fileName + ".so").c_str(), RTLD_LAZY);

    if (!fileName.size()) {
        writeOrPrintMessage("[Load]: Error Loading Shared Object: Invalid size fileName is 0.", log, displayMessage);
        return nullptr;
    }
    else if (handle)
        writeOrPrintMessage("[Load]: Success Loading Shared Object " + fileName + ".so", log, displayMessage);
    else {
        writeOrPrintMessage("[Load]: Error Loading Shared Object " + fileName + ".so: " + dlerror(), log, displayMessage);
        return nullptr;
    }
    return handle;
}
#elif _WIN32
void *Zia::ManagerSharedObject::openFile(const std::string &fileName, std::shared_ptr<Zia::ILogger> log, bool displayMessage) noexcept
{
    // void *handle = dlopen(std::string(fileName + ".so").c_str(), RTLD_LAZY);

    return (nullptr);
}
#endif

#ifdef __linux__
void *Zia::ManagerSharedObject::loadSym(void *handle, const std::string &symboleName, std::shared_ptr<Zia::ILogger> log, bool displayMessage) noexcept
{
    if (!handle) {
        writeOrPrintMessage("[Load]: Error Loading Symbole (" + symboleName + "): Because symbole value is null.", log, displayMessage);
        return nullptr;
    }
    if (!symboleName.size()) {
        writeOrPrintMessage("[Load]: Error Loading Symbole: Because symbole has no name.", log, displayMessage);
        return nullptr;
    }
    void *sym = dlsym(handle, symboleName.c_str());
    if (!sym)
        writeOrPrintMessage("[Load]: Error Loading Symbole (" + symboleName + "): " + dlerror(), log, displayMessage);
    else
        writeOrPrintMessage("[Load]: Success Loading Symbole (" + symboleName + ").", log, displayMessage);
    return sym;
}
#elif _WIN32
void *Zia::ManagerSharedObject::loadSym(void *handle, const std::string &symboleName, std::shared_ptr<Zia::ILogger> log, bool displayMessage) noexcept
{

    return (nullptr);
}
#endif

#ifdef __linux__
bool Zia::ManagerSharedObject::closeFile(void *handle, std::shared_ptr<Zia::ILogger> log, bool displayMessage) noexcept
{
    if (!handle) {
        writeOrPrintMessage("[Load]: Error Close Handle: Because handle value is null.", log, displayMessage);
        return false;
    }
    if (dlclose(handle) == 0) {
        writeOrPrintMessage("[Load]: Success Close Handle.", log, displayMessage);
        return true;
    } else {
        writeOrPrintMessage("[Load]: Error Close Handle: " + std::string(dlerror()), log, displayMessage);
        return false;
    }
}
#elif _WIN32
bool Zia::ManagerSharedObject::closeFile(void *handle, std::shared_ptr<Zia::ILogger> log, bool displayMessage) noexcept
{

    return (false);
}
#endif

#ifdef __linux__
void *Zia::ManagerSharedObject::autoLoadSym(void *handle, TypeSharedObject_e &type, std::shared_ptr<Zia::ILogger> log, bool displayMessage) noexcept
{
    if (!handle) {
        writeOrPrintMessage("[Load]: Error Loading Auto Symbole: Because handle value is null.", log, displayMessage);
        type = TypeSharedObject_e::ModuleUnknown;
        return nullptr;
    }
    void *sym = nullptr;
    type = TypeSharedObject_e::ModuleUnknown;

    if ((sym = dlsym(handle, "createConnectionWrapper")) != nullptr) {
        type = TypeSharedObject_e::ModuleConnectionWrapper;
        writeOrPrintMessage("[Load]: Success Loading Auto Symbole (IConnectionWrapper).", log, displayMessage);
        return sym;
    } else if ((sym = dlsym(handle, "createHandler")) != nullptr) {
        type = TypeSharedObject_e::ModuleHandler;
        writeOrPrintMessage("[Load]: Success Loading Auto Symbole (IHandler).", log, displayMessage);
        return sym;
    } else if ((sym = dlsym(handle, "createLogger")) != nullptr) {
        type = TypeSharedObject_e::ModuleLogger;
        writeOrPrintMessage("[Load]: Success Loading Auto Symbole (ILogger).", log, displayMessage);
        return sym;
    } else if ((sym = dlsym(handle, "createParser")) != nullptr) {
        type = TypeSharedObject_e::ModuleParser;
        writeOrPrintMessage("[Load]: Success Loading Auto Symbole (IParser).", log, displayMessage);
        return sym;
    } else {
        type = TypeSharedObject_e::ModuleUnknown;
        writeOrPrintMessage("[Load]: Error Loading Auto Symbole: No \"Official\" Symbole Find.", log, displayMessage);
        return nullptr;
    }
}
#elif _WIN32
void *Zia::ManagerSharedObject::autoLoadSym(void *handle, TypeSharedObject_e &type, std::shared_ptr<Zia::ILogger> log, bool displayMessage) noexcept
{

    return (nullptr);
}
#endif

#ifdef __linux__
void *Zia::ManagerSharedObject::autoLoadSym(const std::string &fileName, TypeSharedObject_e &type, std::shared_ptr<Zia::ILogger> log, bool displayMessage) noexcept
{
    void *sym = nullptr;
    void *handle = dlopen(std::string(fileName + ".so").c_str(), RTLD_LAZY);
    type = TypeSharedObject_e::ModuleUnknown;

    if (!fileName.size()) {
        writeOrPrintMessage("[Load]: Error Loading Auto Shared Object: Invalid size fileName is 0.", log, displayMessage);
        closeFile(handle, log, false);
        return nullptr;
    }
    else if (!handle) {
        writeOrPrintMessage("[Load]: Error Loading Auto Shared Object " + fileName + ".so: " + dlerror(), log, displayMessage);
        return nullptr;
    }

    if ((sym = dlsym(handle, "createConnectionWrapper")) != nullptr) {
        type = TypeSharedObject_e::ModuleConnectionWrapper;
        writeOrPrintMessage("[Load]: Success Loading Auto Symbole (IConnectionWrapper).", log, displayMessage);
        closeFile(handle, log, false);
        return sym;
    } else if ((sym = dlsym(handle, "createHandler")) != nullptr) {
        type = TypeSharedObject_e::ModuleHandler;
        writeOrPrintMessage("[Load]: Success Loading Auto Symbole (IHandler).", log, displayMessage);
        closeFile(handle, log, false);
        return sym;
    } else if ((sym = dlsym(handle, "createLogger")) != nullptr) {
        type = TypeSharedObject_e::ModuleLogger;
        writeOrPrintMessage("[Load]: Success Loading Auto Symbole (ILogger).", log, displayMessage);
        closeFile(handle, log, false);
        return sym;
    } else if ((sym = dlsym(handle, "createParser")) != nullptr) {
        type = TypeSharedObject_e::ModuleParser;
        writeOrPrintMessage("[Load]: Success Loading Auto Symbole (IParser).", log, displayMessage);
        closeFile(handle, log, false);
        return sym;
    } else {
        type = TypeSharedObject_e::ModuleUnknown;
        writeOrPrintMessage("[Load]: Error Loading Auto Symbole: No \"Official\" Symbole Find.", log, displayMessage);
        closeFile(handle, log, false);
        return nullptr;
    }
}
#elif _WIN32
void *Zia::ManagerSharedObject::autoLoadSym(const std::string &fileName, TypeSharedObject_e &type, std::shared_ptr<Zia::ILogger> log, bool displayMessage) noexcept
{

    return (nullptr);
}
#endif



    //! Private:
void Zia::ManagerSharedObject::writeOrPrintMessage(const std::string &message, std::shared_ptr<Zia::ILogger> log, bool displayMessage)
{
    if (displayMessage == false)
        return;
    if (log)
        log->log(message);
    else
        std::cout << message << std::endl;
}