/*
** EPITECH PROJECT, 2019
** algo
** File description:
** algo
*/

#include "lem_in.h"

int find_all_path(variable_t *var)
{
    path_t *posi = NULL;

    if ((posi = add_element_path(posi, var->end_index)) == NULL)
        return (84);
    for (int cas = -1; posi && check_end_algo(var, posi); cas = -1) {
        if (cas == -1 && check_complete_path(var, posi, &cas))
            posi = complete_path(var, posi);
        if (cas == -1 && check_move_forward(var, posi, &cas))
            posi = move_forward(posi, cas);
        if (cas == -1)
            posi = move_back(var, posi);
    }
    if (posi == NULL)
        return (84);
    return (0);
}

int initialization_algo(variable_t *var)
{
    var->start_index = get_index(var, var->start);
    var->end_index = get_index(var, var->end);
    var->tab_path = NULL;
    var->bad_path = NULL;
    var->limit_path = -1;
    if ((var->tab_path = malloc(sizeof(int *) * 1)) == NULL)
        return (1);
    if ((var->tab_path[0] = malloc(sizeof(int) * 1)) == NULL)
        return (1);
    var->tab_path[0][0] = -1;
    if ((var->bad_path = malloc(sizeof(int *) * 1)) == NULL)
        return (1);
    if ((var->bad_path[0] = malloc(sizeof(int) * 1)) == NULL)
        return (1);
    var->bad_path[0][0] = -1;
    return (0);
}

int algo(variable_t *var)
{
    if (initialization_algo(var) == 1)
        return (84);
    if (find_all_path(var) == 84)
        return (84);
    var->tab_path = sort_array(var->tab_path);
    move_ants(var->nbr_ants, var->tab_path, var);
    return (0);
}
