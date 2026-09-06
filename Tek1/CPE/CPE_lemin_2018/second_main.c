/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "lem_in.h"

int main_bis(int ac, char *av[])
{
    variable_t *var = malloc(sizeof(*var));

    if ((ac != 1 && av) || (check_error(var) != 0))
        return (84);
    if (analyze_data_arg(var) == 84) {
        display_parse(var, 0);
        return (84);
    }
    if (display_parse(var, 1) == 84)
        return (84);
    return (algo(var));
}
