/*
** EPITECH PROJECT, 2019
** is_ls_R
** File description:
** my_ls_R
*/

#include "is_ls_big_r.h"

int is_ls_big_r(flag_t *flag, int *i, int first)
{
    int return_value = 1;
    int nbr = 0;

    if ((return_value = first_analyze_big_r(flag, &nbr, i)) == 84)
        return (84);
    flag->arg->nbr_element = nbr;
    if (create_result_big_r(flag, first) == 84)
        return (84);
    if ((return_value = directory_and_file_big_r(flag, i)) == 84)
        return (84);
    if (return_value != 1) {
        is_extension_is_ls_big_big_r(flag);
        display_result_big_r(flag);
    }
    check_big_r_elemen_two(flag);
    return (0);
}

int normal_ls_big_r(flag_t *flag)
{
    int value_return = 0;
    int i = 0;
    recursive_t *save = malloc(sizeof(*save));

    flag->r = save;
    flag->r->next = NULL;
    for (int first = 1; i < flag->arg->nbr_direction || flag->nbr_recursive
        > 0; first = 0, i++) {
        if ((value_return = analyze(flag, &i, first)) == 84)
            return (value_return);
        if (flag->flag_d == 0)
            check_big_r_element(flag);
        first = 0;
        while (flag->nbr_recursive > 0) {
            if ((value_return = is_ls_big_r(flag, &i, first)) == 84)
                return (value_return);
            pop(flag);
        }
    }
    return (value_return);
}
