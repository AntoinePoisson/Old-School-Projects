/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout
*/

#include "my_teams.h"

static void reply_user_event_logout(char *message);

int logout(client_t *client, char **param)
{
    char tmp[SIZE_ID_UUID + DEFAULT_NAME_LENGTH + 1] = {0};

    if (!param) {
    }
    memset(client->use_team, 0, strlen(client->use_team));
    memset(client->use_channel, 0, strlen(client->use_channel));
    memset(client->use_thread, 0, strlen(client->use_thread));
    client->client_close = true;
    client->online = true;
    sprintf(tmp, "%s|%s", client->id, client->user_name);
    server_event_user_logged_out(client->id);
    reply_user_event_logout(tmp);
    client->login_password = false;
    return (0);
}

static void reply_user_event_logout(char *message)
{
    for (client_t *s = get_data_base()->clients; s; s = s->next)
        if (s->socket != 0 && s->login_password)
            reply_server(301, s->socket, message, s->id);
}