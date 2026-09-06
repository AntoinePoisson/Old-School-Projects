/*
** EPITECH PROJECT, 2019
** is_my_ls
** File description:
** is_extension_is_my_ls
*/

#include "is_my_ls.h"

void display_flag_l(flag_t *flag)
{
    int limit = flag->arg->nbr_element;

    my_stat(flag->arg->result[0], 2, flag);
    for (int i_two = 0; i_two < limit; i_two++)
        my_stat(flag->arg->result[i_two], 3, flag);
    for (int i_two = 0; i_two < limit; i_two++) {
        if (flag->arg->result[i_two][0] != '.') {
            my_stat(flag->arg->result[i_two], -2, flag);
            write(1, "\n", 1);
        }
    }
    my_stat(flag->arg->result[0], 5, flag);
}

void display_flag_d(flag_t *flag, int *i)
{
    if (flag->flag_l == 1)
        my_stat(flag->arg->direction[*i], -2, flag);
    else
        my_putstr(flag->arg->direction[*i]);
    write(1, "\n", 1);
}

int display_file(flag_t *flag, int *i)
{
    if (flag->flag_l == 1)
        my_stat(flag->arg->direction[*i], -2, flag);
    else
        my_putstr(flag->arg->direction[*i]);
    write(1, "\n", 1);
    return (1);
}

int display_error_message(flag_t *flag)
{
    write(2, "ls: cannot access '", 19);
    write(2, flag->arg->direction[flag->arg->index]
        , my_strlen(flag->arg->direction[flag->arg->index]));
    write(2, "': No such file or directory\n", 30);
    return (84);
}

int create_result(flag_t *flag, int first)
{
    if (first != 1)
        free(flag->arg->result);
    flag->arg->result = malloc(sizeof(char *) * flag->arg->nbr_element);
    if (flag->arg->result == NULL)
        return (84);
    return (0);
}