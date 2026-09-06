/*
** EPITECH PROJECT, 2019
** is_initialization.c
** File description:
** is_initialization
*/


#include <unistd.h>
#include "my_struct.h"
#include "my_lib.h"

int check_end(var_t *var);
int take_information(var_t *var);
void display(var_t *var);
void is_rand_ai(var_t *var);
void is_turn_ai(var_t *var);

int is_extension_matchstick(var_t *var)
{
    int value = 1;

    my_putstr("Your turn:\n");
    while ((value = take_information(var)) > 0);
    if (value == -1)
        return (1);
    var->turn = 0;
    return (0);
}

int is_matchstick(var_t *var)
{
    while (check_end(var)) {
        display(var);
        write(1, "\n", 1);
        if (var->turn == 1) {
            if (is_extension_matchstick(var) == 1)
                return (0);
        } else {
            my_putstr("AI's turn...\n");
            is_turn_ai(var);
            var->turn = 1;
        }
    }
    display(var);
    if (var->turn == 1)
        return (1);
    else
        return (2);
}
