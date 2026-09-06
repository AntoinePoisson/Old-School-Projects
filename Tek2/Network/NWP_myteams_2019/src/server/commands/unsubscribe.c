/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** unsubscribe
*/

#include "my_teams.h"

static bool delete_element(client_t *client, char *id);

int unsubscribe(client_t *client, char **param)
{
    team_t *team = find_team(param[0]);
    char message[SIZE_ID_UUID * 2 + 5] = {0};

    if (!team || !delete_element(client, team->id)) {
        reply_server(402, client->socket, param[0], client->id);
        return (0);
    }
    server_event_user_leave_a_team(team->id, client->id);
    sprintf(message, "%s|%s", client->id, team->id);
    reply_server(306, client->socket, message, client->id);
    return (0);
}

static bool delete_element(client_t *client, char *id)
{
    list_index_t *save = client->team;

    if (save && strcmp(save->id, id) == 0) {
        client->team = client->team->next;
    } else if (save && save->next) {
        for (; save && strcmp(save->next->id, id) != 0;
            save = save->next) {
        }
        if (save == NULL)
            return (false);
        save->next = save->next->next;
    } else
        return (false);
    return (true);
}
