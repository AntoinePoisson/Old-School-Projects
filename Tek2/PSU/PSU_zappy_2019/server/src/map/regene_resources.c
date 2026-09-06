/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** regene_ressource
*/

#include "zappy.h"

static void regene_food(server_t *server);
static void regene_linemate(server_t *server);
static void regene_deraumere(server_t *server);

void regene_resources_map(void)
{
    server_t *server = get_server();
    int nbr = (rand() % (((server->arg.width > server->arg.height) ?
        server->arg.width : server->arg.height)) + 2);

    for (int pourcent = 0; nbr > 0; pourcent = 0, nbr--) {
        pourcent = rand() % 100;
        if (pourcent < 20) return (regene_food(server));
        if (pourcent < 37 && pourcent >= 20)
            return (regene_linemate(server));
        if (pourcent < 51 && pourcent >= 37)
            return (regene_deraumere(server));
        if (pourcent < 64 && pourcent >= 51)
            return (regene_sibur(server));
        if (pourcent < 77 && pourcent >= 64)
            return (regene_mendiane(server));
        if (pourcent <= 89 && pourcent >= 77)
            return (regene_phiras(server));
        if (pourcent > 89)
            return (regene_thystame(server));
    }
}

static void regene_food(server_t *server)
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
    if (x != -1 && y != -1) server->map[y][x]->food += 1;
}

static void regene_linemate(server_t *server)
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
    if (x != -1 && y != -1) server->map[y][x]->linemate += 1;
}

static void regene_deraumere(server_t *server)
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
    if (x != -1 && y != -1) server->map[y][x]->deraumere += 1;
}
