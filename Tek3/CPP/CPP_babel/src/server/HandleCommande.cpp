/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** HandleCommande
*/

#include "HandleCommande.hpp"

    //* Public
void babel::HandleCommande::HandlerCommande(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
{
    if (cmd.is_empty())
        return;
    try {
        switch (cmd.getOp()) {
            case babel::clientCommande_e::Register: return (babel::HandleCommande::registerUser(cmd, client, _listClient, _db));
            case babel::clientCommande_e::Login: return (babel::HandleCommande::loginUser(cmd, client, _listClient, _db));
            case babel::clientCommande_e::Logout: return (babel::HandleCommande::logoutUser(cmd, client, _listClient, _db));
            case babel::clientCommande_e::AskCall: return (babel::HandleCommande::askingCallSomeone(cmd, client, _listClient, _db));
            case babel::clientCommande_e::AnswerCall: return (babel::HandleCommande::answerCalledSomeone(cmd, client, _listClient, _db));
            case babel::clientCommande_e::AskRelation: return (babel::HandleCommande::askingAddRelation(cmd, client, _listClient, _db));
            case babel::clientCommande_e::AnswerRelation: return (babel::HandleCommande::answerAddedRelation(cmd, client, _listClient, _db));
            case babel::clientCommande_e::HangUpCall: return (babel::HandleCommande::hangUpCall(cmd, client, _listClient, _db));
            case babel::clientCommande_e::RemoveRelation: return (babel::HandleCommande::removeRelation(cmd, client, _listClient, _db));
            case babel::clientCommande_e::SendListRelation: return (babel::HandleCommande::sendListRelation(cmd, client, _listClient, _db));
            case babel::clientCommande_e::None: return (babel::HandleCommande::nothing(cmd, client, _listClient, _db));
            default: return (babel::HandleCommande::nothing(cmd, client, _listClient, _db));
        }
    } catch(...) {
        return;
    }
}



    //* Private
/**
 * registerUser
 * @param username
 * @param password
 **/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
void babel::HandleCommande::registerUser(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#else
void babel::HandleCommande::registerUser(babel::Package cmd, boost::shared_ptr<babel::Client> &client, __attribute__((unused)) std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#endif
{
    std::cout << "[Cmd]: registerUser." << std::endl;
    if (cmd.getParameter().size() != 4) //? Pas bon nbr Param
        return;
    TableUser rep = _db.registerNewUser(cmd.getParameter()[1], cmd.getParameter()[3], true);

    if (rep.isEmpty()) {
        client->sendPacket(babel::Package("130 0"));
        return;
    }
    client->setTable(rep);
    client->sendPacket(babel::Package("130 1"));
}

/**
 * loginUser
 * @param username
 * @param password
 **/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
void babel::HandleCommande::loginUser(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#else
void babel::HandleCommande::loginUser(babel::Package cmd, boost::shared_ptr<babel::Client> &client, __attribute__((unused)) std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#endif
{
    std::cout << "[Cmd]: loginUser." << std::endl;
    if (cmd.getParameter().size() != 4) //? Pas bon nbr Param
        return;
    TableUser rep = _db.loginUser(cmd.getParameter()[1], cmd.getParameter()[3]);

    if (rep.isEmpty()) {
        client->sendPacket(babel::Package("131 0"));
        return;
    }
    client->setTable(rep);
    client->sendPacket(babel::Package("131 1"));
}

/**
 * logoutUser
 **/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
void babel::HandleCommande::logoutUser(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#else
void babel::HandleCommande::logoutUser(__attribute__((unused)) babel::Package cmd, boost::shared_ptr<babel::Client> &client, __attribute__((unused)) std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#endif
{
    std::cout << "[Cmd]: logoutUser." << std::endl;
    TableUser rep = _db.logoutUser(client->getTable().getId());
    if (client->getTable().isEmpty()) //? Pas connecté
        return;
    client->setTable(rep);
    client->sendPacket(babel::Package("132"));
    client->disconnect();
}

/**
 * askingAddRelation
 * @param username
 **/
void babel::HandleCommande::askingAddRelation(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
{
    int id_user = -1;

    std::cout << "[Cmd]: askingAddRelation." << std::endl;
    if (cmd.getParameter().size() != 2) //? Pas bon nbr Param
        return;
    if (client->getTable().isEmpty()) //? Pas connecté
        return;
    for (auto element : _listClient)
        if (element->getTable().getName() == cmd.getParameter()[1] && element->getSocket().is_open()) {
            id_user = element->getTable().getId();
            break;
        }
    if (_db.isUserRelationWith(client->getTable().getId(), id_user)) { //? Déja en relation
        return;
    }
    for (auto element : _listClient) {
        if (element->getTable().getId() == id_user && element->getSocket().is_open()) {
            element->sendPacket(babel::Package("120 " + std::to_string(client->getTable().getName().size()) + " " + client->getTable().getName() + " " + std::to_string(client->getTable().getId())));
            return;
        }
    }
}

/**
 * answerAddedRelation
 * @param id_user
 **/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
void babel::HandleCommande::answerAddedRelation(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#else
void babel::HandleCommande::answerAddedRelation(babel::Package cmd, boost::shared_ptr<babel::Client> &client, __attribute__((unused)) std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#endif
{
    std::cout << "[Cmd]: answerAddedRelation." << std::endl;
    if (cmd.getParameter().size() != 1) //? Pas bon nbr Param
        return;
    if (client->getTable().isEmpty()) //? Pas connecté
        return;
    _db.addUserRelation(std::stoi(cmd.getParameter()[0]), client->getTable().getId());
}

/**
 * removeRelation
 * @param id_user
 **/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
void babel::HandleCommande::removeRelation(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#else
void babel::HandleCommande::removeRelation(babel::Package cmd, boost::shared_ptr<babel::Client> &client, __attribute__((unused)) std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#endif
{
    std::cout << "[Cmd]: removeRelation." << std::endl;
    if (cmd.getParameter().size() != 1) //? Pas bon nbr Param
        return;
    if (client->getTable().isEmpty()) //? Pas connecté
        return;
    _db.removeRelation(client->getTable().getId(), std::stoi(cmd.getParameter()[0]));
}

/**
 * askingCallSomeone
 * @param id_user
 **/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
void babel::HandleCommande::askingCallSomeone(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#else
void babel::HandleCommande::askingCallSomeone(babel::Package cmd, boost::shared_ptr<babel::Client> &client, __attribute__((unused)) std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#endif
{
    std::cout << "[Cmd]: askingCallSomeone." << std::endl;
    if (cmd.getParameter().size() != 2) //? Pas bon nbr Param
        return;
    if (client->getTable().isEmpty()) //? Pas connecté
        return;
    if (_db.isUserRelationWith(client->getTable().getId(), std::stoi(cmd.getParameter()[0])) == false) //? Pas en relation
        return;
    for (auto element : _listClient) {
        if (element->getTable().getId() == std::stoi(cmd.getParameter()[0]) && element->getSocket().is_open()) {
            element->sendPacket(babel::Package("110 " + std::to_string(client->getTable().getId()) + " " + cmd.getParameter()[1] + " " + element->getSocket().remote_endpoint().address().to_string() + " " + std::string(client->getTable().getName())));
            return;
        }
    }
}

/**
 * answerCalledSomeone
 * @param bool
 * @param socket ??
 **/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
void babel::HandleCommande::answerCalledSomeone(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#else
void babel::HandleCommande::answerCalledSomeone(babel::Package cmd, boost::shared_ptr<babel::Client> &client, __attribute__((unused)) std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#endif
{
    std::cout << "[Cmd]: answerCalledSomeone." << std::endl;
    if (cmd.getParameter().size() != 1) //? Pas bon nbr Param
        return;
    if (client->getTable().isEmpty()) //? Pas connecté
        return;
    if (_db.isUserRelationWith(client->getTable().getId(), std::stoi(cmd.getParameter()[0])) == false) //? Pas en relation
        return;
    for (auto element : _listClient) {
        if (element->getTable().getId() == std::stoi(cmd.getParameter()[0]) && element->getSocket().is_open()) {
            element->sendPacket(babel::Package("111 " + std::to_string(element->getTable().getId())));
            return;
        }
    }
}

/**
 * hangUpCall
 * @param bool
 * @param socket ??
 **/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
void babel::HandleCommande::hangUpCall(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#else
void babel::HandleCommande::hangUpCall(babel::Package cmd, boost::shared_ptr<babel::Client> &client, __attribute__((unused)) std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#endif
{
    std::cout << "[Cmd]: hangUpCall." << std::endl;
    if (cmd.getParameter().size() != 1) //? Pas bon nbr Param
        return;
    if (client->getTable().isEmpty()) //? Pas connecté
        return;
    if (_db.isUserRelationWith(client->getTable().getId(), std::stoi(cmd.getParameter()[0])) == false) //? Pas en relation
        return;
    for (auto element : _listClient) {
        if (element->getTable().getId() == std::stoi(cmd.getParameter()[0]) && element->getSocket().is_open()) {
            element->sendPacket(babel::Package("112 "));
            return;
        }
    }
}

/**
 * sendListRelation
 **/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
void babel::HandleCommande::sendListRelation(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#else
void babel::HandleCommande::sendListRelation(__attribute__((unused)) babel::Package cmd, boost::shared_ptr<babel::Client> &client, __attribute__((unused)) std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#endif
{
    std::cout << "[Cmd]: sendListRelation." << std::endl;
    bool first = true;

    if (client->getTable().isEmpty()) //? Pas connecté
        return;
    std::vector<TableRelation> rep = _db.getRelationList(client->getTable().getId());

    std::string result("100 " + std::to_string(rep.size()) + " ");
    if (rep.size() == 0) {
        client->sendPacket(babel::Package(result));
        return;
    }
    for (auto el : rep) {
        TableUser relation = _db.getUser(el.getFriendId());
        if (!first)
            result += " ";
        result += std::to_string(relation.getId()) + "/";
        result += relation.getName() + "/";
        result += (relation.getOnline() ? "1" : "0");
        first = false;
    }
    client->sendPacket(babel::Package(result));
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
void babel::HandleCommande::nothing(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db)
#else
void babel::HandleCommande::nothing(__attribute__((unused)) babel::Package cmd, __attribute__((unused)) boost::shared_ptr<babel::Client> &client, __attribute__((unused)) std::vector<boost::shared_ptr<babel::Client>> &_listClient, __attribute__((unused)) babel::DataBase &_db)
#endif
{}