/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribe
*/

#include "my_teams.h"

int subscribe(client_t *client, char **param)
{
    team_t *team = find_team(param[0]);
    char message[SIZE_ID_UUID * 2 + 5] = {0};

    if (!team) {
        reply_server(402, client->socket, param[0], client->id);
        return (0);
    }
    for (list_index_t *s = client->team; s; s = s->next)
        if (strcmp(team->id, s->id) == 0)
            return (reply_server(400, client->socket, NULL, client->id));
    if (add_client_to_team(client->id, param[0]) == NULL) {
        reply_server(566, client->socket, NULL, client->id);
        return 0;
    }
    server_event_user_join_a_team(team->id, client->id);
    sprintf(message, "%s|%s", client->id, team->id);
    reply_server(305, client->socket, message, client->id);
    return (0);
}