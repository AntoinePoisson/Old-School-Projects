/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LoadHandling
*/

#include "LoadHandling.hpp"

    // Methode
template<class T>
void Arcade::LoadHandling<T>::load(T pathLib, T pathGames, T pathScore, T libParam)
{
    this->pathLib = pathLib;
    this->pathGames = pathGames;
    this->libParam = libParam;
    this->pathScore = pathScore;
    loadGames();
    loadLibs(libParam);
    loadScore();
}

template<class T>
bool Arcade::LoadHandling<T>::checkFunctLib(bool isGameLib, T nameLib)
{
    void *handleFile = dlopen(nameLib.c_str(), RTLD_NOW);
    void *fnct = nullptr;

    if (!handleFile) {
        std::cout << dlerror() << std::endl;
        return (false);
    }
    fnct = dlsym(handleFile, "create");
    if (!fnct) {
        if (isGameLib)
            std::cout << "The game: "<< nameLib << " doesn't have create methode." << std::endl;
        else
            std::cout << "The lib: "<< nameLib << " doesn't have create methode." << std::endl;
        return (false);    
    }
    dlclose(handleFile);
    return (true);
}

template<class T>
void Arcade::LoadHandling<T>::loadLibs(T libParam)
{
    uint16_t counterLib = 0;
    char buff[100] = {0};
    DIR *fd = opendir(pathLib.c_str());

    if (!fd)
        throw Error("loadLibs", "lib not find.");
    for (struct dirent *entry = readdir(fd); entry; entry = readdir(fd)) {
        if (std::regex_match(entry->d_name, std::regex("lib_arcade_\\S+.so"))) {
            memset(buff, '\0', 100);
            strcpy(buff, pathLib.c_str());
            strcat(buff, entry->d_name);
            if (std::regex_search(libParam, std::regex(entry->d_name))) {
                continue;
            }
            if (Arcade::LoadHandling<T>::checkFunctLib(false, buff)) {
                handleLibs.push_back(buff);
                std::cout << "Lib Success Load: " << buff << std::endl;
                counterLib++;
            }
        }
    }
    if (counterLib <= 1)
        throw Error("loadLibs", "not enough library find.");
    closedir(fd);
}

template<class T>
void Arcade::LoadHandling<T>::loadGames()
{
    uint16_t counterLib = 0;
    char buff[100] = {0};    
    DIR *fd = opendir(pathGames.c_str());

    if (!fd)
        throw Error("loadGames", "games not find.");
    for (struct dirent *entry = readdir(fd); entry; entry = readdir(fd)) {
        if (std::regex_match(entry->d_name, std::regex("lib_arcade_\\S+.so"))) {
            memset(buff, '\0', 100);
            strcpy(buff, pathGames.c_str());
            strcat(buff, entry->d_name);
            if (Arcade::LoadHandling<T>::checkFunctLib(true, buff)) {
                handleGames.push_back(buff);
                std::cout << "Game Success Load: " << entry->d_name << std::endl;
                counterLib++;
            }
        }
    }
    if (counterLib <= 1)
        throw Error("loadGames", "not enough games find.");
    closedir(fd);
}

template<class T>
void Arcade::LoadHandling<T>::loadScore()
{
    int i = 0;
    std::ifstream file(pathScore, std::ifstream::in);
    std::string line("");
    std::string tmp("");

    if (!file)
        throw Error("loadScore", "error with score file");
    std::getline(file, line);
    if (line == "" || !std::regex_match(line, std::regex("\\S+=\\d+")))
        throw Error("loadScore", "error with score file");
    for (; line[i] != '='; i++)
        highScoreName += line[i];
    for (++i; line[i]; i++)
        tmp += line[i];
    highScoreValue = stoi(tmp);
    file.close();
}

template<class T>
std::vector<T> Arcade::LoadHandling<T>::getLibs()
{
    return (handleLibs);
}
template<class T>
std::vector<T> Arcade::LoadHandling<T>::getGames()
{
    return (handleGames);
}
template<class T>
T Arcade::LoadHandling<T>::getHighScoreName()
{
    return (highScoreName);
}

template<class T>
uint64_t Arcade::LoadHandling<T>::getHighScoreValue()
{
    return (highScoreValue);
}


    // Methode Template
template void Arcade::LoadHandling<std::string>::load(std::string pathLib, std::string pathGames, std::string pathScore, std::string libParam);
template bool Arcade::LoadHandling<std::string>::checkFunctLib(bool isGameLib, std::string nameLib);
template void Arcade::LoadHandling<std::string>::loadLibs(std::string libParam);
template void Arcade::LoadHandling<std::string>::loadGames();
template void Arcade::LoadHandling<std::string>::loadScore();
template std::vector<std::string> Arcade::LoadHandling<std::string>::getLibs();
template std::vector<std::string> Arcade::LoadHandling<std::string>::getGames();
template std::string Arcade::LoadHandling<std::string>::getHighScoreName();
template uint64_t Arcade::LoadHandling<std::string>::getHighScoreValue();