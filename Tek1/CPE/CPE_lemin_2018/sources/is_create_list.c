/*
** EPITECH PROJECT, 2019
** is_create_list.c
** File description:
** create element of list
*/

#include "parsing.h"

int create_link(variable_t *var, char const *str)
{
    char *first_element = my_strdup(str);
    char *second_element = NULL;
    int i = 0;
    int i_two = 0;

    for (; str && str[i] != '-' && str[i]; i++);
    second_element = my_strdup(&str[i + 1]);
    first_element[i] = '\0';
    for (i = 0; my_strcmp(var->room[i]->name, first_element); i++);
    for (i_two = 0;
        my_strcmp(var->room[i_two]->name, second_element); i_two++);
    if (var->room[i] != NULL)
        var->room[i]->next[i_two] = var->room[i_two];
    if (var->room[i_two] != NULL)
        var->room[i_two]->next[i] = var->room[i];
    return (0);
}

node_t **create_tab_node_element(variable_t *var)
{
    node_t **tab_node = malloc(sizeof(node_t *) * var->nbr_room);

    for (int i = 0; i < var->nbr_room; i++) {
        tab_node[i] = NULL;
    }
    return (tab_node);
}

int add_node(variable_t *var, char const *str)
{
    node_t *element = malloc(sizeof(node_t));
    char *name = NULL;
    int i = 0;
    int count = 0;
    static int posi = 0;

    for (; str[i] != ' '; i++, count++);
    name = my_malloc(count + 1);
    for (i = 0, count = 0; name && str[i] != ' ' && str[i]; i++, count++)
        name[count] = str[i];
    element->name = name;
    for (; str[i] && str[i] != ' '; i++);
    element->posi_x = my_getnbr(&str[i]);
    for (i = i + find_begin(&str[i]); str[i] != ' ' && str[i]; i++);
    element->posi_y = my_getnbr(&str[i]);
    element->next = create_tab_node_element(var);
    element->ants = 0;
    var->room[posi++] = element;
    return (check_same_data(var, element));
}

int is_room(char const *str)
{
    int i = 0;
    int c = 0;

    if (str == NULL)
        return (84);
    for (; str[i] && str[i] != ' '; i++);
    if (str[i] != ' ')
        return (84);
    for (c = 0, i += find_begin(&str[i]); str[i] && str[i] != ' '; i++, c++)
        if (!(str[i] >= '0' && str[i] <= '9') && (str[i] == '-' && c != 0))
            return (84);
    if (str[i] != ' ')
        return (84);
    i += find_begin(&str[i]);
    for (c = 0; str[i] && str[i] != ' '; i++, c++)
        if (!(str[i] >= '0' && str[i] <= '9') && (str[i] == '-' && c != 0))
            return (84);
    return (0);
}
