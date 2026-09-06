/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Request
*/

#include <iostream>

#include "Request.hpp"
#include "../../exception/AException.hpp"

    //! Public
Zia::Request::Request(Zia::ILogger &log, const std::vector<std::string> &req, const std::string &ip)
: _log(log), _ipClient(ip)
{
    _log.log("In Request class");

    /*Get method*/

    std::vector<std::string> firstLine = seperateStringAt(*req.begin(), ' ');
    _method = firstLine.at(0);
    _log.log("Method is " + _method);

    /*Get fullURL, filename and query args*/

    _fullURL = firstLine.at(1);
    _log.log("Full URL is " + _fullURL);

    std::vector<std::string> url = seperateStringAt(_fullURL, '?');
    _filename = *url.begin();
    _log.log("Filename is " + _filename);

        /*If there are query args*/

    if (url.size() == 2) {
        std::vector<std::string> queries = seperateStringAt(*(url.begin() + 1), '&');

        for (std::vector<std::string>::const_iterator p = queries.begin(); p != queries.end(); p++) {
            _log.log("Query is " + *p);
            std::vector<std::string> query = seperateStringAt(*p, '=');

            if (query.size() == 1)
                _arguments.insert(std::make_pair(*p, ""));
            else
                _arguments.insert(std::make_pair(*query.begin(), *(query.begin() + 1)));
        }
    }

    /*Get headers and body*/

    for (std::vector<std::string>::const_iterator p = req.begin() + 1; p != req.end(); p++) {
        size_t index = p - req.begin();
            /*Get body*/
        if ((*p).length() == 0 && index + 1 != req.size()) {
            p++;
            _body = std::vector<char>((*p).begin(), (*p).end());
            _log.log("Body is:");
            _log.log(*p);
            std::cout << "Body is:" << std::endl;
            for (std::vector<char>::const_iterator q = _body.begin(); q != _body.end(); q++)
                std::cout << *q << std::endl;
            break;
        } else if ((*p).length() == 0) {
            break;
        }
            /*Get header*/
        _log.log("Header is " + *p);
        std::vector<std::string> header = seperateStringAt(*p, ':');
        if (header.size() >= 2 && header[1][0] == ' ' && header[1].size() > 1) {
            header[1] = &header[1][1];
        }
        _headers.insert(std::make_pair(*header.begin(), *(header.begin() + 1)));
    }
    _log.log("\\=====================================/\n");
}

Zia::Request::~Request()
{
}

std::vector<std::string> Zia::Request::seperateStringAt(const std::string &str, const char c)
{
    std::vector<std::string> vect;
    std::string tmp = "";

    for (size_t i = 0; i != str.length(); i++) {
        if (str[i] == c) {
            vect.push_back(tmp);
            tmp.clear();
        } else
            tmp += str[i];
    }
    if (tmp.length() != 0)
        vect.push_back(tmp);
    return (vect);
}

const std::string &Zia::Request::getClientIP(void) const
{
    return _ipClient;
}

const std::string &Zia::Request::getProtocol(void) const
{
    static std::string proto = "HTTP/1.1";

    return proto;
}

std::vector<std::string> Zia::Request::getArgumentsKeys(void) const
{
    std::vector<std::string> res;

    for (auto el : _arguments)
        res.push_back(el.first);
    return res;
}

const std::string &Zia::Request::getURL(void) const
{
    return _fullURL;
}

std::vector<std::string> Zia::Request::getHeaderKeys(void) const
{
    std::vector<std::string> res;

    for (auto el : _headers)
        res.push_back(el.first);
    return res;
}

const std::string &Zia::Request::getMethod(void) const
{
    return _method;
}

const std::string &Zia::Request::getFilename(void) const
{
    return _filename;
}

const std::string *Zia::Request::getArgument(const std::string &name) const
{
    if (_arguments.find(name) == _arguments.end())
        return nullptr;
    if (_arguments.at(name).length() != 0)
        return &_arguments.at(name);
    return nullptr;
}

const std::string *Zia::Request::getHeader(const std::string &key) const
{
    if (_headers.find(key) == _headers.end())
        return nullptr;
    if (_headers.at(key).length() != 0)
        return &_headers.at(key);
    return nullptr;
}

const std::vector<char> *Zia::Request::getBody(void) const
{
    if (_body.size() != 0)
        return &_body;
    return nullptr;
}

Zia::Request::Emitter::Emitter(Zia::Core *core, std::shared_ptr<Zia::IConnection> client, std::shared_ptr<bool> &stopped, std::shared_ptr<std::chrono::steady_clock::time_point> &clock, std::shared_ptr<bool> &oneRequest)
: _core(core), _client(client), _stopped(stopped), _clock(clock), _oneRequest(oneRequest)
{}

const std::string &Zia::Request::Emitter::getIp(void)
{
    return _client->getRemoteIP();
}

void Zia::Request::Emitter::emit(const IRequest &request)
{
    _client->log("[Emitter]: Before Emitting Request...");
    *_oneRequest = true;
    _clock = std::make_shared<std::chrono::steady_clock::time_point>(std::chrono::steady_clock::now());
    _core->addNewRequest(&request, _client, _stopped);
    _client->log("[Emitter]: ...After Emitting Request");
}