/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** DeleteRequestHandler
*/

#ifdef _WIN32
    #include <io.h>
#else
    #include <unistd.h>
#endif
#include <filesystem>
#include <fstream>
#include <cstring>
#include <iostream>
#include <optional>
#include "DeleteRequestHandler.hpp"

DeleteRequestHandler::DeleteRequestHandler(Zia::IConf &conf)
{
    path = getConfPath(conf, "delete_request");
}

DeleteRequestHandler::~DeleteRequestHandler()
{
}

void DeleteRequestHandler::delete_request(Zia::IResponse &res)
{
    std::filesystem::path path = filePath;

    std::filesystem::remove(path);
    sendRes(res, 200, "File deleted.");
}

void DeleteRequestHandler::handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log)
{
    (void)ctx;
    (void)log;
    if (req.getMethod() == "POST")
        return;
    if (getFileName(req, res) == 84)
        return;
    if (isPathPrivate(res))
        return;
    if (req.getMethod() == "DELETE")
        delete_request(res);
}
