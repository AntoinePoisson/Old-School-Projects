/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** condition_win
*/

#include "zappy.h"

static bool end_game(int i, int nbr_max_level, server_t *server);

void condition_win(void)
{
    server_t *server = get_server();
    int nbr_max_level = 0;

    for (int i = 0; server->arg.teams[i]; i++, nbr_max_level = 0) {
        for (client_t *cli = server->clients; cli; cli = cli->next)
            if (!strcmp(cli->name, server->arg.teams[i]->name) &&
            cli->level == 8)
            nbr_max_level++;
        if (end_game(i, nbr_max_level, server))
            return;
    }
}

void condition_end(void)
{
    server_t *server = get_server();

    for (int i = 0; server->arg.teams[i]; i++)
        if (server->arg.teams[i]->nbr_current != 0)
            return;
    printf("Everybody is dead\n");
    server->quit_server = true;
}

static bool end_game(int i, int nbr_max_level, server_t *server)
{
    char win[20] = {0};
    char loss[600] = {0};

    if (nbr_max_level < CONDITION_WIN)
        return (false);
    sprintf(win, "Dead");
    sprintf(loss, "Dead");
    printf("Victory of Team: '%s'\n", server->arg.teams[i]->name);
    for (client_t *cli = server->clients; cli; cli = cli->next) {
        if (strcmp(cli->name, server->arg.teams[i]->name) == 0)
            reply_server(205, cli->socket, win);
        else if (cli->is_graphic == false)
            reply_server(205, cli->socket, loss);
    }
    server->quit_server = true;
    return (true);
}