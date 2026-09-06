/*
** EPITECH PROJECT, 2019
** is_basic_ai
** File description:
** is_basic_ai
*/

#include <my_struct.h>
#include "my_lib.h"

int remove_stick(var_t *var, int line, int nbr);

void is_basic_ai(var_t *var)
{
    for (int i = 1; i <= var->nbr_line; i++)
        for (int i_two = var->size + 2; i_two >= 0; i_two--)
            if (var->game_board[i][i_two] == '|') {
                my_putstr("AI removed ");
                my_put_nbr(1);
                my_putstr(" match(es) from line ");
                my_put_nbr(i);
                my_putstr("\n");
                remove_stick(var, i, 1);
                return;
            }
}
