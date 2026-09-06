/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "my_teams.h"

int users(client_t *client, char **param)
{
    char message[SIZE_ID_UUID + DEFAULT_NAME_LENGTH + 10] = {0};

    if (!param) {
    }
    for (client_t *tmp = get_data_base()->clients; tmp; tmp = tmp->next) {
        if (strcmp(client->user_name, "No Name Client") != 0) {
            memset(message, 0, strlen(message));
            sprintf(message, "%s|%s|%s", tmp->id, tmp->user_name,
            tmp->login_password ? "1" : "0");
            reply_server(309, client->socket, message, client->id);
        }
    }
    return (0);
}