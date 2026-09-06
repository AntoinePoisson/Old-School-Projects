/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** connect_nbr
*/

#include "zappy.h"

int connect_nbr(client_t *client, char **param)
{
    server_t *server = get_server();
    char str[100] = {0};
    int i = 0;

    if (client && param) {}
    while (server->arg.teams[i]) {
        if (strcmp(server->arg.teams[i]->name, client->name) == 0)
            break;
        i += 1;
    }
    if (server->arg.teams[i] == NULL) {
        reply_server(404, client->socket, NULL);
        return (0);
    }
    sprintf(str, "%d", (server->arg.teams[i]->nbr_current -
    server->arg.teams[i]->nbr_online));
    reply_server(201, client->socket, str);
    return (0);
}