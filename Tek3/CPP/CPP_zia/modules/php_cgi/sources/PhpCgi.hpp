/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** PhpCgi
*/

#ifndef PHPCGI_HPP_
#define PHPCGI_HPP_

#include <map>
#include "HandlerWrapper.hpp"

class PhpCgi : public HandlerWrapper
{
    public:
        PhpCgi(Zia::IConf &conf);
        ~PhpCgi();
        void handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log);

    private:
        char **setEnv(const Zia::IRequest &req);
        char **mapToArray(std::map<std::string, std::string> &env);
        int execScript(Zia::IResponse &res, char **env);

    private:
        std::string cgiExectuter; // path to the php cgi programm
};

#endif /* !PHPCGI_HPP_ */
