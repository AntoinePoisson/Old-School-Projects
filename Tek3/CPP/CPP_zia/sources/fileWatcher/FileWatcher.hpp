/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** FileWatcher
*/

#ifndef FILEWATCHER_HPP_
#define FILEWATCHER_HPP_

#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <string>
#include <functional>
#include <boost/thread.hpp>

#include "../core/Core.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia {

    class Core;

    /**
     * @enum FileStatus
     * FileWatcher Status
     */
    enum class FileStatus
    {
        deleted,
        edited,
        created
    };

    /**
     * @class FileWatcher
     * Watch all config file modification
     */
    class FileWatcher
    {
        public:
            explicit FileWatcher(std::string watching_path, std::chrono::duration<int, std::milli> delay, Zia::Core *core);
            virtual ~FileWatcher();

        private:
            void watch();
            void action(const Zia::FileStatus &status, const std::string &path_watch);

            Zia::Core *_core;
            std::unordered_map<std::string, std::filesystem::file_time_type> _paths;
            std::chrono::duration<int, std::milli> _sleep;
            bool _running;
            std::string _path;
            boost::thread _threadFile;
    };
} // namespace Zia

#endif