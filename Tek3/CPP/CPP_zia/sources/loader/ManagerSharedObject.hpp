/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** ManagerSharedObject
*/

#ifndef MANAGERSHAREDOBJECT_HPP_
#define MANAGERSHAREDOBJECT_HPP_

#include <string>
#include <memory>

#ifdef __linux__
# include <dlfcn.h>
#elif _WIN32
#endif

#include "../Zia.hpp"
#include "../api/modules/Logger.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    /**
     * @class ManagerSharedObject
     * Allow to load module (encapsule dlopen/dlclose/dlsym)
     * No need to create instance of class, juste call methode
     */
    class ManagerSharedObject
    {
        private:
            static void writeOrPrintMessage(const std::string &message, std::shared_ptr<Zia::ILogger> log = nullptr, bool displayMessage = true);
        public:
            ~ManagerSharedObject() = default;

            /**
             * @fn openFile
             * Just open the file
             * @param fileName path to file
             * @param log (optional) logger (require displayMessage = true)
             * @param displayMessage (optional) display message of success or failure
             * @return void* opened file handler
             */
            static void *openFile(const std::string &fileName, std::shared_ptr<Zia::ILogger> log = nullptr, bool displayMessage = true) noexcept;
            /**
             * @fn loadSym
             * Load a specifique function in handle
             * @param handle handler of shared object
             * @param symboleName name of function
             * @param log (optional) logger (require displayMessage = true)
             * @param displayMessage (optional) display message of success or failure
             * @return void* return pointer to function
             */
            static void *loadSym(void *handle, const std::string &symboleName, std::shared_ptr<Zia::ILogger> log = nullptr, bool displayMessage = true) noexcept;
            /**
             * @fn closeFile
             * Just close a handle of shared object
             * @param handle handler of shared object
             * @param log (optional) logger (require displayMessage = true)
             * @param displayMessage (optional) display message of success or failure
             * @return true correctly close
             * @return false on error
             */
            static bool closeFile(void *handle, std::shared_ptr<Zia::ILogger> log = nullptr, bool displayMessage = true) noexcept;

            /**
             * @fn autoLoadSym
             * Managment opening / loading and closing of shared object
             * @param handle handler of shared object (already open)
             * @param type ptr to enum (in order to know, which shared object it is)
             * @param log (optional) logger (require displayMessage = true)
             * @param displayMessage (optional) display message of success or failure
             * @return void* ptr to function
             */
            static void *autoLoadSym(void *handle, TypeSharedObject_e &type, std::shared_ptr<Zia::ILogger> log = nullptr, bool displayMessage = true) noexcept;
            /**
             * @fn autoLoadSym
             * Managment opening / loading and closing of shared object
             * WARNING: Marche pas :/
             * @param handle path to file
             * @param type ptr to enum (in order to know, which shared object it is)
             * @param log (optional) logger (require displayMessage = true)
             * @param displayMessage (optional) display message of success or failure
             * @return void* ptr to function
             */
            static void *autoLoadSym(const std::string &fileName, TypeSharedObject_e &type, std::shared_ptr<Zia::ILogger> log = nullptr, bool displayMessage = true) noexcept;
    };
} // namespace Zia

#endif /* !MANAGERSHAREDOBJECT_HPP_ */
