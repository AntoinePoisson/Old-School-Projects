/*
** EPITECH PROJECT, 2019
** tool_of_algo_two.c
** File description:
** tool_of_algo_two
*/

#include "lem_in.h"

int research_recurrence(int **tab, path_t *posi, int new_index)
{
    path_t *save = NULL;

    for (int i = 0; tab[i][0] != -1; i++) {
        save = posi;
        if (comparation_recurrence(tab, save, i, new_index) == 1)
            return (1);
    }
    save = posi;
    for (int i = 0; save; i++, save = save->next)
        if (save->index == new_index)
            return (1);
    return (0);
}

int check_move_forward(variable_t *var, path_t *posi, int *cas)
{
    path_t *save = reverse_list(posi);

    if ((posi == NULL) || (save == NULL) ||
        (var->limit_path != -1 &&
        count_element_path(posi) + 1 > var->limit_path))
        return (0);
    for (int i = 0; i < var->nbr_room && posi; i++) {
        if (var->room[posi->index]->next[i] &&
            i != posi->index &&
            research_recurrence(var->tab_path, save, i) == 0 &&
            research_recurrence(var->bad_path, save, i) == 0) {
            *cas = i;
            return (1);
        }
    }
    return (0);
}

path_t *move_forward(path_t *posi, int new_posi)
{
    return (add_element_path(posi, new_posi));
}

path_t *move_back(variable_t *var, path_t *posi)
{
    if ((var->bad_path = convert_list(var->bad_path, posi)) == NULL)
        return (NULL);
    return (delete_element_path(posi));
}