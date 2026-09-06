/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** IIPC
*/

#ifndef IIPC_HPP_
#define IIPC_HPP_

#include <string>
#include <vector>

namespace Plazza {
    class IIPC {
        public:
            virtual ~IIPC() = default;

            virtual int nbrMessage() = 0;
            virtual std::string getMessage() = 0;
            virtual bool sendMessage(std::string messageSend) = 0;
            virtual bool setCanalListen(long canal) = 0;
            virtual bool setCanalSend(long canal) = 0;
            virtual long getCanalListen() const = 0;
            virtual long getCanalSend() const = 0;
            virtual std::vector<std::string> getMessageParse(std::string message = "") = 0;
        protected:
            long canalSend;
            long canalListen;
    };
}

#endif /* !IIPC_HPP_ */
