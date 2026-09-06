/*
** EPITECH PROJECT, 2019
** Boggle
** File description:
** Check for flags
*/

#include "my_lib.h"
#include "my_struct.h"
#include <stdlib.h>

int apply_g_flag(char **av, int i, variable_t *var)
{
    int size;

    i++;
    size = my_strlen(av[i]);
    var->flag_g = 1;
    if (size != (var->flag_s * var->flag_s)) {
        if (var->flag_s != 4)
            return (my_puterror("Invalid size\n"));
        else
            return (my_puterror(
                "16 characters required for the -g argument\n"));
    }
    var->arg_g = malloc(sizeof(char) * size + 1);
    var->arg_g = my_strcpy(var->arg_g, av[i]);
    return (0);
}

int apply_s_flag(char **av, int i, variable_t *var)
{
    int size;

    i++;
    size = my_getnbr(av[i]);
    if (size <= 0)
        return (my_puterror("The size must be > 0\n"));
    var->flag_s = size;
    return (0);
}

int apply_w_flag(char **av, int i, variable_t *var)
{
    int size;

    i++;
    size = my_strlen(av[i]);
    var->arg_w = malloc(sizeof(char) * size + 1);
    var->arg_w = my_strcpy(var->arg_w, av[i]);
    var->flag_w = 1;
    return (0);
}

int check_for_flags(int ac, char **av, variable_t *var)
{
    for (int i = 1; i != ac; i++)
        if (my_strcmp(av[i], "-s") == 0)
            apply_s_flag(av, i, var);
    for (int i = 1; i != ac; i++)
        if (my_strcmp(av[i], "-g") == 0)
            apply_g_flag(av, i, var);
    for (int i = 1; i != ac; i++)
        if (my_strcmp(av[i], "-w") == 0)
            apply_w_flag(av, i, var);
    if (var->flag_g == 0)
        return (my_puterror("You must use the -g flag\n"));
    return (0);
}
