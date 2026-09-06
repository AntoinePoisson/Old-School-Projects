/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** left
*/

#include "zappy.h"

static void edit_map_cell(client_t *client);

int left(client_t *client, char **param)
{
    if (client && param) {}
    switch (client->look) {
        case Up: client->look = Left;
            break;
        case Down: client->look = Right;
            break;
        case Left: client->look = Down;
            break;
        case Right: client->look = Up;
            break;
        default: reply_server(404, client->socket, NULL);
            return (0);
    }
    edit_map_cell(client);
    reply_server(200, client->socket, NULL);
    return (0);
}

static void edit_map_cell(client_t *client)
{
    server_t *server = get_server();

    for (int i = 0;
        strlen(server->map[client->y][client->x]->players[i].id); i++)
        if (strcmp(server->map[client->y][client->x]->players[i].id,
        client->id) == 0) {
            server->map[client->y][client->x]->players[i].look
            = client->look;
            return;
        }
}