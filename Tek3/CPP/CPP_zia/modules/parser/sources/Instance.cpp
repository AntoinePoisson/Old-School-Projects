/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Instance
*/

#include "Instance.hpp"
#include "api/context/Request.hpp"
#include "exception/AException.hpp"
#include <regex>
#include <iostream>

Zia::Instance::Instance(Zia::IInput &input, Zia::ILogger &log, Zia::IRequest::IEmitter &requestEmitter) : _input(input), _log(log), _requestEmitter(requestEmitter)
{
    _allowedMethods = std::vector<std::string>{"GET","HEAD","POST","DELETE"};
}

Zia::Instance::~Instance()
{
}

size_t Zia::Instance::checkIfRequestHasTwoCRLF()
{
    for (size_t i = 0; i != _buf.length(); i++) {
        if (i + 3 != _buf.length() && _buf[i] == '\r') {
            if (_buf[i + 1] == '\n' && _buf[i + 2] == '\r' && _buf[i + 3] == '\n') {
                _isCompletedRequest = true;
                return (i + 4); // return position after \r\n\r\n
            }
        }
    }
    _isCompletedRequest = false;
    return (0);
}

void Zia::Instance::parseByCRLF()
{
    std::string tmp = "";

    for (size_t i = 0; i != _buf.length() && i != _endpos; i++) {
        if (i + 1 != _buf.length() && _buf[i] == '\r' && _buf[i + 1] == '\n') {
            _fullRequest.push_back(tmp);
            tmp.clear();
            i += 1;
        } else
            tmp += _buf[i];
    }
}

std::vector<std::string> Zia::Instance::seperateStringAt(const std::string &str, const char c)
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

std::string Zia::Instance::toLowerCase(const std::string str)
{
    std::string tmp;

    for (size_t i = 0; i != str.length(); i++)
        tmp += tolower(str[i]);
    return (tmp);
}

bool Zia::Instance::checkFirstLine()
{
    std::string line = *_fullRequest.begin();
    std::vector<std::string> firstLine = seperateStringAt(line, ' ');

    if (firstLine.size() != 3)
        return false;

    /*Check method*/

    _method = *firstLine.begin();
    auto pos = std::find(_allowedMethods.begin(), _allowedMethods.end(), _method);

    if (pos == _allowedMethods.end()) {
        cleanBuf(_endpos);
        throw AException("Module Parser", "Method not implemented", 501);
    }
    _log.log("\n/====================================\\\n - Parser:");
    _log.log("Parsing: Method OK.");

    /*Check URL*/

    std::string url = *(firstLine.begin() + 1);
    if (url.length() == 0)
        return false;
    std::vector<std::string> urlLink = seperateStringAt(url, '?');
    std::regex exp("^[a-zA-Z0-9_-]+=([a-zA-Z0-9_-]+)*(&[a-zA-Z0-9_-]+=([a-zA-Z0-9_-]+)*)*");

    if (urlLink.size() == 2) {
        std::string query = *(urlLink.begin() + 1);
        if (std::regex_match(query, exp) == false)
            return false;
    } else if (urlLink.size() > 2)
        return false;
    _log.log("Parsing: URL OK.");

    /*Check HTTP version*/

    std::string version = *(firstLine.begin() + 2);
    if (version.compare("HTTP/1.1") != 0) {
        cleanBuf(_endpos);
        throw AException("Module Parser", "HTTP protocol version not supported", 505);
    }
    _log.log("Parsing: HTTP version OK.");
    return true;
}

bool Zia::Instance::checkRequest()
{
    if (checkFirstLine() == false)
        return false;

    /*Check headers*/
    std::regex exp("^[a-zA-Z]*(-[a-zA-Z]*)*");

    for (std::vector<std::string>::const_iterator p = _fullRequest.begin() + 1; p != _fullRequest.end() && (*p).length() != 0; p++) {
        std::vector<std::string> headers = seperateStringAt(*p, ':');
        std::string headerName = *headers.begin();

        if (headers.size() < 2 || std::regex_match(headers[0], exp) == false)
            return false;
        if (toLowerCase(headerName) == "transfer-encoding")
            _hasTransferEncoding = true;
        else if (toLowerCase(headerName) == "content-length") {
            _hasContentLength = true;
            _contentLength = std::stoul((*(headers.end() - 1)).c_str());
        }
    }
    _log.log("Parsing: Headers OK.");
    if (_method == "POST" && _hasTransferEncoding == false && _hasContentLength == false) {
        cleanBuf(_endpos);
        throw AException("Module Parser", "POST request needs a Content-Length field", 411);
    }
    return true;
}

size_t Zia::Instance::addChunks(size_t endpos, std::string tmp, size_t loopCount, size_t chunkSize)
{
    size_t i = endpos;

    for (; i != _buf.length(); i++) {
        if (i + 1 != _buf.length() && _buf[i] == '\r' && _buf[i + 1] == '\n') {
            if (loopCount % 2 == 0) {
                try {
                    chunkSize = std::stoul(tmp.c_str());
                } catch (...) {
                    return (0);
                }
            } else {
                if (chunkSize == 0 && tmp.length() == 0) //found end of chunk OK
                    return (i + 2); // to skip \r\n
                if (chunkSize != tmp.length())
                    return (0);
                _fullRequest.push_back(tmp);
            }
            tmp.clear();
            loopCount++;
            i++;
        } else
            tmp += _buf[i];
    }
    _log.log("Parsing: Chunk body missing end.");

    /*Reread from input to find the end*/
    char str[1000] = {0};
    _input.read(1000, str);

    std::string bis(str);
    if (bis.length() == 0)
        return (0);
    _buf += str;
    addChunks(i, tmp, loopCount, chunkSize);
    return (0);
}

bool Zia::Instance::addBody(size_t endpos, std::string tmp, size_t count)
{
    size_t i = endpos;

    for (; i != _buf.length(); i++) {
        if (count == _contentLength) {
            tmp += _buf[i];
            _fullRequest.push_back(tmp);
            return true;
        } else
            tmp += _buf[i];
        count += 1;
    }
    _log.log("Parsing: Not enough in buffer for body.");

    /*Reread from input to find the end*/
    char str[1000] = {0};
    _input.read(1000, str);

    std::string bis(str);
    if (bis.length() == 0)
        return false;
    _buf += str;
    addBody(i, tmp, count);
    return false;
}

void Zia::Instance::cleanBuf(size_t endpos)
{
    std::string tmp(_buf.substr(endpos, _buf.length() - 1));
    _buf.clear();
    _buf = tmp;
    _fullRequest.clear();
    _isCompletedRequest = false;
}

void Zia::Instance::parse()
{
    char str[1000] = {0};

    _input.read(1000, str);
    _buf += str;
    _endpos = checkIfRequestHasTwoCRLF();
    if (_isCompletedRequest == false) // Allow to loop on parser()
        return;
    parseByCRLF();
    if (checkRequest() == false) {
        cleanBuf(_endpos);
        throw AException("Module Parser", "Invalid request syntax", 400);
    }
    if (_hasTransferEncoding == true) {
        _endpos = addChunks(_endpos);

        if (_endpos == 0) {
            _buf.clear();
            throw AException("Module Parser", "Invalid chunk syntax");
        }
        _log.log("Parsing: Chunk body OK.");
    } else if (_hasContentLength == true) {
        if (addBody(_endpos) == false) {
            _buf.clear();
            throw AException("Module Parser", "Invalid body");
        }
        _log.log("Parsing: Body OK.");
    }

    // std::cout << "START" << std::endl;
    // for (std::vector<std::string>::const_iterator p = _fullRequest.begin(); p != _fullRequest.end(); p++) {
    //     std::cout << "$" << *p << "$" << std::endl;
    // }
    // std::cout << "END" << std::endl;
    _log.log("Creating Request...");
    Zia::Request::Emitter *tmp = dynamic_cast<Zia::Request::Emitter *>(&_requestEmitter);
    std::string ip = "0.0.0.0";
    if (tmp != nullptr)
        ip = tmp->getIp();
    Request *req = new Request(_log, _fullRequest, ip);
    _requestEmitter.emit(*req);
    cleanBuf(_endpos + _contentLength);
    //std::cout << "Rest in buf " << _buf << "$" << std::endl;
}