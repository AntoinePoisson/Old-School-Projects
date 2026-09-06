/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/


#include "my_struct.h"

int check_error(int ac, char *av[]);
variable_t *is_initialization(void);
int check_for_flags(int ac, char **av, variable_t *var);
int create_two_d_tab(variable_t *var);
int game_loop(variable_t *);

int main(int ac, char *av[])
{
    variable_t *var = is_initialization();

    if (!var || check_error(ac, av) != 0)
        return (84);
    if (check_for_flags(ac, av, var) == 84)
        return (84);
    if (create_two_d_tab(var) == 84)
        return (84);
    return (game_loop(var));
}
