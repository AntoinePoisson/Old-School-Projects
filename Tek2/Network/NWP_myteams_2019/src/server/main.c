/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include "my_teams.h"
#include "data_base.h"

static int check_args(char **av, int ac)
{
    if (ac != 2)
        THROW(USAGE_MESS);
    if (strcmp(av[1], USAGE_FLAG) == 0 || strcmp(av[1], "-h") == 0 ||
        strcmp(av[1], "--help") == 0)
        RET_USAGE();
    for (int i = 0; av[1][i]; i++)
        if (!(av[1][i] >= '0' && av[1][i] <= '9')) {
            fprintf(stdout, "Invalide Port Argument\n");
            exit(Err);
        }
    return Ok;
}

int main(int ac, char **av)
{
    int val = check_args(av, ac);

    return ((val == Ok) ? my_teams_server(av[1]) : val);
}
