/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** HandlerWrapper
*/

#ifndef HANDLERWRAPPER_HPP_
#define HANDLERWRAPPER_HPP_

#include "IHandler.hpp"
#include <string>
#include <vector>

class HandlerWrapper : public Zia::Module::IHandler
{
    public:
        HandlerWrapper();
        ~HandlerWrapper();
        virtual void handle(const Zia::IRequest &req, Zia::IResponse &res, Zia::IContext &ctx, Zia::ILogger &log) = 0;

        std::string getConfPath(Zia::IConf &conf, std::string objectName);
        void sendErrorRes(Zia::IResponse &res, size_t code, std::string data);
        int getFileName(const Zia::IRequest &req, Zia::IResponse &res);
        bool extensionChecker(std::string extension);
        bool isPathPrivate(Zia::IResponse &res);
        void sendRes(Zia::IResponse &res, size_t code, std::string data);

    protected:
        std::string path; // the path directory where all script are stored
        std::string fileName;  // the name of the script
        std::string filePath; // concat of path and fileName which is the complete filePath to the scritp to execute
        std::string extent;

        template<typename T>
        static void string_to_vector(std::vector<char> &dest, const T &src)
        {
            int vect_index = dest.size();
            dest.resize(dest.size() + src.size());
            for (char c: src)
                dest[vect_index++] = c;
        }
};

#endif /* !HANDLERWRAPPER_HPP_ */
