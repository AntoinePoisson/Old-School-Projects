/*
** EPITECH PROJECT, 2018
** check_flag
** File description:
** check_flag
*/

#include <stddef.h>
#include "my_struct.h"

void check_arg(flag_t *flag, char *av[], int ac);

int check_error_flag(char *arg);

static void flag_init(flag_t *flag)
{
    flag->flag_l = 0;
    flag->flag_big_r = 0;
    flag->flag_d = 0;
    flag->flag_r = 0;
    flag->flag_t = 0;
    flag->nbr_recursive = 0;
    flag->r = NULL;
    flag->nbr_flag = 0;
}

static int find_flag(flag_t *flag, char *arg)
{
    if (check_error_flag(arg) == 84)
        return (84);
    for (int i = 1; arg[i] != '\0'; i++) {
        if (arg[i] == 'l')
            flag->flag_l = 1;
        if (arg[i] == 'R')
            flag->flag_big_r = 1;
        if (arg[i] == 'd')
            flag->flag_d = 1;
        if (arg[i] == 'r')
            flag->flag_r = 1;
        if (arg[i] == 't')
            flag->flag_t = 1;
        if (arg[i] == 'l' || arg[i] == 'R' || arg[i] == 'd'
            || arg[i] == 'r' || arg[i] == 't')
            flag->nbr_flag += 1;
    }
    return (0);
}

int check_flag(flag_t *flag, int ac, char *av[])
{
    flag_init(flag);
    for (int i = 1; i < ac; i++)
        if (av[i][0] == '-' && find_flag(flag, av[i]) == 84)
            return (84);
    check_arg(flag, av, ac);
    return (0);
}
