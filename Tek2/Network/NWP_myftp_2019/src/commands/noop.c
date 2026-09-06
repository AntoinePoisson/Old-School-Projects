/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** noop
*/

#include "server.h"

int noop(client_t *client, char *param)
{
    if (param) {
    }
    reply_server(200, client->socket, NULL);
    return (RETURN_SUCCESS);
}