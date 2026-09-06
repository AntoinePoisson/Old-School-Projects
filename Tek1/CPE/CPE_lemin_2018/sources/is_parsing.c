/*
** EPITECH PROJECT, 2019
** is_parsing.c
** File description:
** parce element
*/

#include "parsing.h"

static void is_extension_pre_analyze(int find_nbr_ant,
    int *posi_define_nbr_ant)
{
    if (find_nbr_ant == 0)
        my_puterror("error: undefined number anthill.\n");
    else
        my_puterror("error: multi defined number anthill.\n");
    *posi_define_nbr_ant = -1;
}

int pre_analyze(variable_t *var, int *posi_define_nbr_ant)
{
    int nbr_room = 1;
    int find_nbr_ant = 0;

    if ((var->data_arg = create_data(var)) == NULL)
        return (-1);
    for (int i = 0; var->data_arg[i]; i++) {
        if (count_word(var->data_arg[i]) == 3 &&
            is_room(var->data_arg[i]) == 0)
            nbr_room++;
        if (count_word(var->data_arg[i]) == 1 &&
            nbr_ants(var->data_arg[i]) == 0) {
            find_nbr_ant += 1;
            *posi_define_nbr_ant = i;
        }
    }
    if (find_nbr_ant == 0 || find_nbr_ant > 1)
        is_extension_pre_analyze(find_nbr_ant, posi_define_nbr_ant);
    return (nbr_room);
}

int management_parsing(variable_t *var, int posi_define_nbr_ant,
    node_t **tab_node)
{
    int return_value = 0;

    var->room = tab_node;
    for (int i = 0; var->data_arg[i]; i++, return_value = 0) {
        if (i != posi_define_nbr_ant) {
            return_value = select_element_parsing(var,
                &var->data_arg[i][find_begin(var->data_arg[i])], &i);
        }
        if (i == posi_define_nbr_ant)
            var->nbr_ants = my_getnbr(var->data_arg[i]);
        if (return_value == 1)
            return (is_extension_management_parsing(var, return_value, 1, i));
        if (return_value == 84)
            return (is_extension_management_parsing(var, return_value, 0, i));
    }
    return (0);
}

int final_check(variable_t *var)
{
    if (var->start == NULL) {
        my_puterror("error: undefined starting node.\n");
        return (84);
    }
    if (var->end == NULL) {
        my_puterror("error: undefined ending node.\n");
        return (84);
    }
    for (int i = 0; var->room[i]; i++)
        for (int i_two = 0; i_two < var->nbr_room; i_two++) {
            if (var->room[i]->next[i_two] != NULL)
                break;
            if (var->room[i]->next[i_two + 1] == NULL &&
                i_two + 1 == var->nbr_room) {
                my_puterror("warning: useless node '");
                my_puterror(var->room[i]->name);
                my_puterror("'.\n");
            }
        }
    return (0);
}

int analyze_data_arg(variable_t *var)
{
    int posi_define_ant = -1;
    int nbr_room = pre_analyze(var, &posi_define_ant);
    node_t **tab_node = malloc(sizeof(node_t *) * nbr_room);

    if (posi_define_ant == -1 || tab_node == NULL)
        return (84);
    for (int i = 0; i < nbr_room; i++) {
        tab_node[i] = NULL;
    }
    var->nbr_room = nbr_room;
    var->room = tab_node;
    if (management_parsing(var, posi_define_ant, tab_node) == 84)
        return (84);
    for (posi_define_ant = 0; var->room[posi_define_ant]; posi_define_ant++) {
    }
    var->nbr_room = posi_define_ant;
    if (final_check(var) == 84)
        return (84);
    return (0);
}
