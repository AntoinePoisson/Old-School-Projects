/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** forward
*/

#include "zappy.h"

int forward(client_t *client, char **param)
{
    int x = client->x;
    int y = client->y;

    if (client && param) {}
    switch (client->look) {
        case Up: calcul_new_position(&(client->x), &(client->y), 0, -1);
            break;
        case Down: calcul_new_position(&(client->x), &(client->y), 0, 1);
            break;
        case Left: calcul_new_position(&(client->x), &(client->y), -1, 0);
            break;
        case Right: calcul_new_position(&(client->x), &(client->y), 1, 0);
            break;
        default: reply_server(404, client->socket, NULL);
            return (0);
    }
    change_player_to_cell(x, y, client->x, client->y, client);
    reply_server(200, client->socket, NULL);
    return (0);
}