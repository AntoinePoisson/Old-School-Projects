/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** death
*/

#include "zappy.h"

static client_t *reset_value(client_t *client);

bool is_death(client_t *client)
{
    server_t *server = get_server();

    client->tick_food = 0;
    if (client->food >= 1)
        return (false);
    remove_player_to_cell(client->x, client->y, client);
    for (int i = 0; server->arg.teams[i]; i++)
        if (strcmp(server->arg.teams[i]->name, client->name) == 0) {
            server->arg.teams[i]->nbr_online -= 1;
            server->arg.teams[i]->nbr_current -= 1;
            break;
        }
    reply_server(204, client->socket, NULL);
    if (client->socket)
        close(client->socket);
    client = reset_value(client);
    return (true);
}

static client_t *reset_value(client_t *client)
{
    memset(client->id, 0, SIZE_ID_UUID);
    memset(client->name, 0, DEFAULT_TEAM_NAME_LENGTH);
    client->level = 0;
    client->socket = 0;
    client->buff = NULL;
    client->tick_remaining = 99;
    client->online = false;
    client->close = true;
    client->is_graphic = false;
    client->x = -1;
    client->y = -1;
    client->look = None;
    client->tick_food = 200;
    client->linemate = 0;
    client->deraumere = 0;
    client->sibur = 0;
    client->mendiane = 0;
    client->phiras = 0;
    client->thystame = 0;
    return (client);
}