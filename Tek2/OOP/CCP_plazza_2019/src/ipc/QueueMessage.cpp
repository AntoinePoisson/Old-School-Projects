/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** QueueMessage
*/

#include "ipc/QueueMessage.hpp"

    // Public
Plazza::QueueMessage::QueueMessage(std::string pathname, int projId, long canalListen, long canalSend)
{
    this->canalListen = canalListen;
    this->canalSend = canalSend;
    if ((canalSend < 0) || (canalListen < 0))
        throw Plazza::Throw::QueueMessage("Wrong parameter in constructor.");
    key = ftok(std::string("./.ipc/" + pathname).c_str(), 2 * projId);
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1)
        throw Plazza::Throw::QueueMessage("Can't get message queue identifier.");
}

Plazza::QueueMessage::~QueueMessage()
{
        msgctl(msgid, IPC_RMID, NULL);
}

int Plazza::QueueMessage::nbrMessage()
{
    struct msqid_ds data;
    
    if (msgctl(msgid, IPC_STAT, &data) == -1) {
        return (-1);
    }
    return (data.msg_qnum);
}

bool Plazza::QueueMessage::setCanalListen(long canal)
{
    if (canal < 0)
        return (false);
    canalListen = canal;
    return (true);
}

bool Plazza::QueueMessage::setCanalSend(long canal)
{
    if (canal < 0)
        return (false);
    canalSend = canal;
    return (true);
}

std::string Plazza::QueueMessage::getMessage()
{
    queue_message_t message;
    std::string res("");

    if (msgrcv(msgid, &message, sizeof(message), canalListen, IPC_NOWAIT) == -1)
        return ("");
    for (int i = 0; message.mText[i] && i < SIZE_MAX; i++)
        res += message.mText[i];
    Plazza::Encrypt tmp(res);
    res = tmp.unpack();
    Plazza::stockage.getLogFile() << " -- IPC get Message : '" << res << "'" << std::endl;
    return (res);
}

bool Plazza::QueueMessage::sendMessage(std::string messageSend)
{
    queue_message_t test;

    Plazza::Encrypt tmp(messageSend);
    messageSend = tmp.pack();
    if (messageSend.size() == 0)
        return (false);
    test.mType = canalSend;
    for (int i = 0; i < messageSend.size() && i < SIZE_MAX; i++)
        test.mText[i] = messageSend.c_str()[i];
    Plazza::stockage.getLogFile() << " ++ IPC send Message : '" << messageSend << "'" << std::endl;
    if (msgsnd(msgid, &test, sizeof(test.mText), IPC_NOWAIT) == -1)
        return (false);
    return (true);
}

std::vector<std::string> Plazza::QueueMessage::getMessageParse(std::string message)
{
    std::string parse = (message == "") ? getMessage() : message;
    std::string tmp("");
    std::vector<std::string> result;
    std::stringstream ssInput(parse);

    while (ssInput >> tmp) {
        result.push_back(tmp);
    }
    return (result);
}

long Plazza::QueueMessage::getCanalListen() const
{
    return (canalListen);
}

long Plazza::QueueMessage::getCanalSend() const
{
    return (canalSend);
}