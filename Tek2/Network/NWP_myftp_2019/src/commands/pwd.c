/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pwd
*/

#include "server.h"

int pwd(client_t *client, char *param)
{
    if (param) {
    }
    reply_server(257, client->socket, client->path_current);
    return (RETURN_SUCCESS);
}