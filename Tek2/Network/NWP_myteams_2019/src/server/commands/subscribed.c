/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribed
*/

#include "my_teams.h"

static void print_list_team_sub(client_t *client);
static void print_list_team_user(client_t *client, team_t *team, char *parm);

int subscribed(client_t *client, char **param)
{
    team_t *team = NULL;

    if (param && param[0]) {
        if (param[1]) {
            reply_server(504, client->socket, NULL, client->id);
            return (0);
        }
        team = find_team(param[0]);
        print_list_team_user(client, team, param[0]);
    }
    print_list_team_sub(client);
    return (0);
}

static void print_list_team_sub(client_t *client)
{
    team_t *team = NULL;
    char message[SIZE_ID_UUID + DEFAULT_DESCRIPTION_LENGTH
        + DEFAULT_NAME_LENGTH + 500] = {0};

    for (list_index_t *list = client->team; list; list = list->next) {
        team = find_team(list->id);
        if (team) {
            memset(message, 0, strlen(message));
            sprintf(message, "%s|%s|%s", team->id,
            team->name, team->description);
            reply_server(324, client->socket, message, client->id);
        }
    }
}

static void print_list_team_user(client_t *client, team_t *team, char *parm)
{
    char message[SIZE_ID_UUID + DEFAULT_NAME_LENGTH + 10] = {0};

    if (team == NULL) {
        reply_server(402, client->socket, parm, client->id);
        return;
    }
    for (client_t *list = get_data_base()->clients; list; list = list->next)
        for (list_index_t *el = list->team; el; el = el->next)
            if (strcmp(el->id, team->id) == 0) {
                memset(message, 0, strlen(message));
                sprintf(message, "%s|%s|%s", list->id, list->user_name,
                list->login_password ? "1" : "0");
                reply_server(309, client->socket, message, client->id);
                break;
            }
}
