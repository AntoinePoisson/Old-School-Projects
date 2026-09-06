/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <unistd.h>
#include "my_struct.h"
#include "my_lib.h"

void display(var_t *var)
{
    for (int i = 0; i < var->nbr_line + 2; i++) {
        write(1, var->game_board[i], my_strlen(var->game_board[i]));
        write(1, "\n", 1);
    }
}
