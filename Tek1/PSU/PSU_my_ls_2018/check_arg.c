/*
** EPITECH PROJECT, 2019
** check_arg
** File description:
** check_arg
*/

#include <stdlib.h>
#include "my_struct.h"
#include "my_lib.h"

static void create_char_2d(flag_t *flag)
{
    char **tab = malloc(sizeof(char *) * flag->arg->nbr_direction);

    flag->arg->direction = tab;
}

static void cp_arg(flag_t *flag, char *av, int *count)
{
    int i = 0;

    flag->arg->direction[*count] = malloc(sizeof(char) * my_strlen(av));
    for (; av[i] != '\0'; i++)
        flag->arg->direction[*count][i] = av[i];
    *count += 1;
}

static void no_arg(flag_t *flag)
{
    flag->arg->nbr_direction = 1;

    create_char_2d(flag);
    flag->arg->direction[0] = malloc(sizeof(char) * 2);
    flag->arg->direction[0][0] = '.';
    return;
}

void check_arg(flag_t *flag, char *av[], int ac)
{
    struct direction_s *create = malloc(sizeof(*create));
    int i = 1;
    int count = 0;

    flag->arg = create;
    for (; i < ac; i++)
        if (av[i][0] != '-')
            count++;
    flag->arg->nbr_direction = count;
    if (count == 0)
        return (no_arg(flag));
    create_char_2d(flag);
    for (i = 1, count = 0; i < ac; i++) {
        if (av[i][0] != '-')
            cp_arg(flag, av[i], &count);
    }
}
