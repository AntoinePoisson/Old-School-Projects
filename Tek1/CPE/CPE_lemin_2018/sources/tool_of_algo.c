/*
** EPITECH PROJECT, 2019
** tool_of_algo.c
** File description:
** tool_of_algo
*/

#include "lem_in.h"

int get_index(variable_t *var, node_t *room)
{
    int i = 0;

    if (room == NULL)
        return (-1);
    for (; my_strcmp(var->room[i]->name, room->name) != 0; i++);
    return (i);
}

int check_end_algo(variable_t *var, path_t *posi)
{
    int useless_variable = 0;

    if (posi == NULL)
        return (0);
    if (posi->index == var->end_index &&
        check_move_forward(var, posi, &useless_variable) == 0) {
        return (0);
    }
    return (1);
}

int check_complete_path(variable_t *var, path_t *posi, int *cas)
{
    if (posi && posi->index == var->start_index) {
        *cas = 1;
        return (1);
    }
    return (0);
}

path_t *complete_path(variable_t *var, path_t *posi)
{
    if ((var->tab_path = convert_list(var->tab_path, posi)) == NULL)
        return (NULL);
    var->limit_path = count_element_path(posi);
    return (move_back(var, posi));
}

int comparation_recurrence(int **tab, path_t *save, int i, int new_index)
{
    int count = 0;
    int compare = 0;

    for (count = 0; tab[i][count] != -1; count++) {
        compare += 1;
    }
    if (compare != 0) {
        count--;
        for (; count >= 0 && save; count--, save = save->next) {
            if (save->index != tab[i][count]) {
                return (0);
            }
        }
    }
    if (count >= 0 && tab[i][count] == new_index) {
        return (1);
    }
    return (0);
}