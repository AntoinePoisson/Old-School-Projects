/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** fork_cmd
*/

#include "zappy.h"

int fork_cmd(client_t *client, char **param)
{
    server_t *server = get_server();

    if (!param || !param[0] || strcmp(param[0], "true") != 0) {
        reply_server(404, client->socket, NULL);
        return (0);
    }
    for (int i = 0; server->arg.teams[i]; i++)
        if (strcmp(server->arg.teams[i]->name, client->name) == 0) {
            server->arg.teams[i]->nbr_current += 1;
            break;
        }
    reply_server(200, client->socket, NULL);
    return (0);
}