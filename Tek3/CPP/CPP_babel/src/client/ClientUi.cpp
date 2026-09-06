/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** Network
*/

#include "ClientUi.h"

babel::ClientUi::ClientUi(babel::ClientNetwork *clit) : QWidget(), aze(nullptr)
{
    Ui::Form::setupUi(this);

    clt = clit;
    SocketTCP *sckTcp = new SocketTCP(this);
    clt->setSocketUdp(new SocketUDP(this));
    QObject::connect(sckTcp->getSocket(), SIGNAL(readyRead()), this, SLOT(handleRequest()));
    QObject::connect(sckTcp->getSocket(), SIGNAL(connected()), this, SLOT(connected()));
    QObject::connect(sckTcp->getSocket(), SIGNAL(disconnected()), this, SLOT(deconnected()));
    QObject::connect(sckTcp->getSocket(), SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorSocket(QAbstractSocket::SocketError)));
    clt->setSocketTcp(sckTcp);
    QObject::connect(Ui::Form::BConnect, SIGNAL(clicked()), this, SLOT(connexion()));
    QObject::connect(Ui::Form::BConnect2, SIGNAL(clicked()), this, SLOT(bindUdp()));
    QObject::connect(Ui::Form::BSign, SIGNAL(clicked()), this, SLOT(signIn()));
    QObject::connect(Ui::Form::BLogin, SIGNAL(clicked()), this, SLOT(logIn()));
    QObject::connect(this, SIGNAL(commandToDo()), this, SLOT(execCommand()));
}

babel::ClientUi::~ClientUi()
{
    if (aze)
        delete aze;
    return;
}


/********************************************************************************
    START                            SLOTS
********************************************************************************/

// handleRequest
void babel::ClientUi::handleRequest()
{
    if (clt->sockTcp->getDataFromSocket() == true) {
        std::cout << "azerzare:" << clt->sockTcp->getCmdParsed().front() << std::endl;
        std::cout << "qsdf:" << clt->sockTcp->getCmdParsed().back() << std::endl;
        emit commandToDo();
    }
}

// execCommand
void babel::ClientUi::execCommand()
{
    for (int i = 0; tab_cmd[i].name != 0; i++) {
        if (tab_cmd[i].name == std::stoi(clt->sockTcp->getCmdParsed().front())) {
            (this->*tab_cmd[i].funct)();
            break;
        }
    }
}

// connexion
void babel::ClientUi::connexion()
{
    Ui::Form::BConnect->setEnabled(false);
    DataClient data(Ui::Form::IP->text().toUtf8().constData(), Ui::Form::Port->value());
    clt->sockTcp->connectSocket(data);
}

void babel::ClientUi::bindUdp()
{
    binded = true;
    DataClient data("", Ui::Form::Port2->value());
    clt->sockUdp->connectSocket(data);
}

void babel::ClientUi::setUpInterface()
{
    this->hide();
    Ui::Form::layoutWidget->hide();
    Ui_APP::setupUi(this);

    QObject::connect(Ui::APP::BLogout, SIGNAL(clicked()), this, SLOT(logout()));

    QObject::connect(Ui::APP::BRefuse, SIGNAL(clicked()), this, SLOT(refuseRelation()));
    QObject::connect(Ui::APP::BAccept, SIGNAL(clicked()), this, SLOT(acceptRelation()));

    QObject::connect(Ui::APP::BCall, SIGNAL(clicked()), this, SLOT(stopCall()));
    QObject::connect(Ui::APP::BRefuseCall, SIGNAL(clicked()), this, SLOT(refuseCall()));
    QObject::connect(Ui::APP::BAcceptCall, SIGNAL(clicked()), this, SLOT(acceptCall()));

    QObject::connect(Ui::APP::BRefresh, SIGNAL(clicked()), this, SLOT(getListRelations()));

    QObject::connect(Ui::APP::SearchRelation, SIGNAL(returnPressed()), this, SLOT(search()));

    QObject::connect(clt->sockUdp->getSocket(), SIGNAL(readyRead()), this, SLOT(readUdp()));

    Ui::APP::BRelation->hide();
    Ui::APP::BCall->hide();

    int y = 100;

    for (int x = 35; x <= 980; y += 75) {
        if (y > 775) {
            y = 25;
            x += 135;
            continue;
        }
        listRelations.push_back(new RelationButton (this, x, y));
    }

    QObject::connect(&timerRelations, SIGNAL(timeout()), this, SLOT(getListRelations()));
    QObject::connect(&timerAudio, SIGNAL(timeout()), this, SLOT(inCall()));
    timerRelations.start(2000);
        try {
        aze = new babel::APortAudio;
    } catch(...) {}
    this->show();
}

// signIn
void babel::ClientUi::signIn()
{
    QString name = Ui::Form::SignName->text();
    std::replace(name.begin(), name.end(), ' ', '_');
    std::replace(name.begin(), name.end(), '/', '_');

    QString password = Ui::Form::SignPassword->text();
    std::replace(password.begin(), password.end(), ' ', '_');
    std::replace(password.begin(), password.end(), '/', '_');
    DataClient data(name.toUtf8().constData(), password.toUtf8().constData());
    if (binded == true)
        clt->registered(data);
    else
        std::cout << "IP and PORT UDP isn't bind yet !" << std::endl;
}

// logIn
void babel::ClientUi::logIn()
{
    DataClient data(Ui::Form::LoginName->text().toUtf8().constData(), Ui::Form::LoginPassword->text().toUtf8().constData());
    if (binded == true)
        clt->login(data);
    else
        std::cout << "IP and PORT UDP isn't bind yet !" << std::endl;
}

// logout
void babel::ClientUi::logout()
{
    clt->logout();
    this->close();
}

// getListRelations
void babel::ClientUi::getListRelations()
{
    clt->listRelation();
}

// search
void babel::ClientUi::search()
{
    DataClient data(Ui_APP::SearchRelation->text().toUtf8().constData());
    clt->askingAddRelation(data);
}

// connected
void babel::ClientUi::connected()
{
    std::cout << "Connected successfully !" << std::endl;
    Ui::Form::BConnect->setEnabled(true);
}

// deconnected
void babel::ClientUi::deconnected()
{
    std::cout << "Deconnected from the server !" << std::endl;
    this->close();
}

// errorSocket
void babel::ClientUi::errorSocket(QAbstractSocket::SocketError error)
{
    switch(error) {
        case QAbstractSocket::HostNotFoundError:
            std::cout << "ERROR : Unknown IP or Port." << std::endl;
            break;
        case QAbstractSocket::ConnectionRefusedError:
            std::cout << "ERROR : Server can't handle the connection." << std::endl;
            break;
        case QAbstractSocket::RemoteHostClosedError:
            std::cout << "ERROR : Connection lost with the server." << std::endl;
            break;
        default:
            std::cout << "ERROR : " << std::endl;
    }

    Ui::Form::BConnect->setEnabled(true);
}

// acceptCall
void babel::ClientUi::acceptCall()
{
    DataClient data(BCall->objectName().toUtf8().constData());
    clt->answerCalledSomeone(data);

    // BOUTON RACCROCHER
    BRefuseCall->hide();
    BAcceptCall->hide();
    for (auto const &butt : listRelations)
        butt->stateHideButton(false);
    // DISABLE ALL BUTTON
    // SHOW HANG UP BUTTON

    //aze->restartSound();
    timerAudio.start(0);
    timerRelations.stop();
    BRefresh->setEnabled(false);
}

// refuseCall
void babel::ClientUi::refuseCall()
{
    Ui::APP::BCall->hide();
}

// acceptRelation
void babel::ClientUi::acceptRelation()
{
    DataClient data(BRelation->objectName().toUtf8().constData());
    clt->answerAddedRelation(data);
    Ui::APP::BRelation->hide();
}

// refuseRelation
void babel::ClientUi::refuseRelation()
{
    Ui::APP::BRelation->hide();
}

void babel::ClientUi::readUdp()
{
    HandlerAudio coder;
    dataUdp_t test = clt->sockUdp->receivAudio();
    std::vector<unsigned char> dataChar(test.audio, test.audio + SIZE_MAX_AUDIO);
    HandlerAudio a(coder.decrypted(dataChar));
    static long time = 0;

    if (time <= test.time) {
        aze->playSound(a);
        time = test.time;
    }
}

// inCall
void babel::ClientUi::inCall()
{
    dataUdp_t udp = {};
    HandlerAudio test = aze->getSound();
    std::vector<unsigned char> data = test.encrypted(test.getData());
    udp.time = test.getTime();
    memcpy(udp.audio, data.data(), SIZE_MAX_AUDIO);
    clt->sockUdp->sendAudio(udp);
}

// stopCall
void babel::ClientUi::stopCall()
{
    // ENABLE ALL BUTTON
    BAcceptCall->show();
    BRefuseCall->show();
    // ENVOYER HANGUP
    BCall->hide();

    DataClient data(BCall->objectName().toUtf8().constData());
    clt->hangUpCall(data);
    timerAudio.stop();
    timerRelations.start(2000);
    BRefresh->setEnabled(true);
}

// caller
void babel::ClientUi::caller()
{
    QObject *receiv = sender();
    QPushButton *receivCasted = qobject_cast<QPushButton*>(receiv);
    DataClient data(qobject_cast<QPushButton*>(receivCasted->parentWidget())->objectName().toUtf8().constData());
    clt->askingCallSomeone(data);

    // DISABLE ALL BUTTON
    // SHOW HANG UP BUTTON
    BCall->setText(qobject_cast<QPushButton*>(receivCasted->parentWidget())->text());
    BCall->setObjectName(qobject_cast<QPushButton*>(receivCasted->parentWidget())->objectName());
    // envoyer l'id du client au serveur pour l'appeler
}

// deleter
void babel::ClientUi::deleter()
{
    QObject *receiv = sender();
    QPushButton *receivCasted = qobject_cast<QPushButton*>(receiv);
    DataClient data(qobject_cast<QPushButton*>(receivCasted->parentWidget())->objectName().toUtf8().constData());
    clt->removeRelation(data);
    qobject_cast<QPushButton*>(receivCasted->parentWidget())->hide();
}

/********************************************************************************
    END                            SLOTS
********************************************************************************/



/********************************************************************************
    START                 PRIVATE ARRAY POINTERS FUNCTIONS
********************************************************************************/


// contactList
void babel::ClientUi::contactList()
{
    std::vector<std::string> data = clt->sockTcp->getCmdParsed();
    data.erase(data.begin(), data.begin() + 2);
    std::vector<std::string> idNameState;

    for (auto const &str : data)
        std::cout << "LIST:" << str << std::endl;
    int x = 0;
    for (auto const &butt : listRelations)
        butt->stateHideButton(false);
    if (data.size() == 0)
        return;
    for (auto const &str : data) {
        if (x > 80)
            break;
        idNameState.clear();
        auto start = 0U;
        auto end = str.find("/");
        while (end != std::string::npos) {
            idNameState.push_back(str.substr(start, end - start));
            start = end + 1;
            end = str.find("/", start);
        }
        idNameState.push_back(str.substr(start, end));
        std::cout << "PARSE : " << idNameState.at(0) << " " << idNameState.at(1) << " " << idNameState.at(2) << std::endl;
        listRelations.at(x)->setButtonName(QString::fromStdString(idNameState.at(1)));
        listRelations.at(x)->setObjectName(QString::fromStdString(idNameState.at(0)));
        if (idNameState.at(2) == "1")
            listRelations.at(x)->stateDesableButton(true);
        else
            listRelations.at(x)->stateDesableButton(false);
        listRelations.at(x)->stateHideButton(true);
        x++;
    }
}


// confirmationCall
void babel::ClientUi::confirmationCall()
{
    // name maybe
    Ui::APP::BCall->setText(QString::fromStdString(clt->sockTcp->getCmdParsed().at(4)));
    Ui::APP::BCall->setObjectName(QString::fromStdString(clt->sockTcp->getCmdParsed().at(1)));
    clt->sockUdp->setPortDist(std::stoi(clt->sockTcp->getCmdParsed().at(2)));
    clt->sockUdp->setAddrDist(clt->sockTcp->getCmdParsed().at(3));
    Ui::APP::BCall->show();
}

// callAccpted
void babel::ClientUi::callAccpted()
{
    for (auto const &butt : listRelations)
        butt->stateHideButton(false);
    BCall->show();
    BRefuseCall->hide();
    BAcceptCall->hide();

    aze->restartSound();
    timerAudio.start(0);
    timerRelations.stop();
    BRefresh->setEnabled(false);
}

// hangUp
void babel::ClientUi::hangUp()
{
    // ENABLE ALL BUTTON
    BAcceptCall->show();
    BRefuseCall->show();
    BCall->hide();
    timerAudio.stop();
    timerRelations.start(2000);
    BRefresh->setEnabled(true);
}

// confirmationRelation
void babel::ClientUi::confirmationRelation()
{
    Ui::APP::BRelation->setText(QString::fromStdString(clt->sockTcp->getCmdParsed().at(2)));
    Ui::APP::BRelation->setObjectName(QString::fromStdString(clt->sockTcp->getCmdParsed().back()));
    Ui::APP::BRelation->show();
}

// registerOk
void babel::ClientUi::registerOk()
{
    std::cout << "here" << std::endl;
    if (clt->sockTcp->getCmdParsed().back() == "1") {
        std::cout << "User registered successfully !" << std::endl;
        setUpInterface();
    }
    else
        std::cout << "User error cant be registered !" << std::endl;
}

// loginOk
void babel::ClientUi::loginOk()
{
    if (clt->sockTcp->getCmdParsed().back() == "1") {
        std::cout << "User logged successfully !" << std::endl;
        setUpInterface();
        }
    else
        std::cout << "User error cant be logged !" << std::endl;
}

// serverShutdown
void babel::ClientUi::serverShutdown()
{
    std::cout << "The server is offline." << std::endl;
}

/********************************************************************************
    END                 PRIVATE ARRAY POINTERS FUNCTIONS
********************************************************************************/



/********************************************************************************
    START                 RelationButton MEMBER FUNCTIONS
********************************************************************************/

babel::RelationButton::RelationButton(QWidget *parent, int x, int y) : QWidget(parent)
{
    relation = new QPushButton(parent);
    relation->setGeometry(x, y, 100, 50);

    QPushButton *call = new QPushButton("call", relation);
    call->setGeometry(5, 35, 30, 15);
    QPushButton *delet = new QPushButton("delete", relation);
    delet->setGeometry(50, 35, 45, 15);
    QObject::connect(call, SIGNAL(clicked()), parent, SLOT(caller()));
    QObject::connect(delet, SIGNAL(clicked()), parent, SLOT(deleter()));
    stateHideButton(false);
}

// setObjectName
void babel::RelationButton::setObjectName(const QString &name)
{
    relation->setObjectName(name);
}

// setButtonName
void babel::RelationButton::setButtonName(const QString &text)
{
    relation->setText(text);
}

// stateHideButton
void babel::RelationButton::stateHideButton(bool hidden)
{
    if (hidden == false)
        relation->hide();
    else
        relation->show();
}

// stateDesableButton
void babel::RelationButton::stateDesableButton(bool a)
{
    relation->setEnabled(a);
}

/********************************************************************************
    END                 RelationButton MEMBER FUNCTIONS
********************************************************************************/