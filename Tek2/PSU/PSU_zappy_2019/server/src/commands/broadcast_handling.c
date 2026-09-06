/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** broadcast
*/

#include "zappy.h"

static char *broadcast_compute(const client_t *rx, const client_t *tx,
    char *data);

int broadcast_transmit(client_t *rx, char **data)
{
    client_t *tx = NULL;
    char *text = NULL;
    char *mess = &rx->buff_curr_cmd[10];

    if (!data || !data[0] || !strlen(mess))
        return (reply_server(404, rx->socket, NULL) ? 0 : 0);
    while (mess[0] == ' ')
        mess = &mess[1];
    if (!strlen(mess))
        return (reply_server(404, rx->socket, NULL) ? 0 : 0);
    for (tx = get_server()->clients; tx; tx = tx->next) {
        if (tx != rx && (text = broadcast_compute(rx, tx, mess)) != NULL) {
            reply_server(201, tx->socket, text);
            free(text);
        } else if (tx == rx)
            reply_server(200, tx->socket, NULL);
    }
    return (0);
}

static void broadcast_algorithm_shift(int *rx, int *tx, const int size)
{
    (*tx) -= 1;
    (*rx) -= 1;
    if ((*rx) < 0)
        (*rx) = size - 1;
    if ((*tx) < 0)
        (*tx) = size - 1;
}

static int broadcast_get_direction(const client_t *rx, const client_t *tx)
{
    int size[2] = {get_server()->arg.width , get_server()->arg.height};
    int pos_rx[2] = {rx->x, rx->y};
    int pos_tx[2] = {tx->x, tx->y};
    float degrees = 0;
    int formatted_dir = 0;

    if (rx->x == tx->x && rx->y == tx->y)
        return (0);
    while (abs(pos_rx[0] - pos_tx[0]) > size[0] / 2)
        broadcast_algorithm_shift(&(pos_rx[0]), &(pos_tx[0]), size[0]);
    while (abs(pos_rx[1] - pos_tx[1]) > size[1] / 2)
        broadcast_algorithm_shift(&(pos_rx[1]), &(pos_tx[1]), size[1]);
    degrees = (atan2(pos_rx[0] - pos_tx[0], pos_rx[1] - pos_tx[1])
        * 180 / M_PI) + 180.f;
    formatted_dir = ((int)degrees + 360 - 45 / 2) % 360;
    formatted_dir = formatted_dir / 45 + 2;
    return ((formatted_dir > 8) ? formatted_dir - 8 : formatted_dir);
}

static int broadcast_reformat(const client_t *rx, const client_t *tx,
int8_t *dir)
{
    if (rx->x == tx->x && rx->y == tx->y)
        return (0);
    *dir = (tx->look == Up && *dir != 0) ? *dir - 0 : *dir;
    *dir = (tx->look == Down && *dir != 0) ? *dir - 4 : *dir;
    *dir = (tx->look == Left && *dir != 0) ? *dir - 2 : *dir;
    *dir = (tx->look == Right && *dir != 0) ? *dir - 6 : *dir;
    *dir = (*dir < 1) ? *dir + 8 : *dir;
    return (0);
}

static char *broadcast_compute(const client_t *rx, const client_t *tx,
char *data)
{
    size_t size = 0;
    char *tmp = NULL;
    int8_t dir = broadcast_get_direction(rx, tx);

    size = snprintf(NULL, 0, "message %d, %s\n", dir, data);
    if ((tmp = calloc((size + 1), 1)) == NULL) {
        fprintf(stderr, "[Error]: Malloc failure with a size of %ld", size);
        fflush(stderr);
        return (NULL);
    }
    broadcast_reformat(rx, tx, &dir);
    sprintf(tmp, "message %d, %s\n", dir, data);
    return (tmp);
}