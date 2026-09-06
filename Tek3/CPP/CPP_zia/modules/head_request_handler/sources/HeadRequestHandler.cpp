/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** HeadRequestHandler
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
#include "HeadRequestHandler.hpp"

HeadRequestHandler::HeadRequestHandler(Zia::IConf &conf)
{
    (void)conf;
}

HeadRequestHandler::~HeadRequestHandler()
{
}

void HeadRequestHandler::head_request(Zia::IResponse &res)
{
    std::vector<char> body;
    res.setHeader("Content-Lenght",std::to_string(res.getBody()->size()));
    res.setBody(body);
}

void HeadRequestHandler::handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log)
{
    (void)ctx;
    (void)log;
    if (req.getMethod() == "HEAD")
        head_request(res);
}
