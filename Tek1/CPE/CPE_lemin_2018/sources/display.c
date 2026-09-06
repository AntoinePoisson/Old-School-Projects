/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** allow display result or message
*/

#include "parsing.h"

static int display_tunnel(variable_t *var)
{
    int i = 0;

    for (int i_two = 0; var->data_arg && var->data_arg[i_two] && !i; i_two++)
        if (is_link_room(var->data_arg[i_two]) == 0)
            i++;
    if (i == 0)
        return (1);
    write(1, "#tunnels\n", 9);
    for (int i = 0; var->data_arg && var->data_arg[i]; i++)
        if (count_word(var->data_arg[i]) == 1 &&
            is_link_room(var->data_arg[i]) == 0) {
            for (int i_two = 0; var->data_arg[i][i_two] &&
                var->data_arg[i][i_two] != ' '; i_two++)
                write(1, &var->data_arg[i][i_two], 1);
            write(1, "\n", 1);
        }
    return (0);
}

static int display_nbr_anthill(variable_t *var)
{
    if (var->nbr_ants > 0) {
        write(1, "#number_of_ants\n", 16);
        my_putnbr(var->nbr_ants);
        write(1, "\n", 1);
        return (1);
    }
    return (0);
}

static void advanced_room_display(variable_t *var, int i, int *count)
{
    if (var->room[i] && var->start)
        if (my_strcmp(var->room[i]->name, var->start->name) == 0) {
            write(1, "##start\n", 8);
            my_printf("%s %d %d\n", var->room[i]->name,
                var->room[i]->posi_x, var->room[i]->posi_y);
            *count += 1;
            return;
        }
    if (var->room[i] && var->end)
        if (my_strcmp(var->room[i]->name, var->end->name) == 0) {
            my_printf("##end\n%s %d %d\n", var->room[i]->name,
                var->room[i]->posi_x, var->room[i]->posi_y);
            *count += 1;
            return;
        }
    if (var->room[i] != NULL)
            my_printf("%s %d %d\n", var->room[i]->name,
                var->room[i]->posi_x, var->room[i]->posi_y);
}

static int display_room(variable_t *var)
{
    int count = 0;

    if (var->room == NULL || var->room[0] == NULL)
        return (1);
    write(1, "#rooms\n", 7);
    for (int i = 0; var->room && var->room[i]; i++) {
        advanced_room_display(var, i, &count);
    }
    if (count != 2)
        return (1);
    return (0);
}

int display_parse(variable_t *var, int cas)
{
    if (display_nbr_anthill(var) == 0)
        return (84);
    if (display_room(var) == 1)
        return (84);
    if (display_tunnel(var) == 1)
        return (84);
    if (cas == 1 && failure_parsing(var) != 84) {
        write(1, "#moves\n", 7);
        return (0);
    }
    return (84);
}
