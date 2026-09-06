/*
** EPITECH PROJECT, 2019
** is_my_ls
** File description:
** is_extension_is_my_ls
*/

#include "is_my_ls.h"

void sort_alphabetically(flag_t *flag)
{
    int limit = flag->arg->nbr_element;
    char *save = NULL;

    for (int i = 0; i < limit; i++)
        for (int i_two = 1; i_two < limit; i_two++)
            if (my_strcmp(flag->arg->result[i_two - 1],
                flag->arg->result[i]) > 0) {
                save = flag->arg->result[i_two - 1];
                flag->arg->result[i_two - 1] = flag->arg->result[i];
                flag->arg->result[i] = save;
            }
}

void sort_alphabetically_rev(flag_t *flag)
{
    int limit = flag->arg->nbr_element;
    char *save = NULL;

    for (int i = 0; i < limit; i++)
        for (int i_two = 1; i_two < limit; i_two++)
            if (my_strcmp(flag->arg->result[i_two - 1],
                flag->arg->result[i]) < 0) {
                save = flag->arg->result[i_two - 1];
                flag->arg->result[i_two - 1] = flag->arg->result[i];
                flag->arg->result[i] = save;
            }
}

void is_extension_analyze(flag_t *flag)
{
    if (flag->flag_t == 1 && flag->flag_r == 0)
        sort_time(flag);
    if (flag->flag_r == 1 && flag->flag_t == 1)
        sort_time_rev(flag);
    if (flag->flag_r == 1 && flag->flag_t == 0)
        sort_alphabetically_rev(flag);
    if (flag->flag_r == 0 && flag->flag_t == 0)
        sort_alphabetically(flag);
}

int analyze(flag_t *flag, int *i, int first)
{
    int return_value = 1;
    int nbr = 0;

    if ((return_value = first_analyze(flag, &nbr, i)) == 84)
        return (84);
    flag->arg->nbr_element = nbr;
    if (create_result(flag, first) == 84)
        return (84);
    if ((return_value = directory_and_file(flag, i)) == 84)
        return (84);
    if (return_value != 1) {
        is_extension_analyze(flag);
        display_result(flag, first, i);
    }
    return (0);
}