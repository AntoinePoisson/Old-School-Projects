/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** HandlerWrapper
*/

#ifdef _WIN32
    #include <io.h>
#else
    #include <unistd.h>
#endif
#include <fstream>
#include <cstring>
#include <iostream>
#include <optional>
#include "HandlerWrapper.hpp"

HandlerWrapper::HandlerWrapper()
{
}

HandlerWrapper::~HandlerWrapper()
{
}

void HandlerWrapper::sendRes(Zia::IResponse &res, size_t code, std::string data)
{
    std::vector<char> body;

    res.setCode(code);
    res.setHeader("Content-Type", "text/plain; charset=utf-8");
    for (char &a : data)
        body.push_back(a);
    res.setBody(body);
}

bool HandlerWrapper::isPathPrivate(Zia::IResponse &res)
{
    std::ifstream file;
    std::string line;
    std::string pathPrivate = "./resources/pages/.htaccess";

    file.open(pathPrivate);

    if (!file) {
        sendErrorRes(res, 404, pathPrivate + " Doesn't exist");
        return true;
    }
    while (std::getline(file, line)) {
        std::string tmp;
        if (line[0] != '/')
            tmp = path + '/' + line;
        else
            tmp = path + line;
        if (filePath.compare(tmp) == 0) {
            sendErrorRes(res, 403, tmp + " Has not access");
            return true;
        }
    }
    file.close();
    return false;
}

std::string HandlerWrapper::getConfPath(Zia::IConf &conf, std::string objectName)
{
    //check read and getString
    auto json = conf.read();
    if (json == nullptr)
        return "FAILED TO READ JSON CONF";

    auto fat = json->getObject(objectName);
    if (fat == nullptr)
        return "FAILED TO READ OBJECT CONF";

    auto confPath = fat->getString("path");
    if (confPath == std::nullopt)
        return "FAILED TO GET STRING";

    if(access((*confPath).data(), R_OK) == -1)
        return "WRONG CONF PATH";

    return *confPath;
}


void HandlerWrapper::sendErrorRes(Zia::IResponse &res, size_t code, std::string data)
{
    std::vector<char> body;

    res.abortPipeline();
    res.setHeader("Content-Type", "text/plain; charset=utf-8");
    res.setCode(code);
    for (char &a : data)
        body.push_back(a);
    res.setBody(body);
}

int HandlerWrapper::getFileName(const Zia::IRequest &req, Zia::IResponse &res)
{
    if(access(path.data(), R_OK) == -1) {
        sendErrorRes(res, 500, path);
        return 84;
    }
    fileName = req.getFilename();
    if (!fileName.empty() && fileName[0] != '/')
        filePath = path + '/' + fileName;
    else if (fileName.empty() || (fileName.size() == 1 && fileName[0] == '/')) {
        fileName = "/index.html";
        filePath = path + fileName;
    }
    else
        filePath = path + fileName;
    if(access(filePath.data(), R_OK) == -1) {
        sendErrorRes(res, 404, filePath + " Doesn't exist");
        return 84;
    }
    return 0;
}

bool HandlerWrapper::extensionChecker(std::string extension)
{
    if (fileName.substr(fileName.find_last_of(".") + 1) == extension) {
        extent = extension;
        return true;
    }
    return false;
}
