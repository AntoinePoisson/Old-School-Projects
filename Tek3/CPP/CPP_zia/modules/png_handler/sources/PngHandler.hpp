/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** PngHandler
*/

#ifndef PNGHANDLER_HPP_
#define PNGHANDLER_HPP_

#include <map>
#include "handler_wrapper/HandlerWrapper.hpp"

class PngHandler : public  HandlerWrapper
{
    public:
        PngHandler(Zia::IConf &conf);
        ~PngHandler();
        void handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log);

    private:
        void pngFileSender(Zia::IResponse &res);
};

#endif /* !PngHandler_HPP_ */
