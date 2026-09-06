/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LoadingSave
*/

#ifndef LOADINGSAVE_HPP_
#define LOADINGSAVE_HPP_

#include <chrono>
#include <ctime>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <vector>
#include <filesystem>
#include <time.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "AMenu.hpp"
#include "Map.hpp"
#include "WrapPlayers.hpp"
#include "GameLoop.hpp"


namespace indie
{
    template<typename T, typename U>
    class LoadingSave {
        public:
            LoadingSave();
            LoadingSave(const T &map, const U &wraper);
            virtual ~LoadingSave() = default;

            void save();
            void load();
            void setPath();
            void setWhich0();
            void setWhich1();
            void setWhich2();
            void setRecentSave();
            std::vector<std::string> getSaveName();
            std::vector<std::string> getRecentSave() const;
    //        bool deleteFile(const std::string &fileName);
    //        bool renameSave(const std::string &oldFileName, const std::string &newFileName);
        private:
            int which;
            std::string _path;
            T _map = {};
            U _wrap = {};
            std::vector<std::string> _saveName;
            std::vector<std::string> _recentSave;
    };

    std::ostream& operator<<(std::ostream& stm, const indie::Map &map);
    std::ostream& operator<<(std::ostream& stm, const indie::WrapPlayers<int> &wrap);
    std::istream& operator>>(std::istream& stm, indie::Map &map);
    std::istream& operator>>(std::istream& stm, indie::WrapPlayers<int> &wrap);

    class LoadingMenu : public AMenu {
        public:
            LoadingMenu();
            virtual ~LoadingMenu() = default;

            void run();
        private:
    };
}

//////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T, typename U>
indie::LoadingSave<T, U>::LoadingSave()
: which(-1), _path("")
{
    getSaveName();
    setRecentSave();
}

template<typename T, typename U>
indie::LoadingSave<T, U>::LoadingSave(const T &map, const U &wraper)
: which(-1), _path("")
{
    _map = map;
    _wrap = wraper;
    getSaveName();
    setRecentSave();
}

template<typename T, typename U>
void indie::LoadingSave<T, U>::save()
{
    if (!std::filesystem::exists("./ressources/.saves/")) {
        std::cout << "Can't find the save file!" << std::endl;
        std::filesystem::create_directory("./ressources/.saves");
    }
    auto date = std::chrono::system_clock::now();
    std::time_t date_time = std::chrono::system_clock::to_time_t(date);
    std::string filePath = "./ressources/.saves/";
    filePath = filePath + std::ctime(&date_time);
    std::ofstream file(filePath, std::ios::trunc);

    file << _map;
    file << _wrap;
    file.close();
}

template<typename T, typename U>
void indie::LoadingSave<T, U>::load()
{
    setPath();
    if (_path.empty()) {
        std::cout << "THERE IS NOT ENOUGH SAVE FILE" << std::endl;
        return;
    }
    if (!std::filesystem::exists("./ressources/.saves/")) {
        std::cout << "Can't find the save file!" << std::endl;
        return;
    }
    std::ifstream file("./ressources/.saves/" + _path, std::ios::in);
    unsigned int seed = 0;
    indie::WrapPlayers<int> wrapper;

    file >> seed;
    indie::Map map(seed);
    file >> map;

    file >> wrapper;

    file.close();

    indie::Game game(map, wrapper);

    game.run();
//  LANCER LA GAME LOOP
}

template<typename T, typename U>
std::vector<std::string> indie::LoadingSave<T, U>::getSaveName()
{
    if (!std::filesystem::exists("./ressources/.saves/")) {
        std::cout << "Can't find the save file!" << std::endl;
        return {};
    }
    std::string path("./ressources/.saves/");

    for (const auto &it : std::filesystem::directory_iterator(path)) {
//        const std::string file = it.path().generic_string();
        std::string file = it.path().generic_string().substr(20);
//        std::cout << file << std::endl;
//        if (file.compare(".gitkeep"))
        _saveName.push_back(file);
    }
    return _saveName;
}

template<typename T, typename U>
std::vector<std::string> indie::LoadingSave<T, U>::getRecentSave() const
{
    return _recentSave;
}

template<typename T, typename U>
void indie::LoadingSave<T, U>::setRecentSave()
{
    std::vector<std::time_t> tri;

    for (std::string &s : _saveName) {
        struct std::tm tm;
        std::istringstream ss(s);
        ss >> std::get_time(&tm, "%a %b %d %T %Y");
        std::time_t time = mktime(&tm);
        tri.push_back(time);
        ss.clear();
    }
    std::sort(tri.begin(), tri.end());
    if (tri.size() >= 1)
        _recentSave.push_back(std::ctime(&tri[tri.size()-1]));
    if (tri.size() >= 2)
        _recentSave.push_back(std::ctime(&tri[tri.size()-2]));
    if (tri.size() >= 3)
        _recentSave.push_back(std::ctime(&tri[tri.size()-3]));
    if (tri.size() == 0)
        std::cout << "THERE IS NOTHING TO LOAD" << std::endl;
}

template<typename T, typename U>
void indie::LoadingSave<T, U>::setPath()
{
    _path = _recentSave[which];
}

template<typename T, typename U>
void indie::LoadingSave<T, U>::setWhich0()
{
    which = 0;
    load();
}

template<typename T, typename U>
void indie::LoadingSave<T, U>::setWhich1()
{
    which = 1;
    load();
}

template<typename T, typename U>
void indie::LoadingSave<T, U>::setWhich2()
{
    which = 2;
    load();
}

#endif /* !LOADINGSAVE_HPP_ */
