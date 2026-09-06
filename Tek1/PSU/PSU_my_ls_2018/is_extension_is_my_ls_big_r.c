/*
** EPITECH PROJECT, 2019
** is_ls_R
** File description:
** my_ls_R
*/

#include "is_ls_big_r.h"

void display_flag_l_big_r(flag_t *flag)
{
    int limit = flag->arg->nbr_element;
    char *link = NULL;

    my_stat(flag->arg->result[0], 6, flag);
    for (int i_two = 0; i_two < limit; i_two++)
        my_stat(flag->arg->result[i_two], 3, flag);
    for (int i_two = 0; i_two < limit; i_two++) {
        if (flag->arg->result[i_two][0] != '.') {
            link = link_directory(flag->arg->result[i_two], 5, flag);
            my_stat(link, -24, flag);
            write(1, "\n", 1);
        }
    }
    my_stat(flag->arg->result[0], 5, flag);
}

void display_flag_d_big_r(flag_t *flag)
{
    if (flag->flag_l == 1)
        my_stat(flag->r->data, -2, flag);
    else
        my_putstr(flag->r->data);
    write(1, "\n", 1);
}

int display_file_big_r(flag_t *flag)
{
    if (flag->flag_l == 1)
        my_stat(flag->r->data, -2, flag);
    else
        my_putstr(flag->r->data);
    write(1, "\n", 1);
    return (1);
}

int display_error_message_big_r(flag_t *flag)
{
    write(2, "ls: cannot access '", 19);
    write(2, flag->r->data, my_strlen(flag->r->data));
    write(2, "': No such file or directory\n", 30);
    return (84);
}

int create_result_big_r(flag_t *flag, int first)
{
    if (first != 1)
        free(flag->arg->result);
    flag->arg->result = malloc(sizeof(char *) * flag->arg->nbr_element);
    if (flag->arg->result == NULL)
        return (84);
    return (0);
}