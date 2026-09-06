/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** special_case_ritual
*/

#include "zappy.h"

void special_case_ritual(client_t *client)
{
    if (strncmp(client->buff_curr_cmd, "Incantation", 11) != 0)
        return;
    if (strcmp(client->buff_curr_cmd, "Incantation\n") != 0) {
        if (strncmp(client->buff_curr_cmd, "Incantation", 11) == 0) {
            free(client->buff_curr_cmd);
            client->buff_curr_cmd = strdup("Incantation false\n");
        }
        reply_server(206, client->socket, NULL);
        return;
    }
    free(client->buff_curr_cmd);
    client->buff_curr_cmd = strdup("Incantation true\n");
    reply_server(206, client->socket, NULL);
}

void up_free_place_in_team(client_t *client)
{
    server_t *server = get_server();

    if (!client->name || !strlen(client->name))
        return;
    for (int i = 0; server->arg.teams[i]; i++)
        if (strcmp(server->arg.teams[i]->name, client->name) == 0) {
            server->arg.teams[i]->nbr_online -= 1;
            return;
        }
}