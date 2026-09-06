/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** DataClient
*/

#ifndef DATACLIENT_H_
#define DATACLIENT_H_

#include "IData.h"

namespace babel
{
    class DataClient : public babel::IData
    {
        public:
            DataClient(const std::string &name, const std::string &nam = "");
            DataClient(const std::string &ip, uint16_t port);
            virtual ~DataClient();
            void setFirstParam(const std::string &name) final;
            void setSecondParam(const std::string &password) final;
            const std::string& getFirstParam() const final;
            const std::string& getSecondParam() const final;

            void setSecondParam(int port);
            uint16_t getPort() const;

        private:
            std::string _fstParam;
            std::string _sndParam;
            uint16_t _port;
    };

}

#endif /* !DATACLIENT_H_ */
