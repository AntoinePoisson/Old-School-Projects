/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <unistd.h>
#include <stddef.h>
#include "my_string.h"

int check_error(int ac, char *av[]);
int menu(int flag);
int display_h(void);

int main(int ac, char *av[], char **env)
{
    if (env[0] == NULL)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (display_h());
    if (check_error(ac, av) != 0)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "--hitbox") == 0)
        return (menu(1));
    return (menu(0));
}
