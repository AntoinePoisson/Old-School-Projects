/*
** EPITECH PROJECT, 2018
** main
** File description:
** main of my_hunter
*/

#include "main.h"

int main(int ac, char **av, char **env)
{
    int return_main = 0;

    if (env[0] == NULL)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        option_h();
    else
        return_main = main_second();
    if (return_main == 0)
        return (0);
    else
        return (ERROR);
    return (0);
}
