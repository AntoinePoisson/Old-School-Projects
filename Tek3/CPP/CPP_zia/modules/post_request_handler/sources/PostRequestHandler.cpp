/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** PostRequestHandler
*/

#ifdef _WIN32
    #include <io.h>
#else
    #include <unistd.h>
#endif
#include <fstream>
#include "PostRequestHandler.hpp"

PostRequestHandler::PostRequestHandler(Zia::IConf &conf)
{
    path = getConfPath(conf, "post_request");
}

PostRequestHandler::~PostRequestHandler()
{
}

void PostRequestHandler::post_request(const Zia::IRequest &req, Zia::IResponse &res)
{
    std::ofstream myfile;
    myfile.open(filePath);

    for (char c: *req.getBody())
        myfile << c;
    myfile.close();
    sendRes(res, 200, "OK");
}

void PostRequestHandler::handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log)
{
    (void)ctx;
    (void)log;
    getFileName(req, res);
    if (req.getMethod() == "POST")
        post_request(req, res);
}
