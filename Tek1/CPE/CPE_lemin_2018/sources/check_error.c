/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error
*/

#include "parsing.h"

static int display_check_same_data(node_t *element, int nbr)
{
    if (nbr == 1) {
        my_puterror("error: node duplicate '");
        my_puterror(element->name);
        my_puterror("'.\n");
    } else {
        my_puterror("error: same position '");
        my_puterror(element->name);
        my_puterror("'.\n");
    }
    return (84);
}

int check_same_data(variable_t *var, node_t *element)
{
    int i_two = 0;

    if (element->name == NULL) {
        my_puterror("error: failure malloc.\n");
        return (1);
    }
    for (; var->room[i_two]; i_two++);
    for (int i = 0; i < (i_two - 1); i++) {
        if (my_strcmp(var->room[i]->name, element->name) == 0) {
            var->room[i_two - 1] = NULL;
            return (display_check_same_data(element, 1));
        }
        if (var->room[i]->posi_x == element->posi_x &&
            var->room[i]->posi_y == element->posi_y) {
            var->room[i_two - 1] = NULL;
            return (display_check_same_data(element, 0));
        }
    }
    return (0);
}

char *select_begin(char *str)
{
    int delete = find_begin(str);
    int size = my_strlen(str) - delete;
    char *new_str = NULL;

    if (str == NULL || size <= 0 || delete == 0)
        return (str);
    if ((new_str = my_malloc(size + 1)) == NULL)
        return (str);
    size = 0;
    for (int i = delete; str && str[i]; i++, size++)
        new_str[size] = str[i];
    new_str[size] = '\0';
    return (new_str);
}

static int is_initialization_struct(variable_t *var)
{
    var->data_arg = NULL;
    var->start = NULL;
    var->end = NULL;
    var->room = NULL;
    var->path = NULL;
    var->tab_path = NULL;
    var->bad_path = NULL;
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

int check_error(variable_t *var)
{
    if (var == NULL)
        return (84);
    if (is_initialization_struct(var) == 1)
        return (84);
    var->nbr_ants = 0;
    var->start_index = 0;
    var->end_index = 0;
    var->limit_path = -1;
    return (0);
}
