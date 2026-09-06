/*
** EPITECH PROJECT, 2019
** NWP_myteams_2019
** File description:
** list.c
*/

#include "my_teams.h"

static int list_replies(client_t *client)
{
    char *buf = calloc(SIZE_ID_UUID * 2 + 15 + DEFAULT_BODY_LENGTH + 4, 1);
    char *chan = NULL;

    if (!buf)
        return reply_server(566, client->socket, NULL, client->id);
    for (comment_t *com = get_data_base()->comments; com; com = com->next)
        if (!strcmp(com->linked_id_thread, client->use_thread)) {
            chan = find_thread(com->linked_id_thread)->linked_id_channel;
            if (!strcmp(client->use_channel, chan) &&
                !strcmp(client->use_team, find_channel(chan)->linked_id_team)) {
                sprintf(buf, "%s|%s|%lu|%s", com->id,
                find_thread(com->linked_id_thread)->creator, com->timestamp,
                com->message);
                reply_server(321, client->socket, buf, client->id);
                memset(buf, 0, strlen(buf));
            }
        }
    return Ok;
}

static int list_threads(client_t *client)
{
    char *buf = calloc(SIZE_ID_UUID * 2 + 15 + DEFAULT_NAME_LENGTH +
        DEFAULT_BODY_LENGTH + 5, sizeof(char));

    if (!buf)
        return reply_server(566, client->socket, NULL, client->id);
    for (thread_t *th = get_data_base()->threads; th; th = th->next)
        if (!strcmp(client->use_channel, th->linked_id_channel) &&
            !strcmp(client->use_team,
            find_channel(th->linked_id_channel)->linked_id_team)) {
            sprintf(buf, "%s|%s|%lu|%s|%s", th->id, th->creator, th->timestamp,
            th->name, th->body);
            reply_server(317, client->socket, buf, client->id);
            memset(buf, 0, strlen(buf));
        }
    return Ok;
}

static int list_channels(client_t *client)
{
    char *buf = calloc(SIZE_ID_UUID + DEFAULT_NAME_LENGTH + DEFAULT_BODY_LENGTH
        + 3, sizeof(char));

    if (!buf)
        return reply_server(566, client->socket, NULL, client->id);
    for (channel_t *chan = get_data_base()->channels; chan; chan = chan->next)
        if (!strcmp(client->use_team, chan->linked_id_team)) {
            sprintf(buf, "%s|%s|%s", chan->id, chan->name, chan->description);
            reply_server(313, client->socket, buf, client->id);
            memset(buf, 0, strlen(buf));
        }
    return Ok;
}

static int list_teams(client_t *client)
{
    char *buf = calloc(SIZE_ID_UUID + DEFAULT_NAME_LENGTH + DEFAULT_BODY_LENGTH
        + 3, sizeof(char));

    if (!buf)
        return reply_server(566, client->socket, NULL, client->id);
    for (team_t *team = get_data_base()->teams; team; team = team->next) {
        sprintf(buf, "%s|%s|%s", team->id, team->name, team->description);
        reply_server(310, client->socket, buf, client->id);
        memset(buf, 0, strlen(buf));
    }
    return Ok;
}

int list(client_t *client, __attribute__ ((unused))char **param)
{
    if (strlen(client->use_thread))
        return list_replies(client);
    if (strlen(client->use_channel))
        return list_threads(client);
    if (strlen(client->use_team))
        return list_channels(client);
    return list_teams(client);
}