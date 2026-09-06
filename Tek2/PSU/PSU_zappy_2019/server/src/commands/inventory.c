/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** inventory
*/

#include "zappy.h"

int inventory(client_t *client, __attribute__((unused)) char **param)
{
    char res[521] = {0};

    sprintf(res, "food %d, linemate %d, deraumere %d, sibur %d, mendiane %d, ",
    client->food, client->linemate, client->deraumere, client->sibur,
    client->mendiane);
    sprintf(&res[strlen(res)], "phiras %d, thystame %d",
    client->phiras, client->thystame);
    return (reply_server(202, client->socket, res) ? 0 : 0);
}