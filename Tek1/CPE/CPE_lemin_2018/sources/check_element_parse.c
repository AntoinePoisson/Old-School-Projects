/*
** EPITECH PROJECT, 2019
** check_element_parse.c
** File description:
** check element output
*/

#include "parsing.h"

static int second_part_of_link(variable_t *var, char *str, int i, int i_two)
{
    char *second_part = &str[i + 1];

    for (i += 1, i_two = i; str[i]; i++);
    for (i -= i_two, i_two = 0; var->room[i_two]; i_two++)
        if (my_strncmp(var->room[i_two]->name, second_part, i) == 0)
            break;
    if (var->room[i_two] == NULL) {
        my_puterror("warning: link same node '");
        my_puterror(second_part);
        for (int a = 0; var->data_arg[a]; a++) {
            if (my_strcmp(var->data_arg[a], str) == 0) {
                var->data_arg[a] = NULL;
                break;
            }
        }
        return (my_puterror("'.\n"));
    }
    return (0);
}

static int is_extension_right_link_room(variable_t *var, char *str, int i)
{
    my_puterror("warning: node '");
    for (int a = 0; a <= i - 1 && str[a]; a++)
        write(2, &str[a], 1);
    for (int a = 0; var->data_arg[a]; a++) {
        if (my_strcmp(var->data_arg[a], str) == 0) {
            var->data_arg[a] = NULL;
            break;
        }
    }
    return (my_puterror("' does not exist.\n"));
}

int is_right_link_room(variable_t *var, char *str)
{
    int i = 0;
    int i_two = 0;

    for (; str && str[i] != '-' && str[i]; i++);
    if (my_strncmp(str, &str[i + 1], i) == 0) {
        my_puterror("warning: link same node '");
        my_puterror(str);
        return (my_puterror("'.\n"));
    }
    for (i_two = 0; var->room[i_two]; i_two++) {
        if (my_strncmp(var->room[i_two]->name, str, i - 1) == 0 &&
            var->room[i_two]->name[i] == '\0')
            break;
    }
    if (var->room[i_two] == NULL)
        return (is_extension_right_link_room(var, str, i));
    if (second_part_of_link(var, str, i, i_two) == 84)
        return (84);
    return (create_link(var, str));
}

int is_command(variable_t *var, char const *str, int *i)
{
    static int start = 0;
    static int end = 1;

    if (str[0] == '#' && str[1] != '#')
        return (0);
    if (my_strncmp(str, "##start", 7) == 0) {
        if (start >= 1) {
            my_puterror("error: multi defined starting node.\n");
            return (1);
        }
        return (management_special_room(var, str, i, &start));
    }
    if (my_strncmp(str, "##end", 5) == 0) {
        if (end >= 2) {
            my_puterror("error: multi defined ending node.\n");
            return (1);
        }
        return (management_special_room(var, str, i, &end));
    }
    return (0);
}

int select_element_parsing(variable_t *var, char *str, int *i)
{
    int nbr_work = count_word(str);

    if (str == NULL || str[0] == '\0')
        return (1);
    if (nbr_work == 0 && str[0] == '#')
        return (is_command(var, str, i));
    if (nbr_work == 1 && is_link_room(str) == 0)
        return (is_right_link_room(var, str));
    if (nbr_work == 3 && is_room(str) == 0)
        return (add_node(var, str));
    return (1);
}
