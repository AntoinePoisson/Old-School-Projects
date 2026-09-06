/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_norme
*/

#include "my_teams.h"

int create_reply(client_t *client, char *descript, data_base_t *db)
{
    char mess[(SIZE_ID_UUID * 3) + DEFAULT_BODY_LENGTH + 5] = {0};
    comment_t *comment = add_new_comment_init(descript, client->use_thread,
        NULL, NULL);

    if (comment == NULL || descript == NULL)
        return (reply_server(566, client->socket, NULL, client->id) ? 0 : 0);
    server_event_thread_new_message(client->use_thread, client->id, descript);
    sprintf(mess, "%s|%s|%lu|%s", client->use_thread, client->id,
    comment->timestamp, comment->message);
    reply_server(320, client->socket, mess, client->id);
    for (client_t *s = db->clients; s; s = s->next)
        for (list_index_t *e = s->team; e && strcmp(s->id, client->id) != 0;
            e = e->next)
            if (strcmp(e->id, client->use_team) == 0 && s->socket != 0) {
                memset(mess, 0, (SIZE_ID_UUID * 3) + DEFAULT_BODY_LENGTH + 5);
                sprintf(mess, "%s|%s|%s|%s", client->id, client->use_thread,
                client->id, descript);
                reply_server(319, s->socket, mess, s->id);
            }
    return (0);
}

char *transform_name(char *name)
{
    for (int i = 0; name && name[i]; i++)
        if (name[i] == '|')
            name[i] = ' ';
    return (name);
}