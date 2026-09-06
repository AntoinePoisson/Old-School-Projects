/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** management_map
*/

#include "zappy.h"

static void place_random_player_norme(int *x, int *y, server_t *server);

void place_random_player(client_t *client)
{
    server_t *server = get_server();
    int x = -1;
    int y = -1;

    for (int count = server->arg.width * server->arg.height; count > 0;
        count--) {
        x = rand() % server->arg.width;
        y = rand() % server->arg.height;
        if (nbr_player_on_cell(x, y) == 0)
            break;
        x = -1;
        y = -1;
    }
    place_random_player_norme(&x, &y, server);
    client->look = (rand() % Left) + 1;
    client->x = x;
    client->y = y;
    add_player_to_cell(x, y, client);
}

int nbr_player_on_cell(int x, int y)
{
    server_t *server = get_server();
    int res = 0;

    if (x < 0 || y < 0 || x >= server->arg.width || y >= server->arg.height)
        return (-1);
    for (int i = 0; i < MAX_PLAYER_SAME_POSITION &&
        strlen(server->map[y][x]->players[i].id); i++)
        res += 1;
    return (res);
}

bool add_player_to_cell(int x, int y, client_t *client)
{
    server_t *server = get_server();
    int index = 0;

    if (x < 0 || y < 0 || x >= server->arg.width || y >= server->arg.height ||
        !client)
        return (false);
    while (strlen(server->map[y][x]->players[index].id))
        index += 1;
    if (index >= MAX_PLAYER_SAME_POSITION)
        return (false);
    strcpy(server->map[y][x]->players[index].id, client->id);
    strcpy(server->map[y][x]->players[index].player_team, client->name);
    server->map[y][x]->players[index].look = client->look;
    return (true);
}

bool change_player_to_cell(int x_old, int y_old, int x_new, int y_new,
client_t *client)
{
    server_t *server = get_server();

    if (x_old < 0 || y_old < 0 || x_old >= server->arg.width ||
        y_old >= server->arg.height ||
        x_new < 0 || y_new < 0 || x_new >= server->arg.width ||
        y_new >= server->arg.height)
        return (false);
    if (remove_player_to_cell(x_old, y_old, client) == false)
        return (false);
    if (add_player_to_cell(x_new, y_new, client) == false)
        return (false);
    return (true);
}

static void place_random_player_norme(int *x, int *y, server_t *server)
{
    if (*x != -1 && *y != -1)
        return;
    for (int line = 0; line < server->arg.height; line++)
        for (int col = 0; col < server->arg.width; col++)
            if (nbr_player_on_cell(line, col) == 0) {
                *y = line;
                *x = col;
                break;
            }
    if (*x == -1 || *y == -1) {
        *x = rand() % server->arg.width;
        *y = rand() % server->arg.height;
    }
}