/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** dele
*/

#include "server.h"

int dele(client_t *client, char *param)
{
    if (remove(param) == -1) {
        reply_server(550, client->socket, NULL);
        return (RETURN_ERROR);
    }
    reply_server(250, client->socket, NULL);
    return (RETURN_SUCCESS);
}