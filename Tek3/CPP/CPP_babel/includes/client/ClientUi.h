/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include "ClientNetwork.h"
#include "widge.h"
#include "test.h"


namespace babel {

class RelationButton : public QWidget
{
    public:
        RelationButton(QWidget *parent, int x, int y);
        void setButtonName(const QString &text);
        void setObjectName(const QString &name);
        void stateHideButton(bool);
        void stateDesableButton(bool);
    private:
    QPushButton *relation;
};

class ClientUi : public QWidget, private Ui::Form, private Ui::APP
{
    Q_OBJECT

    public:
        ClientUi(babel::ClientNetwork *clt);
        virtual ~ClientUi();

   private slots:
        void connexion();
        void bindUdp();
        void signIn();
        void logIn();
//        void getData();
        void handleRequest();
        void execCommand();
        void connected();
        void deconnected();
        void errorSocket(QAbstractSocket::SocketError error);
        void acceptRelation();
        void refuseRelation();
        void acceptCall();
        void refuseCall();
        void getListRelations();
        void logout();
        void search();

        void caller();
        void deleter();
        void inCall();
        void stopCall();
        void readUdp();

    signals:
        void commandToDo();

    private:
        void setUpInterface();

    private:
        void contactList();
        void confirmationCall();
        void callAccpted();
        void confirmationRelation();
        void registerOk();
        void loginOk();
        void serverShutdown();
        void hangUp();

    private:
        bool binded = false;
        QTimer timerRelations;
        QTimer timerAudio;
        babel::APortAudio *aze;
        babel::ClientNetwork *clt;
        std::vector<RelationButton *> listRelations;

        typedef struct command_s {
            int name;
            void (ClientUi::*funct)();
        }command_t;

    private:
        const command_t tab_cmd[9] = {
            {100, &ClientUi::contactList},
            {110, &ClientUi::confirmationCall},
            {111, &ClientUi::callAccpted},
            {112, &ClientUi::hangUp},
            {120, &ClientUi::confirmationRelation},
            {130, &ClientUi::registerOk},
            {131, &ClientUi::loginOk},
            {132, &ClientUi::serverShutdown},
            {0, nullptr}
        };
    };
}
#endif /* !NETWORK_HPP_ */
