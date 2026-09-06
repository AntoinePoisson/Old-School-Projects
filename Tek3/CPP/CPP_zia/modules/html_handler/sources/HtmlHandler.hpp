/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** HtmlHandler
*/

#ifndef HTMLHANDLER_HPP_
#define HTMLHANDLER_HPP_

#include "HandlerWrapper.hpp"

class HtmlHandler : public HandlerWrapper
{
    public:
        HtmlHandler(Zia::IConf &conf);
        ~HtmlHandler();
        void handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log);

    private:
    void htmlFileSender(Zia::IResponse &res);

    private:
};

#endif /* !HTMLHANDLER_HPP_ */
