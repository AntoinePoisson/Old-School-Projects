/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** incantation
*/

#include "zappy.h"

static bool enough_people(client_t *client, server_t *server);
static bool enough_ressouce(client_t *client);

int incantation(client_t *client, char **param)
{
    bool fail = false;
    server_t *server = get_server();
    char mess[10] = {0};

    if (!param || strcmp(param[0], "true") != 0)
        fail = true;
    if (!enough_people(client, server))
        fail = true;
    if (!enough_ressouce(client))
        fail = true;
    if (!fail) {
        client->level += 1;
        sprintf(mess, "%d", client->level);
        reply_server(207, client->socket, mess);
    } else
        reply_server(404, client->socket, NULL);
    return (0);
}

static bool enough_people(client_t *client, server_t *server)
{
    int count = 0;

    for (int i = 0;
        strlen(server->map[client->y][client->x]->players[i].id); i++)
        count++;
    if (count >= list_ritual[client->level - 1].nbr_player)
        return (true);
    return (false);
}

static bool enough_ressouce(client_t *client)
{
    bool fail = false;

    if (client->linemate < list_ritual[client->level - 1].linemate)
        fail = true;
    if (client->deraumere < list_ritual[client->level - 1].deraumere)
        fail = true;
    if (client->sibur < list_ritual[client->level - 1].sibur) fail = true;
    if (client->mendiane < list_ritual[client->level - 1].mendiane)
        fail = true;
    if (client->phiras < list_ritual[client->level - 1].phiras)
        fail = true;
    if (client->thystame < list_ritual[client->level - 1].thystame)
        fail = true;
    client->linemate -= list_ritual[client->level - 1].linemate;
    client->deraumere -= list_ritual[client->level - 1].deraumere;
    client->sibur -= list_ritual[client->level - 1].sibur;
    client->mendiane -= list_ritual[client->level - 1].mendiane;
    client->phiras -= list_ritual[client->level - 1].phiras;
    client->thystame -= list_ritual[client->level - 1].thystame;
    return (!fail);
}