/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** FileExplorer
*/

#ifdef _WIN32
    #include <io.h>
#else
    #include <unistd.h>
#endif
#include <filesystem>
#include <chrono>
#include <fstream>
#include <cstring>
#include <ctime>
#include <iostream>
#include <optional>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "FileExplorer.hpp"


FileExplorer::FileExplorer(Zia::IConf &conf)
{
    path = getConfPath(conf, "file_explorer");
}

FileExplorer::~FileExplorer()
{
}

void FileExplorer::explore_file(Zia::IResponse &res)
{
    std::filesystem::directory_entry fs(filePath);

    if (!fs.exists() || !fs.is_directory()) {
        sendErrorRes(res, 404, filePath + " Not found");
        return;
    }
    std::string body;
    body += "<html><head><title>";
    body += filePath;
    body += "</title><body><h2>Index of: " + std::string(fileName) + "</h2><table>";
    body += "<thead><tr><td style=\"width: 300px\">Name</td><td>Last modified</td></tr></thead>";
    for(auto& p: std::filesystem::directory_iterator(filePath)) {
        struct stat buf;
        std::string row;

        if (stat(p.path().c_str(), &buf) < 0) {
            sendErrorRes(res, 500, "Internal server error");
            break;
        }
        std::string link = fileName + (filePath.back() == '/' ? "": "/") + std::string(p.path().filename());
        row += "<tr>";
        row += "<td><a href=\"" + link + "\">" + std::string(p.path().filename()) + "</a></td>";
        char *date_string = std::ctime(&buf.st_atime);
        row += "<td>" + std::string(date_string) + "</td>";
        row += "</tr>";
        body += row;
    }
    body += "</table></body></html>";
    res.setCode(200);
    res.setHeader("Content-Type", " text/html; charset=utf-8");
    std::vector<char> tmp;
    string_to_vector(tmp, body);
    res.setBody(tmp);
}

void FileExplorer::handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log)
{
    (void)ctx;
    (void)log;
    if (req.getMethod() == "POST")
        return;
    if (getFileName(req, res) == 84)
        return;
    if (isPathPrivate(res))
        return;
    if (res.getBody()->size() != 0)
        return;
    explore_file(res);
}
