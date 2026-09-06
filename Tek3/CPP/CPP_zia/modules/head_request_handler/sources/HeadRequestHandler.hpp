/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** HeadRequestHandler
*/

#ifndef HEADREQUESTHANDLER_HPP_
#define HEADREQUESTHANDLER_HPP_

#include "IHandler.hpp"

class HeadRequestHandler : public Zia::Module::IHandler
{
    public:
        HeadRequestHandler(Zia::IConf &conf);
        ~HeadRequestHandler();
        void handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log);

    private:
        void head_request(Zia::IResponse &res);
};

#endif /* !HeadRequestHandler_HPP_ */
