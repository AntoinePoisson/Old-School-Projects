/*
** EPITECH PROJECT, 2019
** NWP_myteams_2019
** File description:
** info.c
*/

#include "my_teams.h"

static int info_threads(client_t *client)
{
    thread_t *thr = find_thread(client->use_thread);
    char *buf = calloc(SIZE_ID_UUID * 2 + 15 + DEFAULT_NAME_LENGTH +
        DEFAULT_BODY_LENGTH + 1, sizeof(char));

    if (!buf)
        return reply_server(566, client->socket, NULL, client->id);
    sprintf(buf, "%s|%s|%lu|%s|%s", thr->id, thr->creator, thr->timestamp,
    thr->name, thr->body);
    reply_server(322, client->socket, buf, client->id);
    return Ok;
}

static int info_channels(client_t *client)
{
    channel_t *chan = find_channel(client->use_channel);
    char *buf = calloc(SIZE_ID_UUID + DEFAULT_NAME_LENGTH + DEFAULT_BODY_LENGTH
        + 1, sizeof(char));

    if (!buf)
        return reply_server(566, client->socket, NULL, client->id);
    sprintf(buf, "%s|%s|%s", chan->id, chan->name, chan->description);
    reply_server(318, client->socket, buf, client->id);
    return Ok;
}

static int info_teams(client_t *client)
{
    team_t *team = find_team(client->use_team);
    char *buf = calloc(SIZE_ID_UUID + DEFAULT_NAME_LENGTH + DEFAULT_BODY_LENGTH
        + 1, sizeof(char));

    if (!buf)
        return reply_server(566, client->socket, NULL, client->id);
    sprintf(buf, "%s|%s|%s", team->id, team->name, team->description);
    reply_server(314, client->socket, buf, client->id);
    return Ok;
}

static int info_users(client_t *client)
{
    char *buf = calloc(SIZE_ID_UUID + DEFAULT_NAME_LENGTH + 4, sizeof(char));

    if (!buf)
        return reply_server(566, client->socket, NULL, client->id);
    for (client_t *cli = get_data_base()->clients; cli; cli = cli->next) {
        sprintf(buf, "%s|%s|%s", cli->id, cli->user_name,
        cli->login_password ? "1" : "0");
        reply_server(302, client->socket, buf, client->id);
        memset(buf, 0, strlen(buf));
    }
    return Ok;
}

int info(client_t *client, __attribute__ ((unused))char **param)
{
    if (strlen(client->use_thread))
        return info_threads(client);
    if (strlen(client->use_channel))
        return info_channels(client);
    if (strlen(client->use_team))
        return info_teams(client);
    return info_users(client);
}