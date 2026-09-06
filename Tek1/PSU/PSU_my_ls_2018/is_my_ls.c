/*
** EPITECH PROJECT, 2019
** is_my_ls
** File description:
** my_ls
*/

#include "is_my_ls.h"

int normal_ls(flag_t *flag)
{
    int value_return = 0;
    static int i = 0;

    i = 0;
    for (int first = 1; i < flag->arg->nbr_direction; first = 0, i++)
        if ((value_return = analyze(flag, &i, first)) == 84)
            return (value_return);
    return (value_return);
}

int is_my_ls(flag_t *flag)
{
    if (flag->flag_big_r == 1) {
        if (normal_ls_big_r(flag) != 0)
            return (84);
    }
    else if (normal_ls(flag) != 0)
        return (84);
    return (0);
}
