/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** use
*/

#include "my_teams.h"

static bool go_to_team(client_t *client, char *param);
static bool go_to_channel(client_t *client, char *param);
static bool go_to_thread(client_t *client, char *param);

int use(client_t *client, char **param)
{
    memset(client->use_team, 0, SIZE_ID_UUID);
    memset(client->use_channel, 0, SIZE_ID_UUID);
    memset(client->use_thread, 0, SIZE_ID_UUID);
    if (!param)
        return (0);
    if (!param[0] || !go_to_team(client, param[0]))
        return (0);
    if (!param[1] || !go_to_channel(client, param[1]))
        return (0);
    if (!param[2] || !go_to_thread(client, param[2]))
        return (0);
    return (0);
}

static bool go_to_team(client_t *client, char *param)
{
    team_t *team = find_team(param);

    if (!team) {
        reply_server(402, client->socket, param, client->id);
        return (false);
    }
    for (list_index_t *start = client->team; start; start = start->next) {
        if (strcmp(start->id, team->id) == 0) {
            strcpy(client->use_team, param);
            return (true);
        }
    }
    reply_server(402, client->socket, param, client->id);
    return (false);
}

static bool go_to_channel(client_t *client, char *param)
{
    channel_t *channel = find_channel(param);

    if (!channel || strcmp(channel->linked_id_team, client->use_team) != 0) {
        reply_server(403, client->socket, param, client->id);
        return (false);
    }
    strcpy(client->use_channel, param);
    return (true);
}

static bool go_to_thread(client_t *client, char *param)
{
    thread_t *thread = find_thread(param);

    if (!thread ||
        strcmp(thread->linked_id_channel, client->use_channel) != 0) {
        reply_server(404, client->socket, param, client->id);
        return (false);
    }
    strcpy(client->use_thread, param);
    return (true);
}