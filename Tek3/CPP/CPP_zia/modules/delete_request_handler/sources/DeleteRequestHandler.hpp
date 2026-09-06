/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** DeleteRequestHandler
*/

#ifndef DELETEREQUESTHANDLER_HPP_
#define DELETEREQUESTHANDLER_HPP_

#include "HandlerWrapper.hpp"

class DeleteRequestHandler : public HandlerWrapper
{
    public:
        DeleteRequestHandler(Zia::IConf &conf);
        ~DeleteRequestHandler();
        void handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log);

    private:
        void delete_request(Zia::IResponse &res);
};

#endif /* !DeleteRequestHandler_HPP_ */
