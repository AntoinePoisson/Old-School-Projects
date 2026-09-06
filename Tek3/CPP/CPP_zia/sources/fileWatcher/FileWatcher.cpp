/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** FileWatcher
*/

#include "FileWatcher.hpp"

    //! Public
Zia::FileWatcher::FileWatcher(std::string watching_path, std::chrono::duration<int, std::milli> delay, Zia::Core *core)
{
    this->_core = core;
    this->_sleep = delay;
    this->_path = watching_path;
    this->_running = true;
    for (auto &file : std::filesystem::recursive_directory_iterator(this->_path)) {
        try {
            auto tmp = std::filesystem::last_write_time(file);
            this->_paths[file.path().string()] = tmp;
        } catch(...) {}
    }
    this->_threadFile = boost::thread(&Zia::FileWatcher::watch, this);
}

Zia::FileWatcher::~FileWatcher()
{
    this->_running = false;
    this->_threadFile.join();
}



    //! Private
void Zia::FileWatcher::action(const Zia::FileStatus &status, const std::string &path_watch)
{
    if(!std::filesystem::is_regular_file(std::filesystem::path(path_watch)) && status != Zia::FileStatus::deleted) {
        return;
    }
    for (auto &elm : this->_core->_watchList) {
        if (path_watch == elm) {
            this->_running = false;
            *(this->_core->_reboot) = true;
            Zia::Core::getStatus() = Zia::CoreState_e::Stop;
            // Join
            break;
        }
    }
}

void Zia::FileWatcher::watch()
{
    while (this->_running)
    {
        try {
            std::this_thread::sleep_for(this->_sleep);
            auto it = this->_paths.begin();
            while (it != this->_paths.end())
            {
                if (!std::filesystem::exists(it->first))
                {
                    this->action(Zia::FileStatus::deleted, it->first);
                    it = this->_paths.erase(it);
                    continue;
                }
                it++;
            }
            for (auto &file : std::filesystem::recursive_directory_iterator(this->_path))
            {
                auto current_file_last_write_time = std::filesystem::last_write_time(file);
                if (!(this->_paths.find(file.path().string()) != this->_paths.end()))
                {
                    this->_paths[file.path().string()] = current_file_last_write_time;
                    this->action(Zia::FileStatus::created, file.path().string());
                    continue;
                }
                if (_paths[file.path().string()] != current_file_last_write_time)
                {
                    this->_paths[file.path().string()] = current_file_last_write_time;
                    this->action(Zia::FileStatus::edited, file.path().string());
                }
            }
        } catch (const std::filesystem::filesystem_error &err) {
            // std::cout << err.what() << std::endl; //! throw ici
        } catch (const std::exception &err) {
            std::cout << "[FileWatcher]: Receive exception" << std::endl;
        } catch (...) {
            std::cout << "[FileWatcher]: Something happened on filewatcher" << std::endl;
        }
    }
}
