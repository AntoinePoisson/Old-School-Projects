/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** cwd
*/

#include "server.h"

int cwd(client_t *client, char *param)
{
    char *pwd = NULL;

    if (chdir(param) == -1) {
        reply_server(550, client->socket, NULL);
        return (RETURN_ERROR);
    }
    pwd = get_pwd();
    if (!pwd) {
        reply_server(550, client->socket, NULL);
        return (RETURN_ERROR);
    }
    free(client->path_current);
    client->path_current = pwd;
    reply_server(250, client->socket, NULL);
    return (RETURN_SUCCESS);
}