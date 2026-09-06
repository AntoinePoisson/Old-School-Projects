/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "my_teams.h"

static int size_tab_two(char **param, bool total_size);
static char *genere_message(char **param);

int send_message(client_t *client, char **param)
{
    client_t *receive = find_client_by_id(param[0]);
    char message[DEFAULT_BODY_LENGTH + SIZE_ID_UUID + 5] = {0};
    char message_two[DEFAULT_BODY_LENGTH + 5] = {0};
    time_t timer = time(NULL);

    if (!receive && param[0])
        return (reply_server(401, client->socket, param[0], client->id)
        ? 0 : 0);
    if (size_tab_two(param, false) == 0
        || size_tab_two(param, true) >= DEFAULT_BODY_LENGTH)
        return (reply_server(504, client->socket, NULL, client->id) ? 0 : 0);
    strcpy(message_two, genere_message(param));
    if (!add_new_discussion_init(message_two, client->id, param[0], &timer))
        return (reply_server(566, client->socket, NULL, client->id) ? 0 : 0);
    sprintf(message, "%s|%s", client->id, message_two);
    server_event_private_message_sended(client->id, param[0], message_two);
    reply_server(303, receive->socket, message, receive->id);
    return (0);
}

static int size_tab_two(char **param, bool total_size)
{
    int res = 0;

    if (!param || !param[0] || !param[1])
        return (0);
    for (int i = 0; param && param[i]; i++)
        res++;
    if (total_size == false)
        return (res);
    res = 0;
    for (int i = 1; param[i]; i++)
        res += strlen(param[i]) + 1;
    return (res);
}

static char *genere_message(char **param)
{
    char res[DEFAULT_BODY_LENGTH + 1] = {0};

    for (int i = 1; param[i]; i++) {
        strcpy(&res[strlen(res)], param[i]);
        if (param[i + 1] != NULL)
            strcpy(&res[strlen(res)], " ");
    }
    return (strdup(res));
}
