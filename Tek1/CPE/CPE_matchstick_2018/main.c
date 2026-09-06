/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "my_lib.h"
#include "my_struct.h"

int check_error(int ac, char *av[]);
int is_initialization(char *av[], var_t *var);
void display(var_t *var);
int remove_stick(var_t *var, int line, int nbr);
int is_matchstick(var_t *var);

int main(int ac, char *av[])
{
    var_t *var = malloc(sizeof(*var));
    int value_return = 0;

    if (check_error(ac, av) == 84 || var == NULL) {
        write(2, "Invalid Argument.\n", 18);
        return (84);
    }
    if (is_initialization(av, var) == 84) {
        write(2, "Cannot initialization game board.\n", 34);
        return (84);
    }
    value_return = is_matchstick(var);
    if (value_return == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    else if(value_return == 2)
        my_putstr("You lost, too bad...\n");
    else
        my_putstr("\n");
    free(var);
    return (value_return);
}
