/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error
*/

#include <stddef.h>
#include "my_lib.h"

int control_right_flag(char *str)
{
    if (my_strlen(str) != 2)
        return (84);
    if (str[1] == 's')
        return (1);
    if (str[1] == 'w')
        return (2);
    if (str[1] == 'g')
        return (3);
    return (84);
}

int control_arg(char *arg, int cas, int *i)
{
    if (arg == NULL)
        return (84);
    if (cas == 1)
        for (int i = 0; arg[i]; i++)
            if (!(arg[i] >= '0' && arg[i] <= '9'))
                return (84);
    if (cas == 2 || cas == 3)
        for (int i = 0; arg[i]; i++)
            if (!(arg[i] >= 'a' && arg[i] <= 'z'))
                return (84);
    *i += 1;
    return (0);
}

int check_error(int ac, char *av[])
{
    int cas = 0;

    if (ac < 3 || !av)
        return (my_puterror("Invalide Nbr Argument.\n"));
    for (int i = 1; i < ac; i++, cas = 0) {
        if (av[i][0] == '-' && ((cas = control_right_flag(av[i])) == 84))
            return (my_puterror("False Flag.\n"));
        if (cas == 0)
            return (84);
        if (control_arg(av[i + 1], cas, &i) == 84)
            return (my_puterror("Wrong Argument.\n"));
    }
    return (0);
}
