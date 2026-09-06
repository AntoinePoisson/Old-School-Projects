/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** PhpCgi
*/

#ifdef _WIN32
    #include <io.h>
    #define pipe _pipe
#else
    #include <unistd.h>
    #include <sys/wait.h>
#endif
#include <list>
#include <cstring>
#include <iostream>
#include <optional>
#include "PhpCgi.hpp"

PhpCgi::PhpCgi(Zia::IConf &conf)
{
    path = getConfPath(conf, "phpcgi");
    cgiExectuter = "/usr/bin/php-cgi";
}

PhpCgi::~PhpCgi()
{
}

char **PhpCgi::mapToArray(std::map<std::string, std::string> &env)
{
    char **array = new char*[env.size() + 1];
    int i = 0;

    for (std::pair<const std::string, std::string> &line : env) {
        std::string concat = line.first + '=' + line.second;
        array[i] = new char[concat.size() + 1];
        memset(array[i], 0, concat.size() + 1);
        std::strcpy(array[i], concat.data());
        i++;
    }
    array[i] = NULL;
    return array;
}

char **PhpCgi::setEnv(const Zia::IRequest &req)
{
    std::map<std::string, std::string> env;

    env["REDIRECT_STATUS"] = "CGI";

    auto type = req.getHeader("Content-type");
    if (type != nullptr)
        env["CONTENT_TYPE"] = *type;

    auto lenght = req.getHeader("Content-length");
    if (lenght != nullptr)
        env["CONTENT_LENGTH"] = *lenght;

    auto cook = req.getHeader("Set-Cookie");
    if (cook != nullptr)
    env["HTTP_COOKIE"] = *cook;

    auto agent = req.getHeader("User-Agent");
    if (agent != nullptr)
        env["HTTP_USER_AGENT"] = *agent;

    env["SYSTEMROOT"] = "/";
    env["DOCUMENT_ROOT"] = path;
    env["REQUEST_URI"] = fileName;


    env["SCRIPT_NAME"] = fileName;
    env["SCRIPT_FILENAME"] = filePath;
    env["PATH_INFO"] = path;
    env["REQUEST_METHOD"] = req.getMethod();
    env["SERVER_NAME"] = "Zia";
    env["SERVER_SOFTWARE"] = "Zia/1.1";
    env["GATEWAY_INTERFACE"] = "CGI/1.1";
    env["SERVER_PROTOCOL"] = "HTTP/1.1";
//    env["SERVER_PORT"] = 80;     // ça peut changer
    env["QUERY_STRING"] = req.getMethod() + " " + fileName + " HTTP/1.1";

    //req.getBody();


    return mapToArray(env);
}

#ifdef _WIN32
int PhpCgi::execScript(Zia::IResponse &res, char **env)
{
    return 0;
}
#else
int PhpCgi::execScript(Zia::IResponse &res, char **env)
{
    int pipefd[2] = {0};
    pipe(pipefd);
    pid_t cpid = fork();

    if (cpid == -1) {
        sendErrorRes(res, 500, "Fork Failed");
        delete env;
        return 84;
    }
    else if (cpid == 0) {
        char *arg[] = {&cgiExectuter[0], &filePath[0], NULL};

        close(pipefd[0]);
        dup2(pipefd[1], 1);

        if (execve(&cgiExectuter[0], arg, env) == -1) {
            std::cout << "[PHP CGI]: FAILED TO EXEC" << std::endl;
            //sendErrorRes(res, 403, "FAILED TO EXEC");
            std::exit(84);
        }
    }
    else {
        close(pipefd[1]);
        int status = 0;
        wait(&status);

        char buffer;
        std::list<char> data;
        while (read(pipefd[0], &buffer, 1) > 0)
            data.push_back(buffer);
        close(pipefd[0]);

        std::string key;
        std::string value;
        bool doublePoint = false;

        for (; data.size() > 0;) {
            char c = data.front();
            data.pop_front();
            if (c == ':') {
                data.pop_front();
                doublePoint = true;
                continue;
            }
            if (c == '\r') {
                if (doublePoint == false) {
                    data.pop_front();
                    break;
                }
                data.pop_front();
                doublePoint = false;
                res.setHeader(key, value);
                key.clear();
                value.clear();
                continue;
            }
            if (!doublePoint)
                key.push_back(c);
            else
                value.push_back(c);
        }

        std::vector<char> body;
        for (char a : data)
            body.push_back(a);

        res.setCode(200);
        res.setBody(body);
    }
    //delete env;
    return 0;
}
#endif

void PhpCgi::handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log)
{
    (void)ctx;
    (void)log;
    if (req.getMethod() == "POST")
        return;
    if (getFileName(req, res) == 84)
        return;
    if (isPathPrivate(res))
        return;
    if (!extensionChecker("php"))
        return;
    execScript(res, setEnv(req));
}
