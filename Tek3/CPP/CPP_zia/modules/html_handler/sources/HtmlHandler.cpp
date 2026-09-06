/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** HtmlHandler
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
#include "HtmlHandler.hpp"

HtmlHandler::HtmlHandler(Zia::IConf &conf)
{
    path = getConfPath(conf, "html");
}

HtmlHandler::~HtmlHandler()
{
}

void HtmlHandler::htmlFileSender(Zia::IResponse &res)
{
    std::ifstream file;
    std::string line;
    std::vector<char> body;
    file.open(filePath);

    if (!file) {
        sendErrorRes(res, 404, filePath + " Doesn't exist");
        return;
    }
    while (std::getline(file, line)) {
        for (char a : line)
            body.push_back(a);
        body.push_back('\n');
    }
    res.setCode(200);
    res.setHeader("Content-Type", "text/html; charset=utf-8");
    if (extent == "html")
        res.setHeader("Content-Type", "text/html; charset=utf-8");
    else if (extent == "css")
        res.setHeader("Content-Type", "text/css; charset=utf-8");
    else
        res.setHeader("Content-Type", "text/js; charset=utf-8");
    res.setBody(body);
    file.close();
}

void HtmlHandler::handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log)
{
    (void)ctx;
    (void)log;
    if (req.getMethod() == "POST")
        return;
    if (getFileName(req, res) == 84)
        return;
    if (isPathPrivate(res))
        return;
    if (!extensionChecker("html") && !extensionChecker("css") && !extensionChecker("js"))
        return;
    htmlFileSender(res);
}
