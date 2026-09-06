/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Instance
*/

#pragma once
#include "IParser.hpp"
#include <algorithm>

namespace Zia
{
    class Instance : public Zia::Module::IParser::IInstance
    {
        public:
            Instance(Zia::IInput &input, Zia::ILogger &log, Zia::IRequest::IEmitter &requestEmitter);
            ~Instance();
            void parse();
            size_t checkIfRequestHasTwoCRLF();
            void parseByCRLF();
            bool checkRequest();
            bool checkFirstLine();
            size_t addChunks(size_t endpos, std::string tmp = "", size_t loopCount = 0, size_t chunkSize = 0);
            bool addBody(size_t endpos, std::string tmp = "", size_t count = 1);
            void cleanBuf(size_t endpos);

            std::vector<std::string> seperateStringAt(const std::string &str, const char c);
            std::string toLowerCase(const std::string str);

        private:
            Zia::IInput &_input;
            Zia::ILogger &_log;
            Zia::IRequest::IEmitter &_requestEmitter;
            std::string _buf = "";
            size_t _endpos;
            std::vector<std::string> _fullRequest;
            std::string _method;
            std::vector<std::string> _allowedMethods;
            bool _isCompletedRequest = false;
            bool _hasContentLength = false;
            size_t _contentLength = 0;
            bool _hasTransferEncoding = false;
    };
}