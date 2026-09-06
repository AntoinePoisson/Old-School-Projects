/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** tools
*/

#include "zappy.h"

static inline void calcul_new_position_norme(server_t *server, int *new_y);

void calcul_new_position(int *x, int *y, int offset_x, int offset_y)
{
    server_t *server = get_server();
    int new_x = *x + offset_x;
    int new_y = *y + offset_y;

    if (new_x < 0) {
        while (new_x < 0)
            new_x += server->arg.width;
    } else {
        while (new_x >= server->arg.width)
            new_x -= server->arg.width;
    }
    calcul_new_position_norme(server, &new_y);
    *x = new_x;
    *y = new_y;
}

static inline void calcul_new_position_norme(server_t *server, int *new_y)
{
    if (*new_y < 0) {
        while (*new_y < 0)
            *new_y = *new_y + server->arg.height;
    } else {
        while (*new_y >= server->arg.height)
            *new_y = *new_y - server->arg.height;
    }
}