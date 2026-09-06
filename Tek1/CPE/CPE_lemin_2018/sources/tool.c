/*
** EPITECH PROJECT, 2019
** tool.c
** File description:
** tool of parsing
*/

#include "parsing.h"

int find_begin(char const *str)
{
    int i = 0;

    for (; str && str[i] == ' '; i++) {
    }
    return (i);
}

int count_word(char const *str)
{
    int count = 0;

    if (str == NULL || str[0] == '\0')
        return (0);
    for (int i = find_begin(str); str[i] != '\0' && str[i] != '#'; i++)
        if ((str[i] == ' ' && str[i + 1] != ' ') || str[i + 1] == '\0')
            count++;
    return (count);
}

int nbr_ants(char const *str)
{
    int i = find_begin(str);

    for (; str[i] && str[i] != ' '; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (84);
    if (my_getnbr(str) <= 0)
        return (84);
    return (0);
}

int is_link_room(char const *str)
{
    int i = 0;
    int count = 0;

    for (; str[i]; i++)
        if (str[i] == '-') {
            count++;
            break;
        }
    if (count != 1 || i == 0 ||
        str[i + 1] == '\0')
        return (84);
    return (0);
}

int management_special_room(variable_t *var, char const *str, int *posi,
    int *cas)
{
    int i = 0;
    char *new_str = NULL;

    *cas += 1;
    *posi += 1;
    new_str = &var->data_arg[*posi][find_begin(str)];
    if (!new_str || count_word(new_str) != 3 || is_room(new_str) != 0)
        return (1);
    if (add_node(var, new_str) != 0)
        return (84);
    for (; var->room[i]; i++);
    if (*cas == 1 && i != 0)
        var->start = var->room[i - 1];
    if (*cas == 2 && i != 0)
        var->end = var->room[i - 1];
    return (0);
}
