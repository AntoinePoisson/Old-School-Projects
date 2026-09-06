/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** help
*/

#include "my_teams.h"

int help(client_t *client, char **param)
{
    if (param) {
    }
    return (reply_server(200, client->socket, NULL, client->id) ? 0 : 84);
}