/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** PostRequestHandler
*/

#ifndef PostRequestHandler_HPP_
#define PostRequestHandler_HPP_

#include "HandlerWrapper.hpp"

class PostRequestHandler : public HandlerWrapper
{
    public:
        PostRequestHandler(Zia::IConf &conf);
        ~PostRequestHandler();
        void handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log);

    private:
        void post_request(const Zia::IRequest &req, Zia::IResponse &res);
};

#endif /* !PostRequestHandler_HPP_ */
