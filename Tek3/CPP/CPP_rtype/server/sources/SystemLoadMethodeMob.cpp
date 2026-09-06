/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemLoadMethodeMob
*/

#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <dlfcn.h>
#include <dirent.h>

#include "systems/LoadMethodeMob.hpp"
#include "Server.hpp"
#include "singleton/ECManager.hpp"
#include "libMobs/includes/ILibMob.hpp"

void rtype::system::LoadMethodeMob::update(const Entity &id)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    uint16_t counterLib = 0;
    char buff[100] = {0};
    DIR *fd = opendir("./server/lib/");
    void *handleFile = nullptr;
    createMethodeMob fnctCreate = nullptr;

    if (id.size()) {}
    if (!fd)
        return;
    for (struct dirent *entry = readdir(fd); entry; entry = readdir(fd)) {
        if (std::regex_match(entry->d_name, std::regex("lib\\S+.so"))) {
            memset(buff, '\0', 100);
            strcpy(buff, "./server/lib/");
            strcat(buff, entry->d_name);
            if (!(handleFile = dlopen(buff, RTLD_NOW))) {
                std::cerr << "Can't Open Dynamic Lib: " << dlerror() << std::endl;
                continue;
            }
            if (!(fnctCreate = (createMethodeMob)dlsym(handleFile, "create"))) {
                std::cerr << "Can't Take Methode Dynamic Lib: " << dlerror() << std::endl;
                continue;
            }
            std::cout << "[LIB]: Success Loading Lib: " << entry->d_name << std::endl;
            handler.getComponent<rtype::component::ListMethodeMob>(id)._list.push_back(((*fnctCreate)()));
            dlclose(handleFile);
        }
    }
    closedir(fd);
}
