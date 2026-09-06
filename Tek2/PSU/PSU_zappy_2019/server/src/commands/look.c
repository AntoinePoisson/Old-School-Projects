/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** look
*/

#include "zappy.h"

static char *write_cell(char *res, int x, int y, server_t *s);
static char *write_cell_norme(char *res, int x, int y, bool first_write);
static void pos_on_function_look(int *x, int *y, int look, int direction);
static void pos_on_function_look_norme(int *x, int *y, int look, int direction);

int look(client_t *client, __attribute__((unused)) char **param)
{
    char res[9000] = {0};
    int x = client->x;
    int y = client->y;
    int x_ = client->x;
    int y_ = client->y;
    int n = 1;

    for (int lvl = client->level; lvl >= 0; x = x_, y = y_, lvl--, n++, n++) {
        if (lvl != client->level) {
            pos_on_function_look(&x, &y, client->look, Up);
            pos_on_function_look(&x, &y, client->look, Left);
        }
        x_ = x;
        y_ = y;
        for (int c = n; c > 0; c--) {
            write_cell(res, x, y, get_server());
            pos_on_function_look(&x, &y, client->look, Right);
        }
    }
    return (reply_server(202, client->socket, res) ? 0 : 0);
}

static char *write_cell(char *res, int x, int y, server_t *s)
{
    bool first_write = is_extension_of_write_cell(x, y, s);

    if (strlen(res))
        res[strlen(res)] = ',';
    for (int i = 0; strlen(s->map[y][x]->players[i].id); i++)
        sprintf(&res[strlen(res)], first_write ? " %s" : "%s", "player");
    return (write_cell_norme(res, x, y, first_write));
}

static char *write_cell_norme(char *res, int x, int y, bool first_write)
{
    server_t *s = get_server();

    for (unsigned int i = 0; i < (s->map[y][x]->food); i++)
        sprintf(&res[strlen(res)], first_write ? " %s" : "%s", "food");
    for (unsigned int i = 0; i < (s->map[y][x]->linemate); i++)
        sprintf(&res[strlen(res)], first_write ? " %s" : "%s", "linemate");
    for (unsigned int i = 0; i < (s->map[y][x]->deraumere); i++)
        sprintf(&res[strlen(res)], first_write ? " %s" : "%s", "deraumere");
    for (unsigned int i = 0; i < (s->map[y][x]->sibur); i++)
        sprintf(&res[strlen(res)], first_write ? " %s" : "%s", "sibur");
    for (unsigned int i = 0; i < (s->map[y][x]->mendiane); i++)
        sprintf(&res[strlen(res)], first_write ? " %s" : "%s", "mendiane");
    for (unsigned int i = 0; i < (s->map[y][x]->phiras); i++)
        sprintf(&res[strlen(res)], first_write ? " %s" : "%s", "phiras");
    for (unsigned int i = 0; i < (s->map[y][x]->thystame); i++)
        sprintf(&res[strlen(res)], first_write ? " %s" : "%s", "thystame");
    return (res);
}

static void pos_on_function_look(int *x, int *y, int look, int direction)
{
    if (look == Up && direction == Up)
        calcul_new_position(x, y, 0, -1);
    if (look == Up && direction == Down)
        calcul_new_position(x, y, 0, 1);
    if (look == Up && direction == Left)
        calcul_new_position(x, y, -1, 0);
    if (look == Up && direction == Right)
        calcul_new_position(x, y, 1, 0);
    if (look == Down && direction == Up)
        calcul_new_position(x, y, 0, 1);
    if (look == Down && direction == Down)
        calcul_new_position(x, y, 0, -1);
    if (look == Down && direction == Left)
        calcul_new_position(x, y, 1, 0);
    if (look == Down && direction == Right)
        calcul_new_position(x, y, -1, 0);
    if (look == Left && direction == Up)
        calcul_new_position(x, y, -1, 0);
    pos_on_function_look_norme(x, y, look, direction);
}

static void pos_on_function_look_norme(int *x, int *y, int look, int direction)
{
    if (look == Left && direction == Down)
        calcul_new_position(x, y, 1, 0);
    if (look == Left && direction == Left)
        calcul_new_position(x, y, 0, 1);
    if (look == Left && direction == Right)
        calcul_new_position(x, y, 0, -1);
    if (look == Right && direction == Up)
        calcul_new_position(x, y, 1, 0);
    if (look == Right && direction == Down)
        calcul_new_position(x, y, -1, 0);
    if (look == Right && direction == Left)
        calcul_new_position(x, y, 0, -1);
    if (look == Right && direction == Right)
        calcul_new_position(x, y, 0, 1);
}