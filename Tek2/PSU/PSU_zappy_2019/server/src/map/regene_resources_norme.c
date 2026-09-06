/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** regene_resources_norme
*/

#include "zappy.h"

void regene_sibur(server_t *server)
{
    int x = -1;
    int y = -1;

    for (int c = server->arg.width * server->arg.height; c > 0; c--) {
        x = rand() % server->arg.width;
        y = rand() % server->arg.height;
        if (x >= 0 && y >= 0 && x < server->arg.width && y < server->arg.height
            && total_ressource_in_case(x, y) <= DEF_RES_CASE)
            break;
        x = -1;
        y = -1;
    }
    if (x == -1 || y == -1)
        for (int line = 0; line < server->arg.height; line++)
            for (int col = 0; col < server->arg.width; col++)
                if (total_ressource_in_case(col, line) <= DEF_RES_CASE) {
                    x = col;
                    y = line;
                }
    if (x != -1 && y != -1) server->map[y][x]->sibur += 1;
}

void regene_mendiane(server_t *server)
{
    int x = -1;
    int y = -1;

    for (int c = server->arg.width * server->arg.height; c > 0; c--) {
        x = rand() % server->arg.width;
        y = rand() % server->arg.height;
        if (x >= 0 && y >= 0 && x < server->arg.width && y < server->arg.height
            && total_ressource_in_case(x, y) <= DEF_RES_CASE)
            break;
        x = -1;
        y = -1;
    }
    if (x == -1 || y == -1)
        for (int line = 0; line < server->arg.height; line++)
            for (int col = 0; col < server->arg.width; col++)
                if (total_ressource_in_case(col, line) <= DEF_RES_CASE) {
                    x = col;
                    y = line;
                }
    if (x != -1 && y != -1) server->map[y][x]->mendiane += 1;
}

void regene_phiras(server_t *server)
{
    int x = -1;
    int y = -1;

    for (int c = server->arg.width * server->arg.height; c > 0; c--) {
        x = rand() % server->arg.width;
        y = rand() % server->arg.height;
        if (x >= 0 && y >= 0 && x < server->arg.width && y < server->arg.height
            && total_ressource_in_case(x, y) <= DEF_RES_CASE)
            break;
        x = -1;
        y = -1;
    }
    if (x == -1 || y == -1)
        for (int line = 0; line < server->arg.height; line++)
            for (int col = 0; col < server->arg.width; col++)
                if (total_ressource_in_case(col, line) <= DEF_RES_CASE) {
                    x = col;
                    y = line;
                }
    if (x != -1 && y != -1) server->map[y][x]->phiras += 1;
}

void regene_thystame(server_t *server)
{
    int x = -1;
    int y = -1;

    for (int c = server->arg.width * server->arg.height; c > 0; c--) {
        x = rand() % server->arg.width;
        y = rand() % server->arg.height;
        if (x >= 0 && y >= 0 && x < server->arg.width && y < server->arg.height
            && total_ressource_in_case(x, y) <= DEF_RES_CASE)
            break;
        x = -1;
        y = -1;
    }
    if (x == -1 || y == -1)
        for (int line = 0; line < server->arg.height; line++)
            for (int col = 0; col < server->arg.width; col++)
                if (total_ressource_in_case(col, line) <= DEF_RES_CASE) {
                    x = col;
                    y = line;
                }
    if (x != -1 && y != -1) server->map[y][x]->thystame += 1;
}

int total_ressource_in_case(int x, int y)
{
    server_t *s = get_server();

    if (x >= 0 && y >= 0 && x < s->arg.width && y < s->arg.height)
        return (s->map[y][x]->food + s->map[y][x]->linemate +
        s->map[y][x]->deraumere + s->map[y][x]->sibur +
        s->map[y][x]->mendiane + s->map[y][x]->phiras + s->map[y][x]->thystame);
    return (100);
}