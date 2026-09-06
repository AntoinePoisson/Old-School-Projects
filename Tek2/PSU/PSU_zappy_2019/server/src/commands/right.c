/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** right
*/

#include "zappy.h"

static void edit_map_cell(client_t *client);

int right(client_t *client, char **param)
{
    if (client && param) {}
    switch (client->look) {
        case Up: client->look = Right;
            break;
        case Down: client->look = Left;
            break;
        case Left: client->look = Up;
            break;
        case Right: client->look = Down;
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

bool is_extension_of_write_cell(int x, int y, server_t *s)
{
    int c = 0;

    if ((strlen(s->map[y][x]->players[0].id)))
        c++;
    if ((strlen(s->map[y][x]->players[1].id)))
        c++;
    c += (s->map[y][x]->food);
    c += (s->map[y][x]->linemate);
    c += (s->map[y][x]->deraumere);
    c += (s->map[y][x]->sibur);
    c += (s->map[y][x]->mendiane);
    c += (s->map[y][x]->phiras);
    c += (s->map[y][x]->thystame);
    return (c >= 2 ? true : false);
}