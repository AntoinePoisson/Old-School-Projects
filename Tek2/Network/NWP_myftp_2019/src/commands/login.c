/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** login
*/

#include "server.h"

int user(client_t *client, char *param)
{
    if (client->login_user == 1) {
        reply_server(331, client->socket, NULL);
        return (RETURN_SUCCESS);
    }
    if (strcmp(param, "Anonymous") == 0) {
        client->login_user = 1;
        reply_server(331, client->socket, NULL);
    } else {
        client->login_user = 2;
        reply_server(331, client->socket, NULL);
        return (RETURN_ERROR);
    }
    return (RETURN_SUCCESS);
}

int password(client_t *client, char *param)
{
    if ((client->login_user == 0) || (client->login_password == true)) {
        reply_server(503, client->socket, NULL);
        return (RETURN_ERROR);
    }
    if (param == NULL && client->login_user == 1) {
        client->login_password = true;
        reply_server(230, client->socket, NULL);
    } else {
        client->login_user = 0;
        reply_server(530, client->socket, NULL);
        return (RETURN_ERROR);
    }
    return (RETURN_SUCCESS);
}