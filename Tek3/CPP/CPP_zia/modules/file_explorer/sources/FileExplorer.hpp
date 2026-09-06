/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** FileExplorer
*/

#ifndef FILEEXPLORER_HPP_
#define FILEEXPLORER_HPP_

#include "HandlerWrapper.hpp"

class FileExplorer : public HandlerWrapper
{
    public:
        FileExplorer(Zia::IConf &conf);
        ~FileExplorer();
        void handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log);

    private:
    void explore_file(Zia::IResponse &res);
};

#endif /* !FileExplorer_HPP_ */
