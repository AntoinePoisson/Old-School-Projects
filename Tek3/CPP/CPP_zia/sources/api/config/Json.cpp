/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Json
*/

#include <fstream>

#include "abstraction/access.hpp"
#include "Json.hpp"
#include "../../exception/AException.hpp"

    //! Public
Zia::Json::Object::Object(nlohmann::json json)
{
    try {
        _json = json;
    } catch(nlohmann::detail::parse_error &excep) {
        throw AException("Json", excep.what());
    }
}

Zia::Json::Object::Object(const Object *obj)
{
    if (obj == nullptr)
        throw AException("Json", "Receive null in constructor parameter");
    try {
        _json = obj->_json;
    } catch(nlohmann::detail::parse_error &excep) {
        throw AException("Json", excep.what());
    }
}

Zia::Json::Object::Object(const std::string &nameFile)
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
        throw AException("Json", "Thow Receive ??");
    }
}

void Zia::Json::Object::operator=(const Object &element)
{
    this->_json = element._json;
}

void Zia::Json::Object::operator=(nlohmann::json json)
{
    this->_json = json;
}

std::vector<std::string> Zia::Json::Object::getKeys(void) const
{
    std::vector<std::string> res;

    for (auto &x: _json.items()) {
        res.push_back(x.key());
    }
    return res;
}

std::optional<Zia::Json::Number> Zia::Json::Object::getNumber(const std::string &args) const
{
    try {
        if ((_json.find(args) != _json.end()) && !_json[args].is_null()) {
            return std::optional<Zia::Json::Number>(_json.at(args));
        }
    } catch(...) {
        return std::nullopt;
    }
    return std::nullopt;
}

std::optional<Zia::Json::Integer> Zia::Json::Object::getInteger(const std::string &args) const
{
    try {
        if ((_json.find(args) != _json.end()) && !_json[args].is_null()) {
            return std::optional<Zia::Json::Integer>(_json.at(args));
        }
    } catch(...) {
        return std::nullopt;
    }
    return std::nullopt;
}

std::optional<Zia::Json::String> Zia::Json::Object::getString(const std::string &args) const
{
    try {
        if ((_json.find(args) != _json.end()) && !_json[args].is_null()) {
            return std::optional<Zia::Json::String>(_json.at(args));
        }
    } catch(...) {
        return std::nullopt;
    }
    return std::nullopt;
}

std::optional<Zia::Json::Bool> Zia::Json::Object::getBool(const std::string &args) const
{
    try {
        if ((_json.find(args) != _json.end()) && !_json[args].is_null()) {
            return std::optional<Zia::Json::Bool>(_json.at(args));
        }
    } catch(...) {
        return std::nullopt;
    }
    return std::nullopt;
}

bool Zia::Json::Object::isNull(const std::string &args) const
{
    try {
        if ((_json.find(args) != _json.end()) && _json[args].is_null()) {
            return true;
        }
    } catch(...) {
        return false;
    }
    return false;
}

bool Zia::Json::Object::isUndefined(const std::string &args) const
{
    try {
        if ((_json.find(args) == _json.end())) {
            return true;
        }
    } catch(...) {
        return false;
    }
    return false;
}

const Zia::Json::IObject* Zia::Json::Object::getObject(const std::string &args) const
{
    try {
        if ((_json.find(args) == _json.end()) || (_json[args].is_object() == false)) {
            return nullptr;
        }
        return (new Zia::Json::Object(nlohmann::json(_json[args])));
    } catch(...) {
        return nullptr;
    }
    return nullptr;
}

const Zia::Json::IArray* Zia::Json::Object::getArray(const std::string &args) const
{
    try {
        if ((_json.find(args) == _json.end()) || (_json[args].is_array() == false)) {
            return nullptr;
        }
        return (new Zia::Json::Array(nlohmann::json(_json[args])));
    } catch(...) {
        return nullptr;
    }
    return nullptr;
}

void Zia::Json::Object::setNumber(const std::string &args, Number value)
{
    if (!args.size())
        return;
    try {
        _json += {args, value};
    } catch(...) {
    }
}

void Zia::Json::Object::setInteger(const std::string &args, Integer value)
{
    if (!args.size())
        return;
    try {
        _json += {args, value};
    } catch(...) {
    }
}

void Zia::Json::Object::setString(const std::string &args, const String &value)
{
    if (!args.size())
        return;
    try {
        _json += {args, value};
    } catch(...) {
    }
}

void Zia::Json::Object::setBool(const std::string &args, Bool value)
{
    if (!args.size())
        return;
    try {
        _json += {args, value};
    } catch(...) {
    }
}

void Zia::Json::Object::setNull(const std::string &args)
{
    if (!args.size())
        return;
    try {
        _json += {args, nlohmann::detail::value_t::null};
    } catch(...) {
    }
}

void Zia::Json::Object::setUndefined(const std::string &args)
{
    if (!args.size())
        return;
    try {
        _json += {args, nlohmann::detail::value_t::null};
    } catch(...) {
    }
}

Zia::Json::IObject* Zia::Json::Object::getObject(const std::string &args)
{
    Zia::Json::Object* res = nullptr;

    if ((_json.find(args) == _json.end()) || (_json[args].is_object() == false)) {
        return res;
    }
    try {
        res = new Zia::Json::Object(nlohmann::json(_json[args]));
    } catch(...) {
        return res;
    }
    return res;
}

Zia::Json::IArray* Zia::Json::Object::getArray(const std::string &args)
{
    Zia::Json::Array* res = nullptr;

    if ((_json.find(args) == _json.end()) || (_json[args].is_array() == false)) {
        return res;
    }
    try {
        res = new Zia::Json::Array(nlohmann::json(_json[args]));
    } catch(...) {
        return res;
    }
    return res;
}

Zia::Json::IObject& Zia::Json::Object::createEmptyObject(const std::string &args)
{
    try {
        nlohmann::json objEmpty = {args, nlohmann::json::object({})};
        static Zia::Json::Object res(objEmpty);

        res = objEmpty;
        _json += {args, nlohmann::json::object({})};
        return res;
    } catch(...) {
        static Zia::Json::Object res(nlohmann::json({args, nlohmann::json::object({})}));
        return res;
    }
}

Zia::Json::IArray& Zia::Json::Object::createEmptyArray(const std::string &args)
{
    try {
        nlohmann::json objEmpty = {args, nlohmann::json::array({})};
        static Zia::Json::Array res(objEmpty);

        res = objEmpty;
        _json += {args, nlohmann::json::array({})};
        return res;
    } catch(...) {
        static Zia::Json::Array res(nlohmann::json({args, nlohmann::json::array({})}));
        return res;
    }
}

void Zia::Json::Object::clear(void)
{
    try {
        _json.erase(_json.begin(), _json.end());
    } catch(...) {
    }
}




    //? Array
Zia::Json::Array::Array(nlohmann::json json)
{
    try {
        _json = json;
    } catch(nlohmann::detail::parse_error &excep) {
        throw AException("Json", excep.what());
    }
}

Zia::Json::Array::Array(const Array *obj)
{
    if (obj == nullptr)
        throw AException("Json", "Receive null in constructor parameter");
    try {
        _json = obj->_json;
    } catch(nlohmann::detail::parse_error &excep) {
        throw AException("Json", excep.what());
    }
}

Zia::Json::Array::Array(const std::string &nameFile)
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
        throw AException("Json", "Thow Receive ??");
    }
}

void Zia::Json::Array::operator=(const Array &element)
{
    this->_json = element._json;
}

void Zia::Json::Array::operator=(nlohmann::json json)
{
    this->_json = json;
}

size_t Zia::Json::Array::getSize(void) const
{
    return _json.size();
}

void Zia::Json::Array::remove(size_t index)
{
    if (index > _json.size())
        return;
    try {
        _json.erase(getIndex(index));
    } catch(...) {
    }
}

std::optional<Zia::Json::Number> Zia::Json::Array::getNumber(size_t args) const
{
    try {
        std::string el(getIndex(args));

        if ((_json.find(el) != _json.end()) && !_json[el].is_null()) {
            return std::optional<Zia::Json::Number>(_json.at(el));
        }
    } catch(...) {
        return std::nullopt;
    }
    return std::nullopt;
}

std::optional<Zia::Json::Integer> Zia::Json::Array::getInteger(size_t args) const
{
    try {
        std::string el(getIndex(args));

        if ((_json.find(el) != _json.end()) && !_json[el].is_null()) {
            return std::optional<Zia::Json::Integer>(_json.at(el));
        }
    } catch(...) {
        return std::nullopt;
    }
    return std::nullopt;
}

std::optional<Zia::Json::String> Zia::Json::Array::getString(size_t args) const
{
    try {
        std::string el(getIndex(args));

        if ((_json.find(el) != _json.end()) && !_json[el].is_null()) {
            return std::optional<Zia::Json::String>(_json.at(el));
        }
    } catch(...) {
        return std::nullopt;
    }
    return std::nullopt;
}

std::optional<Zia::Json::Bool> Zia::Json::Array::getBool(size_t args) const
{
    try {
        std::string el(getIndex(args));

        if ((_json.find(el) != _json.end()) && !_json[el].is_null()) {
            return std::optional<Zia::Json::Bool>(_json.at(el));
        }
    } catch(...) {
        return std::nullopt;
    }
    return std::nullopt;
}

bool Zia::Json::Array::isNull(size_t args) const
{
    try {
        std::string el(getIndex(args));

        if ((_json.find(el) != _json.end()) && _json[el].is_null()) {
            return true;
        }
    } catch(...) {
        return false;
    }
    return false;
}

bool Zia::Json::Array::isUndefined(size_t args) const
{
    try {
        std::string el(getIndex(args));

        if ((_json.find(el) == _json.end())) {
            return true;
        }
    } catch(...) {
        return false;
    }
    return false;
}

const Zia::Json::IObject* Zia::Json::Array::getObject(size_t args) const
{
    try {
        if ((args >= _json.size()) || (_json[args].is_object() == false)) {
            return nullptr;
        }
        return (new Zia::Json::Object(nlohmann::json(_json[args])));
    } catch(...) {
        return nullptr;
    }
    return nullptr;
}

const Zia::Json::IArray* Zia::Json::Array::getArray(size_t args) const
{
    try {
        if ((args >= _json.size()) || (_json[args].is_array() == false)) {
            return nullptr;
        }
        return (new Zia::Json::Array(nlohmann::json(_json[args])));
    } catch(...) {
        return nullptr;
    }
    return nullptr;
}

void Zia::Json::Array::setNumber(size_t args, Number value)
{
    try {
        _json += {std::to_string(args), value};
    } catch(...) {
    }
}

void Zia::Json::Array::setInteger(size_t args, Integer value)
{
    try {
        _json += {std::to_string(args), value};
    } catch(...) {
    }
}

void Zia::Json::Array::setString(size_t args, const String &value)
{
    try {
        _json += {std::to_string(args), value};
    } catch(...) {
    }
}

void Zia::Json::Array::setBool(size_t args, Bool value)
{
    try {
        _json += {std::to_string(args), value};
    } catch(...) {
    }
}

void Zia::Json::Array::setNull(size_t args)
{
    try {
        _json += {std::to_string(args), nlohmann::detail::value_t::null};
    } catch(...) {
    }
}

void Zia::Json::Array::setUndefined(size_t args)
{
    try {
        _json += {std::to_string(args), nlohmann::detail::value_t::null};
    } catch(...) {
    }
}

Zia::Json::IObject* Zia::Json::Array::getObject(size_t args)
{
    try {
        if ((args >= _json.size()) || (_json[args].is_object() == false)) {
            return nullptr;
        }
        return (new Zia::Json::Object(nlohmann::json(_json[args])));
    } catch(...) {
        return nullptr;
    }
    return nullptr;
}

Zia::Json::IArray* Zia::Json::Array::getArray(size_t args)
{
    try {
        if ((args >= _json.size()) || (_json[args].is_array() == false)) {
            return nullptr;
        }
        return (new Zia::Json::Array(nlohmann::json(_json[args])));
    } catch(...) {
        return nullptr;
    }
    return nullptr;
}

Zia::Json::IObject& Zia::Json::Array::createEmptyObject(size_t args)
{
    try {
        nlohmann::json objEmpty = {std::to_string(args), nlohmann::json::object({})};
        static Zia::Json::Object res(objEmpty);

        res = objEmpty;
        _json += {std::to_string(args), nlohmann::json::object({})};
        return res;
    } catch(...) {
        static Zia::Json::Object res(nlohmann::json({std::to_string(args), nlohmann::json::object({})}));
        return res;
    }
}

Zia::Json::IArray& Zia::Json::Array::createEmptyArray(size_t args)
{
    try {
        nlohmann::json objEmpty = {std::to_string(args), nlohmann::json::array({})};
        static Zia::Json::Array res(objEmpty);

        res = objEmpty;
        _json += {std::to_string(args), nlohmann::json::array({})};
        return res;
    } catch(...) {
        static Zia::Json::Array res(nlohmann::json({std::to_string(args), nlohmann::json::array({})}));
        return res;
    }
}

void Zia::Json::Array::clear(void)
{
    try {
        _json.erase(_json.begin(), _json.end());
    } catch(...) {
    }
}

    //! Private
const std::string& Zia::Json::Array::getIndex(size_t index) const
{
    static std::string res("");
    size_t counter = 0;

    res = "";
    try {
        if (index > _json.size())
            return res;
        for (auto el : _json.items()) {
            if (counter == index)
                break;
            res = el.key();
            counter++;
        }
        return res;
    } catch(...) {
        return res;
    }
}