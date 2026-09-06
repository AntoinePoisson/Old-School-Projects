/*
** EPITECH PROJECT, 2019
** NWP_myteams_2019
** File description:
** user.c
*/

#include "my_teams.h"

int user(client_t *client, char **param)
{
    char buf[SIZE_ID_UUID + DEFAULT_NAME_LENGTH + 50] = {0};
    client_t *c = NULL;

    if (!(c = find_client_by_id(*param))) {
        reply_server(401, client->socket, param[0], client->id);
        return Err;
    }
    sprintf(buf, "%s|%s|%s", c->id, c->user_name,
        (c->login_password) ? "1" : "0");
    reply_server(302, client->socket, buf, client->id);
    return Ok;
}