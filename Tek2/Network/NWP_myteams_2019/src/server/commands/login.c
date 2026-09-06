/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "my_teams.h"

static client_t *check_old_data_base(client_t *curr_client, char *name);
static int create_new_client(client_t *curr_client, char *name);
static char *genere_name(char **param);
static void reply_user_event_login(char *message);

int login(client_t *client, char **param)
{
    char tmp[SIZE_ID_UUID + DEFAULT_NAME_LENGTH + 1] = {0};

    if ((!param) || genere_name(param) == NULL)
        return (reply_server(503, client->socket, NULL, client->id) ? 0 : 0);
    if (client->login_password == true)
        return (reply_server(400, client->socket, NULL, client->id) ? 0 : 0);
    if (client->client_close && strcmp(client->user_name, genere_name(param)))
        return (create_new_client(client, genere_name(param)));
    memset(client->use_team, 0, strlen(client->use_team));
    memset(client->use_channel, 0, strlen(client->use_channel));
    memset(client->use_thread, 0, strlen(client->use_thread));
    client->login_password = true;
    client->client_close = false;
    client->online = true;
    client = check_old_data_base(client, genere_name(param));
    strcpy(client->user_name, genere_name(param));
    server_event_user_logged_in(client->id);
    sprintf(tmp, "%s|%s", client->id, client->user_name);
    reply_user_event_login(tmp);
    return (0);
}

static client_t *check_old_data_base(client_t *curr_cli, char *name)
{
    client_t *old_client = find_client_by_name(name);

    if (old_client == NULL) {
        server_event_user_created(curr_cli->id, name);
        return (curr_cli);
    }
    if (old_client == curr_cli) return (curr_cli);
    strcpy(curr_cli->id, old_client->id);
    strcpy(old_client->id, generate_uuid());
    old_client->user_name[0] = 0;
    if (get_data_base()->clients == old_client) {
        get_data_base()->clients = get_data_base()->clients->next;
        return (curr_cli);
    }
    for (client_t *tmp = get_data_base()->clients; tmp; tmp = tmp->next)
        if (tmp->next == old_client)
            tmp->next = old_client->next;
    return (curr_cli);
}

static int create_new_client(client_t *curr_client, char *name)
{
    client_t *new_client = add_new_client_init(NULL, NULL);;
    char tmp[SIZE_ID_UUID + DEFAULT_NAME_LENGTH + 1] = {0};

    if (new_client == NULL)
        return (reply_server(400, new_client->socket, NULL, new_client->id)
        ? 0 : 0);
    new_client->login_password = true;
    new_client->client_close = false;
    new_client->online = true;
    new_client->socket = curr_client->socket;
    curr_client->socket = 0;
    curr_client->online = false;
    new_client = check_old_data_base(new_client, name);
    strcpy(new_client->user_name, name);
    server_event_user_logged_in(new_client->id);
    sprintf(tmp, "%s|%s", new_client->id, new_client->user_name);
    reply_user_event_login(tmp);
    return 0;
}

static char *genere_name(char **param)
{
    char res[DEFAULT_NAME_LENGTH + 5] = {0};
    int index = 0;

    for (int i = 0; param && param[i]; i++)
        index += strlen(param[i]) + 1;
    if (index >= DEFAULT_DESCRIPTION_LENGTH || index == 0)
        return (NULL);
    for (int i = 0; param[i]; i++) {
        strcpy(&res[strlen(res)], param[i]);
        if (param[i + 1] != NULL)
            strcpy(&res[strlen(res)], " ");
    }
    return (strdup(res));
}

static void reply_user_event_login(char *message)
{
    for (client_t *s = get_data_base()->clients; s; s = s->next)
        if (s->socket != 0 && s->login_password)
            reply_server(300, s->socket, message, s->id);
}