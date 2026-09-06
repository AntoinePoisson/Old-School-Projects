/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_lib.h"
#include "my_struct.h"

int check_error(var_t *var, char *env[]);
int is_minishell(var_t *var);
int my_exit(var_t *var, char *arg_nbr);

int main(int ac, char *av[], char *env[])
{
    var_t *var = malloc(sizeof(*var));
    int value_return = 0;

    if (ac || av) {
    }
    if (check_error(var, env) != 0)
        return (84);
    value_return = is_minishell(var);
    if (value_return == -1)
        return (0);
    else
        my_exit(var, "0");
    return (value_return);
}
