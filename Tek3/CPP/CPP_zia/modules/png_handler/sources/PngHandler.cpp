/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** PngHandler
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
#include "PngHandler.hpp"

PngHandler::PngHandler(Zia::IConf &conf)
{
    path = getConfPath(conf, "png");
}

PngHandler::~PngHandler()
{
}

void PngHandler::pngFileSender(Zia::IResponse &res)
{
    std::ifstream file (filePath, std::ios::in|std::ios::binary|std::ios::ate);
    std::vector<char> body;
    std::streampos size;

    if (!file.is_open()) {
        sendErrorRes(res, 404, filePath + " Not found");
        return;
    }
    size = file.tellg();
    body.resize(size);
    file.seekg (0, std::ios::beg);
    file.read(&body.front(), size);
    file.close();
    res.setCode(200);
    res.setHeader("Content-Type", "image/png");
    res.setHeader("Accept-Ranges", "none");
    res.setBody(body);
    file.close();
}


void PngHandler::handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log)
{
    (void)ctx;
    (void)log;
    if (req.getMethod() == "POST")
        return;
    if (getFileName(req, res) == 84)
        return;
    if (isPathPrivate(res))
        return;
    if (extensionChecker("png") || extensionChecker("jpg") || extensionChecker("gif")) {
        pngFileSender(res);
    }
}
