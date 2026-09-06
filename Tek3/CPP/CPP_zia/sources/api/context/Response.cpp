/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Response
*/

#include "Response.hpp"
#include "../../Zia.hpp"

    //! Public
Zia::Response::Response(std::shared_ptr<bool> &status)
: _statusModule(status), _code(200), _modif(false)
{
    *_statusModule = false;
}

bool &Zia::Response::checkModifictionByModule(void)
{
    return _modif;
}

void Zia::Response::abortPipeline(void)
{
    _modif = true;
    *_statusModule = true;
}

size_t Zia::Response::getCode(void) const
{
    return _code;
}

void Zia::Response::setCode(size_t code)
{
    _modif = true;
    _code = code;
}

const std::string *Zia::Response::getHeader(const std::string &key) const
{
    if (key == BYPASS_API_LIMITATION) {
        if (_header.empty())
            return nullptr;
        std::string res;
        for (auto header : _header) {
            res += header.first + ": " + header.second + "\r\n";
        }
        return new std::string(res);
    }
    if (_header.find(key) == _header.end())
        return nullptr;
    return &(_header.find(key)->second);
}

void Zia::Response::setHeader(const std::string &key, const std::string &value)
{
    _modif = true;
    _header[key] = std::string(value);
}

const std::vector<char> *Zia::Response::getBody(void) const
{
    return &_body;
}

void Zia::Response::setBody(const std::vector<char> &body)
{
    _modif = true;
    _body = body;
}
