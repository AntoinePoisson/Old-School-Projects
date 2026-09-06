/*
** EPITECH PROJECT, 2019
** check_end_start_link.c
** File description:
** check if start and end are link
*/

#include "lem_in.h"

int check_end_start_link(variable_t *var)
{
    path_t *posi = NULL;

    initialization_algo(var);
    if ((posi = add_element_path(posi, var->end_index)) == NULL)
        return (84);
    for (int cas = -1; posi && check_end_algo(var, posi); cas = -1) {
        if (cas == -1 && check_complete_path(var, posi, &cas))
            return (0);
        if (cas == -1 && check_move_forward(var, posi, &cas))
            posi = move_forward(posi, cas);
        if (cas == -1)
            posi = move_back(var, posi);
    }
    if (posi == NULL)
        return (84);
    return (84);
}