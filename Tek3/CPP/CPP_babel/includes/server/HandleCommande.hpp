/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** HandleCommande
*/

#ifndef HANDLECOMMANDE_HPP_
#define HANDLECOMMANDE_HPP_

#include "AsioNetwork.hpp"
#include "Client.hpp"
#include "DataBase.hpp"

namespace babel {

    class Package;
    class Client;
    class Database;

    typedef enum clientCommande_e {
        None = 0,
        Register = 230,
        Login = 231,
        Logout = 232,
        AskCall = 210,
        AnswerCall = 211,
        HangUpCall = 212,
        AskRelation = 220,
        AnswerRelation = 221,
        RemoveRelation = 222,
        SendListRelation = 223,
    } clientCommande_t;

    class HandleCommande {
        public:
            virtual ~HandleCommande() = default;

            static void HandlerCommande(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
            static void logoutUser(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
            static void registerUser(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
            static void loginUser(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
            static void askingAddRelation(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
            static void answerAddedRelation(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
            static void removeRelation(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
            static void askingCallSomeone(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
            static void answerCalledSomeone(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
            static void hangUpCall(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
            static void sendListRelation(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
            static void nothing(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
    };

    // typedef struct commande_s {
    //     clientCommande_t cmd;
    //     void (babel::HandleCommande::*ptr)(babel::Package cmd, boost::shared_ptr<babel::Client> &client, std::vector<boost::shared_ptr<babel::Client>> &_listClient, babel::DataBase &_db);
    // } commande_t;

    // static const commande_t listCommande[10] = {
    //     {babel::clientCommande_e::Register, &babel::HandleCommande::Nothing},
    //     {babel::clientCommande_e::Login, &babel::HandleCommande::Nothing},
    //     {babel::clientCommande_e::Logout, &babel::HandleCommande::Nothing},
    //     {babel::clientCommande_e::AskCall, &babel::HandleCommande::Nothing},
    //     {babel::clientCommande_e::AnswerCall, &babel::HandleCommande::Nothing},
    //     {babel::clientCommande_e::AskRelation, &babel::HandleCommande::Nothing},
    //     {babel::clientCommande_e::AnswerRelation, &babel::HandleCommande::Nothing},
    //     {babel::clientCommande_e::RemoveRelation, &babel::HandleCommande::Nothing},
    //     {babel::clientCommande_e::None, &babel::HandleCommande::Nothing}
    // };
}

#endif /* !HANDLECOMMANDE_HPP_ */
