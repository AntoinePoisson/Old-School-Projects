/*
** EPITECH PROJECT, 2019
** tool_two.c
** File description:
** tool_two.c
*/

#include <stddef.h>
#include "get_next_line.h"
#include "my_lib.h"
#include "my_struct.h"

void is_extension_control_nbr_remove_stick(var_t *var, int nbr)
{
    if (nbr < 1)
        my_putstr("Error: you have to remove at least one match\n");
    else {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(var->nbr_remove);
        my_putstr(" matches per turn\n");
    }
}

int control_nbr_remove_stick(var_t *var, char *data, int cas)
{
    int nbr = 0;

    for (int i = 0; data[i] != '\0'; i++)
        if (!(data[i] >= '0' && data[i] <= '9')) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        }
    nbr = my_getnbr(data);
    if (cas == 0)
        if (!(0 < nbr && nbr <= var->nbr_line)) {
            my_putstr("Error: this line is out of range\n");
            return (1);
        }
    if (cas == 1)
        if (nbr > var->nbr_remove || nbr < 1) {
            is_extension_control_nbr_remove_stick(var, nbr);
            return (1);
        }
    return (0);
}

int check_end(var_t *var)
{
    int nbr_obstacle = 0;

    for (int i = 1; i <= var->nbr_line; i++)
        for (int i_two = 0; i_two < var->size + 2; i_two++)
            if (var->game_board[i][i_two] == '|')
                nbr_obstacle++;
    return (nbr_obstacle);
}

int remove_stick(var_t *var, int line, int nbr)
{
    int nbr_remove = 0;

    for (int i = var->size + 2; i >= 0 && nbr_remove != nbr; i--)
        if (var->game_board[line][i] == '|')
            nbr_remove++;
    if (nbr_remove != nbr) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    nbr_remove = 0;
    for (int i = var->size + 2; i >= 0 && nbr_remove != nbr; i--)
        if (var->game_board[line][i] == '|') {
            var->game_board[line][i] = ' ';
            nbr_remove++;
        }
    return (0);
}

int check_righ_chose_line(var_t *var, int line)
{
    for (int i = var->size + 2; i > 0; i--)
        if (var->game_board[line][i] == '|')
            return (1);
    my_putstr("Error: this line is out of range\n");
    return (0);
}