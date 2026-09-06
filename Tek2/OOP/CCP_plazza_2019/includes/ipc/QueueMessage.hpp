/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** QueueMessage
*/

#ifndef QUEUEMESSAGE_HPP_
#define QUEUEMESSAGE_HPP_

#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sstream>
#include <stdlib.h>

#include "encrypt/Encrypt.hpp"
#include "Plazza.hpp"
#include "throw/QueueMessage.hpp"
#include "ipc/IIPC.hpp"

#define MAX_SIZE 100

namespace Plazza {

    class QueueMessage : public Plazza::IIPC {
        public:
            explicit QueueMessage(std::string pathname, int projId, long canalListen, long canalSend);
            ~QueueMessage();

            int nbrMessage();
            std::string getMessage();
            bool sendMessage(std::string messageSend);

            bool setCanalListen(long canal);
            bool setCanalSend(long canal);
            long getCanalListen() const;
            long getCanalSend() const;
            std::vector<std::string> getMessageParse(std::string message = "");

        private:
            key_t key;
            int msgid;

            typedef struct queue_message {
                long mType;
                char mText[MAX_SIZE + 1] = {0};
            } queue_message_t;
    };

}

#endif /* !QUEUEMESSAGE_HPP_ */
