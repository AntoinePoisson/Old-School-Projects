/*
** EPITECH PROJECT, 2019
** NWP_myteams_2019
** File description:
** messages.c
*/

#include <time.h>
#include "my_teams.h"

int messages(client_t *client, char **param)
{
    char buf[SIZE_ID_UUID + DEFAULT_MESSAGE_LENGTH + 150] = {0};

    if (!find_client_by_id(*param))
        return reply_server(401, client->socket, param[0], client->id);
    for (discussion_t *d = get_data_base()->discussions; d; d = d->next)
        if ((strcmp(*param, d->id_client_reveice) == 0 &&
            strcmp(client->id, d->id_client_send) == 0) ||
            (strcmp(client->id, d->id_client_reveice) == 0 &&
            strcmp(*param, d->id_client_send) == 0)) {
            memset(buf, 0, strlen(buf));
            sprintf(buf, "%s|%lu|%s", d->id_client_send,
            d->timestamp, d->message);
            reply_server(304, client->socket, buf, client->id);
        }
    return Ok;
}