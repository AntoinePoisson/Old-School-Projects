/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** remove_player_to_cell
*/

#include "zappy.h"

static bool remove_player_to_cell_norme(int x, int y, int position,
    server_t *server);

bool remove_player_to_cell(int x, int y, client_t *client)
{
    server_t *server = get_server();
    int position = -1;

    if (x < 0 || y < 0 || x >= server->arg.width || y >= server->arg.height)
        return (false);
    for (int i = 0; i < MAX_PLAYER_SAME_POSITION &&
        strlen(server->map[y][x]->players[i].id); i++)
        if (strcmp(server->map[y][x]->players[i].id, client->id) == 0) {
            position = i;
            memset(server->map[y][x]->players[i].id, 0, SIZE_ID_UUID);
            server->map[y][x]->players[i].look = None;
            memset(server->map[y][x]->players[i].player_team, 0,
            DEFAULT_TEAM_NAME_LENGTH);
            break;
        }
    return (remove_player_to_cell_norme(x, y, position, server));
}

static bool remove_player_to_cell_norme(int x, int y, int position,
server_t *server)
{
    if (position == -1)
        return (false);
    for (int i = position; i + 1 < MAX_PLAYER_SAME_POSITION &&
        strlen(server->map[y][x]->players[i + 1].id); i++) {
        strcpy(server->map[y][x]->players[i].id,
            server->map[y][x]->players[i + 1].id);
        strcpy(server->map[y][x]->players[i].player_team,
            server->map[y][x]->players[i + 1].player_team);
        server->map[y][x]->players[i].look =
            server->map[y][x]->players[i + 1].look;
    }
    return (true);
}