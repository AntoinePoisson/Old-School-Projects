/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "my_teams.h"

static int create_team(client_t *client, char *name, char *descript);
static int create_channel(client_t *client, char *name, char *descript);
static int create_thread(client_t *client, char *name, char *descript);
static char *genere_message(char **param);

int create(client_t *client, char **param)
{
    data_base_t *db = get_data_base();
    int size = 0;
    char *descript = NULL;

    for (int i = 0; param && param[i]; i++)
        size++;
    if (strlen(client->use_thread) && param && param[0] && param[1] == NULL &&
        (strlen(param[0]) < DEFAULT_NAME_LENGTH))
        return create_reply(client, transform_name(param[0]), db);
    if (size < 2 || (descript = genere_message(param)) == NULL ||
        (strlen(param[0]) >= DEFAULT_NAME_LENGTH) || (strlen(descript) >=
        DEFAULT_DESCRIPTION_LENGTH) || strlen(client->use_thread)) {
        reply_server(504, client->socket, NULL, client->id);
        return (0);
    }
    if (strlen(client->use_channel))
        return create_thread(client, param[0], descript);
    if (strlen(client->use_team))
        return create_channel(client, param[0], descript);
    return create_team(client, param[0], descript);
}

static int create_team(client_t *client, char *name, char *descript)
{
    team_t *team = add_new_team_init(name, descript, NULL);
    char message[SIZE_ID_UUID + DEFAULT_NAME_LENGTH +
        DEFAULT_DESCRIPTION_LENGTH + 500] = {0};

    if (team == NULL) {
        reply_server(566, client->socket, NULL, client->id);
        return (0);
    }
    server_event_team_created(team->id, team->name, client->id);
    sprintf(message, "%s|%s|%s", team->id, team->name, team->description);
    reply_server(308, client->socket, message, client->id);
    for (client_t *s = get_data_base()->clients; s; s = s->next)
        if (strcmp(s->id, client->id) != 0)
            reply_server(307, s->socket, message, s->id);
    return (0);
}

static int create_channel(client_t *client, char *name, char *descript)
{
    channel_t *channel = add_new_channel_init(name, client->use_team, NULL,
        descript);
    char message[SIZE_ID_UUID + DEFAULT_NAME_LENGTH +
        DEFAULT_DESCRIPTION_LENGTH + 500] = {0};

    if (channel == NULL) {
        reply_server(566, client->socket, NULL, client->id);
        return (0);
    }
    server_event_channel_created(client->use_team, channel->id, name);
    sprintf(message, "%s|%s|%s", channel->id, channel->name,
        channel->description);
    reply_server(312, client->socket, message, client->id);
    for (client_t *s = get_data_base()->clients; s; s = s->next)
        for (list_index_t *e = s->team; e && strcmp(s->id, client->id) != 0;
            e = e->next)
            if (strcmp(e->id, client->use_team) == 0 && s->socket != 0)
                reply_server(311, s->socket, message, s->id);
    return (0);
}

static int create_thread(client_t *client, char *name, char *descript)
{
    thread_t *thread = add_new_thread_init(name, client->use_channel, NULL,
        client->id, NULL, descript);
    char message[(SIZE_ID_UUID * 3) + DEFAULT_NAME_LENGTH +
        DEFAULT_BODY_LENGTH + 50] = {0};

    if (thread == NULL) {
        reply_server(566, client->socket, NULL, client->id);
        return (0);
    }
    server_event_thread_created(client->use_channel, thread->id, client->id,
        descript);
    sprintf(message, "%s|%s|%lu|%s|%s", thread->id, client->id,
        thread->timestamp, thread->name, thread->body);
    reply_server(316, client->socket, message, client->id);
    for (client_t *s = get_data_base()->clients; s; s = s->next)
        for (list_index_t *e = s->team; e && strcmp(s->id, client->id) != 0;
            e = e->next)
            if (strcmp(e->id, client->use_team) == 0 && s->socket != 0)
                reply_server(315, s->socket, message, s->id);
    return (0);
}

static char *genere_message(char **param)
{
    char res[DEFAULT_DESCRIPTION_LENGTH + 5] = {0};
    int index = 0;

    for (int i = 1; param[i]; i++)
        index += strlen(param[i]) + 1;
    if (index >= DEFAULT_DESCRIPTION_LENGTH)
        return (NULL);
    param[0] = transform_name(param[0]);
    for (int i = 1; param[i]; i++) {
        strcpy(&res[strlen(res)], param[i]);
        if (param[i + 1] != NULL)
            strcpy(&res[strlen(res)], " ");
    }
    return (strdup(res));
}