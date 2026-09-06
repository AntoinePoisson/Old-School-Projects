/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** research_player_in_map
*/

#include "zappy.h"

static bool find_id_in_map(int x, int y, server_t *server, client_t *cli);

void research_player_in_map(int *x, int *y, client_t *client)
{
    server_t *server = get_server();

    if (!client || client->close || client->online == false)
        return;
    for (int line = 0; line < server->arg.height; line++)
        for (int col = 0; col < server->arg.width; col++)
            if (find_id_in_map(*x, *y, server, client) == true) {
                *y = line;
                *x = col;
                return;
            }
}

static bool find_id_in_map(int x, int y, server_t *server, client_t *cli)
{
    for (int i = 0; strlen(server->map[y][x]->players[i].id); i++)
        if (strcmp(server->map[y][x]->players[i].id, cli->id) == 0)
            return (true);
    return (false);
}