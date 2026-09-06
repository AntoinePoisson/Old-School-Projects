/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** quit
*/

#include "server.h"

int quit(client_t *client, char *param)
{
    if (param) {}
    client->close = true;
    client->login_password = false;
    client->login_user = 0;
    if (client->is_socket_data == PASV)
        close(client->socket_data);
    reply_server(221, client->socket, NULL);
    close(client->socket);
    client->is_socket_data = NO_EXIST;
    client->socket = 0;
    return (RETURN_SUCCESS);
}