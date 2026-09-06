/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** check_arg_norme
*/

#include "zappy.h"

team_t *create_new_team(char *name, int nbr_max)
{
    team_t *new = calloc(1, sizeof(*new));

    if (!new)
        return (NULL);
    new->name = name;
    new->nbr_max = nbr_max;
    new->nbr_current = 1;
    new->nbr_online = 0;
    return (new);
}

void change_value_teams_liste_nbr_client(int nbr_max)
{
    server_t *server = get_server();

    for (int i = 0; server->arg.teams[i]; i++) {
        server->arg.teams[i]->nbr_current = nbr_max;
        server->arg.teams[i]->nbr_max = MAX_PLAYER_SAME_POSITION * 10;
    }
}

int check_param_width_and_height(server_t *server)
{
    if (!(server->arg.height >= 10 && server->arg.height <= 30)) {
        fprintf(stderr, "-y option must be integer between 10 and 30\n");
        return (Err);
    }
    if (!(server->arg.width >= 10 && server->arg.width <= 30)) {
        fprintf(stderr, "-x option must be integer between 10 and 30\n");
        return (Err);
    }
    return (Ok);
}