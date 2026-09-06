/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** create_map
*/

#include <time.h>
#include "zappy.h"

static cell_t *generate_new_cell(int x, int y);

bool create_map(void)
{
    server_t *server = get_server();

    srand(time(NULL));
    server->map = calloc(server->arg.height + 1, sizeof(cell_t **));
    if (!server->map)
        return (false);
    for (int y = 0; y < server->arg.height; y++) {
        if (!(server->map[y] = calloc(server->arg.width + 1, sizeof(cell_t *))))
            return (false);
        for (int x = 0; x < server->arg.width; x++)
            if ((server->map[y][x] = generate_new_cell(x, y)) == NULL)
                return (false);
    }
    return (true);
}

static cell_t *generate_new_cell(int x, int y)
{
    cell_t *new = calloc(1, sizeof(cell_t));

    if (!new)
        return (NULL);
    new->x = x;
    new->y = y;
    new->food += rand() % 4 ? 1 : 0;
    new->linemate += rand() % 3 ? 1 : 0;
    new->deraumere += rand() % 3 ? 1 : 0;
    new->sibur += rand() % 2 ? 1 : 0;
    new->mendiane += rand() % 2 ? 1 : 0;
    new->phiras += rand() % 2 ? 1 : 0;
    new->thystame += rand() % 1 ? 1 : 0;
    return (new);
}