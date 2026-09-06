/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Conf
*/

#include <iostream>
#include <fstream>

#include "abstraction/access.hpp"
#include "Conf.hpp"
#include "exception/AException.hpp"

    //! Public
Zia::Conf::Conf(const std::string &nameFile)
: _nameFile(nameFile)
{
    if (access(nameFile.c_str(), 0) == -1)
        throw AException("Json", "Wrong config file: " + nameFile);
    try {
        std::ifstream file(nameFile);

        if (!file.is_open())
            throw AException("Json", "Can't open config file");
        file >> _json;
        file.close();
    } catch(nlohmann::detail::parse_error &excep) {
        throw AException("Json", excep.what());
    } catch(...) {
        throw AException("Json", "receive throw during read config file");
    }
}

void Zia::Conf::setNameFile(const std::string &nameFile) noexcept
{
    if (!nameFile.size())
        return;
    _nameFile = nameFile;
}

const std::string &Zia::Conf::getNameFile(void) const
{
    return _nameFile;
}

std::unique_ptr<Zia::Json::IObject> Zia::Conf::read(void) const
{
    if (access(_nameFile.c_str(), 0) == -1)
        return nullptr;
    try {
        std::ifstream file(_nameFile);
        nlohmann::json jjjson;

        if (!file.is_open())
            return nullptr;
        file >> jjjson;
        file.close();
        return (std::make_unique<Zia::Json::Object>(jjjson));
    } catch(...) {
        return nullptr;
    }
    return nullptr;
}

void Zia::Conf::write(const Json::IObject &jsonObject)
{
    if (!dynamic_cast<const Zia::Json::Object *>(&jsonObject))
        return;
    Zia::Json::Object obj(dynamic_cast<const Zia::Json::Object *>(&jsonObject));
    std::string json;

    obj >> json;
    if (access(_nameFile.c_str(), 0) == -1)
        return;
    try {
        std::ofstream file(_nameFile);

        if (!file.is_open())
            return;
        file << json;
        file.close();
    } catch(...) {
    }
}